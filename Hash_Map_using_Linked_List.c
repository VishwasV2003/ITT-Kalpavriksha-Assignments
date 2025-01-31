#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node* next;
    int key;
    int value;
}Node;

Node* make_node(int key,int value){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->key=key;
    new_node->value=value;
    new_node->next=NULL;
    return new_node;
}
Node* add(Node* head,int key,int value){
    if(head==NULL)
        head=make_node(key,value);
    else{
        Node* temp=head;
        int updated=0;
        while(temp->next){
            if(temp->key==key){
                temp->value=value;
                updated=1;
                break;
            }
            temp=temp->next;
        }
        if(!updated)
            temp->next=make_node(key,value);
    }
    return head;
}
int find_key(Node* head,int key){
    int value=-1;
    while(head){
        if(head->key==key){
            value=head->value;
            break;
        }
        head=head->next;
    }
    return value;
}
int remove_key_list(Node** head,int key){
    int deleted=0;
    Node* temp=(*head);
    if((*head)){
        if(temp->key==key){
            (*head)=(*head)->next;
            deleted=1;
        }
        else{
            Node* prev=temp;
            temp=temp->next;
            while(temp){
                if(temp->key==key){
                    prev->next=temp->next;
                    deleted=1;
                    free(temp);
                    break;
                }
                prev=temp;
                temp=temp->next;
            }
        }
    }
    return deleted;
}
void display_list(Node* head){
    while(head){
        if(head->next)
            printf("(%d , %d)->",head->key,head->value);
        else
            printf("(%d , %d)",head->key,head->value);
        head=head->next;
    }
    printf("\n");
}


void put(Node** hash,int key,int value){
    int index=key%10;
    hash[index]=add(hash[index],key,value);
}
int get(Node** hash,int key){
    int index=key%10;
    return find_key(hash[index],key);
}
int remove_key(Node** hash,int key){
    int index=key%10;
    return remove_key_list(&hash[index],key);
}
void display(Node** hash){
    printf("Hash Table:\n");
    for(int index=0;index<10;index++){
        if(hash[index]!=NULL){
            printf("Index %d:",index);
            display_list(hash[index]);
        }
    }
}

void main(){
    Node* hash[10]={NULL};

    printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");

    int exit=0;
    while(!exit){
        printf("Enter your choice:");
        int choice=0;
        scanf("%d",&choice);
        int key,value,deleted;
        switch(choice){
            case 1:
                printf("Enter key:");
                scanf("%d",&key);
                printf("Enter value:");
                scanf("%d",&value);
                put(hash,key,value);
                break;
            case 2:
                printf("Enter key:");
                scanf("%d",&key);
                value=get(hash,key);
                if(value>=0)
                    printf("Value:%d\n",value);
                else
                    printf("Key not present\n");
                break;
            case 3:
                printf("Enter key:");
                scanf("%d",&key);
                deleted=remove_key(hash,key);
                if(deleted)
                    printf("Key %d deleted\n",key);
                else
                    printf("Key not present\n");
                break;
            case 4:
                display(hash);
                break;
            case 5:
                exit=1;
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

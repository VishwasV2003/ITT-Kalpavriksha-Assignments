#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* next;
    int data;
};

struct Node* make_node(int new_data){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node*));
    new_node->data=new_data;
    new_node->next=NULL;
    return new_node;
}

void add_in_beginning(struct Node** head,int new_data){
    struct Node* curr_head=*head;
    if(curr_head==NULL){
        curr_head=make_node(new_data);
    }
    else{
        struct Node* temp=make_node(new_data);
        temp->next=curr_head;
        curr_head=temp;
    }
    *head=curr_head;
    // return head;
}
void add_in_end(struct Node** head,int new_data){
    struct Node* curr_head=*head;
    if(curr_head==NULL){
        curr_head=make_node(new_data);
    }
    else{
        struct Node* temp=curr_head; 
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=make_node(new_data);
    }
    *head=curr_head;
    // return head;
    
}
void add_at_position(struct Node** head,int new_data,int operation_index){
    struct Node* curr_head=*head;
    if(operation_index==1){
        add_in_beginning(&curr_head,new_data);
    }
    else{
        struct Node* temp=curr_head;
        while(temp!=NULL && temp->next!=NULL && operation_index-1!=1){
            temp=temp->next;
            operation_index--;
        }
        if(operation_index-1==1 && temp!=NULL){
            struct Node* new_node=make_node(new_data);
            new_node->next=temp->next;
            temp->next=new_node;
        }
        else{
            printf("Invalid index\n");
        }
    }
    *head=curr_head;
    // return head;
}
void print_list(struct Node* head){
    printf("\nLinked List:");
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void update_at_position(struct Node* head,int new_data,int position){
    struct Node* temp=head;
    while(temp!=NULL && temp->next!=NULL && position!=1){
        temp=temp->next;
        position--;
    }
    if(temp!=NULL && position==1){
        temp->data=new_data;
    }
    else{
        printf("Invalid Index\n");
    }
}
void delete_first_element(struct Node** head){
    struct Node* curr_head=*head;
    if(curr_head!=NULL){
        struct Node* temp=curr_head->next;
        free(head);
        curr_head=temp;
    }
    else{
        printf("No elements to delete\n");
    }
    *head=curr_head;
    // return head;
}
void delete_last_element(struct Node** head){
    struct Node* curr_head=*head;

    struct Node* temp=curr_head;
    struct Node* prev=curr_head;
    if(curr_head!=NULL){
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        if(prev->next!=NULL){
            prev->next=NULL;
            free(temp);
        }
        else{
            curr_head=NULL;
        }
    }
    else{
        printf("No elements to delete\n");
    }
    *head=curr_head;
    // return head;
}
void delete_element_at_position(struct Node** head,int operation_index){
    struct Node* curr_head=*head;
    if(operation_index==1){
        delete_first_element(&curr_head);
    }
    else{
        struct Node* temp=curr_head;
        struct Node* prev=NULL;
        while(temp!=NULL && temp->next!=NULL && operation_index-1!=0){
            prev=temp;
            temp=temp->next;
            operation_index--;
        }
        if(operation_index-1==0 && temp!=NULL){
            prev->next=temp->next;
            free(temp);
        }
        else{
            printf("Invalid Index\n");
        }
    }
    *head=curr_head;
    // return head;
}
int main(){
    struct Node* head=NULL;
    int number_of_operations=0;
    printf("Number of operations:");
    scanf("%d",&number_of_operations);
    
    while(number_of_operations){
        printf("1 x: Add x to the end (x: is any number and pos: position)\n2 x: Add x at the beginning\n3 pos x: Add x at position pos (1-indexed)\n4: Display all elements\n5 pos x: Update the element at position pos to x\n6: Delete the first element\n7: Delete the last element\n8 pos: Delete the element at position pos (1-indexed)\n");
        int operation=0;
        scanf("%d",&operation);
                
        int new_data=0,operation_index=0;
        switch(operation){
            case 1:
                printf("Enter Value:");
                scanf("%d",&new_data);
                add_in_end(&head,new_data);
                break;
            case 2:
                printf("Enter Value:");
                scanf("%d",&new_data);
                add_in_beginning(&head,new_data);
                break;
            case 3:
                printf("Enter Value and index:");
                scanf("%d%d",&new_data,&operation_index);
                add_at_position(&head,new_data,operation_index);
                break;
            case 4:
                print_list(head);
                break;
            case 5:
                printf("Enter Value and index:");
                scanf("%d%d",&new_data,&operation_index);
                update_at_position(head,new_data,operation_index);
                break;
            case 6:
                delete_first_element(&head);
                break;
            case 7:
                delete_last_element(&head);
                break;
            case 8:
                printf("Enter index:");
                scanf("%d",&operation_index);
                delete_element_at_position(&head,operation_index);
                break;
            default:
                printf("Invalid Input\n");
                break;

        }
        number_of_operations--;
    }
    return 0;
}
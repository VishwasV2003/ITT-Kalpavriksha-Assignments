#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    struct Node* next;
    int data;
}Node;

Node* make_node(int num){
    Node* new_node=(Node*)malloc(sizeof(Node*));
    new_node->data=num;
    new_node->next=NULL;
    return new_node; 
}
Node* add(Node* head,int num){
    if(head==NULL)
        head=make_node(num);
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=make_node(num);
    }
    return head;
}

void print(Node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

Node* reverse(Node* head,int group_size){
    if(head){
        Node* prev=NULL;
        Node* temp=head;
        Node* next=head->next;
        
        Node* nextHead=head;
        for(int index=0;index<group_size-1 && next!=NULL;index++){
            temp->next=prev;
            prev=temp;
            temp=next;
            next=next->next;
        }
        temp->next=prev;

        head=temp;

        nextHead->next=next;

        if(next){
            for(int index=0;index<group_size && next!=NULL;index++){
                prev=next;
                next=next->next;
            }

            if(prev)
                prev->next=reverse(prev->next,group_size);
        }

    }

    

    return head;

}
void main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';

    Node* head=NULL;
    int group_size;
    scanf("%d",&group_size);
    int is_negative=0;
    int num=0;

    for(int index=0;index<=strlen(input);index++){
        if(input[index]==' ' || input[index]=='\0'){
            if(is_negative)
                num*=-1;
            head=add(head,num);
            num=0;
            is_negative=0;
        }
        else if(input[index]=='-'){
            is_negative=1;
        }
        else if(input[index]>='0' && input[index]<='9'){
            num*=10;
            num+=input[index]-'0';
        }
    }
    head=reverse(head,group_size);
    print(head);
}
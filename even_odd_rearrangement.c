#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    int data;
}Node;

Node* make_node(int data){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

Node* get_linked_list(char* input){
    Node* head=NULL;
    Node* temp=head;
    int num=0;
    int is_negative=0;
    for(int index=0;index<=strlen(input);index++){
        if(input[index]==' ' || input[index]=='\0'){
            if(is_negative)
                    num*=-1;
            if(head==NULL){
                head=make_node(num);
                temp=head;
            }
            else{
                temp->next=make_node(num);
                temp=temp->next;
            }
            num=0;
            is_negative=0;
        }
        if(input[index]=='-'){
            is_negative=1;
        }
        else if(input[index]>='0' && input[index]<='9'){
            num*=10;
            num+=input[index]-'0';
        }
    }
    return head;
} 

Node* insert_node(Node* head,Node* new_node){
    if(head==NULL){
        head=new_node;
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        } 
        temp->next=new_node;
    }
    return head;
}
Node* rearrange_list_even_odd(Node* head){
    Node* even_list=NULL;
    Node* odd_list=NULL;
    Node* temp=NULL;

    while(head){
        if(head->data%2==0){
            even_list=insert_node(even_list,head);
        }
        else{
            odd_list=insert_node(odd_list,head);
        }
        temp=head;
        head=head->next;
        temp->next=NULL;
    }

    if(even_list){
        head=even_list;
        while(even_list->next)
            even_list=even_list->next;
        even_list->next=odd_list;
    }
    else{
        head=odd_list;
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
void main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';
    
    Node* head=get_linked_list(input);

    printf("Before rearrangement:");
    print(head);
    head=rearrange_list_even_odd(head);
    printf("\nAfter rearrangement:");
    print(head);
}
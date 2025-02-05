#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    int data;
}Node;

Node* make_node(int value){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}
Node* insert(Node* head,int value){
    if(head==NULL){
        head=make_node(value);
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        } 
        temp->next=make_node(value);
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
Node* bubble_sort(Node* head){
    Node* temp_head_1=head;
    Node* temp_head_2=head;
    while(temp_head_1->next!=NULL){
        temp_head_2=head;
        while(temp_head_2->next!=NULL){
            if(temp_head_2->data>temp_head_2->next->data){
                int temp=temp_head_2->data;
                temp_head_2->data=temp_head_2->next->data;
                temp_head_2->next->data=temp;
            }
            temp_head_2=temp_head_2->next;
        }
        temp_head_1=temp_head_1->next;
    }
    return head;
}
void main(){
    Node* head=NULL;
    printf("Input space seperated values ended by 0:");
    while(1){
        int value;
        scanf("%d",&value);
        if(value==0)
            break;
        head=insert(head,value);
    }
    printf("Before sorting:");
    print(head);
    head=bubble_sort(head);
    printf("\nAfter sorting:");
    print(head);
}
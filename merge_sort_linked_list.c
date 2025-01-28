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
Node* get_mid(Node* head){
    Node* slow=head;
    Node* fast=head;
    Node* mid=slow;
    while(fast && fast->next){
        mid=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return mid;
}
Node* merge(Node* left,Node* right){
    Node* head=NULL;
    Node* temp=NULL;

    while(left && right){
        if(left->data < right->data){
            head=insert_node(head,left);
            temp=left;
            left=left->next;
            temp->next=NULL;
        }
        else{
            head=insert_node(head,right);
            temp=right;
            right=right->next;
            temp->next=NULL;
        }
    }
    while(left){
        head=insert_node(head,left);
        temp=left;
        left=left->next;
        temp->next=NULL;
    }
    while(right){
        head=insert_node(head,right);
        temp=right;
        right=right->next;
        temp->next=NULL;
    }

    return head;
}
Node* merge_sort(Node* head){
    if(head==NULL || head->next==NULL)
        return head;
    
    Node* mid=get_mid(head);
    Node* temp=mid->next;
    mid->next=NULL;

    Node* left=merge_sort(head);
    Node* right=merge_sort(temp);

    head=merge(left,right);
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
    head=merge_sort(head);
    printf("\nAfter sorting:");
    print(head);
}
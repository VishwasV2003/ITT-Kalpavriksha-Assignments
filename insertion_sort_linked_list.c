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
Node* insertion_sort(Node* head){
    Node* temp_head_1=head->next;
    Node* prev_head_1=head;
    Node* temp_head_2=head;

    while(temp_head_1){
        int key=temp_head_1->data;
        if(prev_head_1->data>key){
            prev_head_1->next=temp_head_1->next;
        }

        temp_head_2=head;

        if(temp_head_2->data>key){
            temp_head_1->next=head;
            head=temp_head_1;
            temp_head_1=prev_head_1->next;
            continue;
        }
        else{
            Node* prev_head_2=head;
            temp_head_2=prev_head_2->next;
            while(temp_head_2){
                if(temp_head_2->data>key){
                    temp_head_1->next=temp_head_2;
                    prev_head_2->next=temp_head_1;
                    temp_head_1=prev_head_1->next;
                    break;
                }
                prev_head_2=temp_head_2;
                temp_head_2=temp_head_2->next;
            }
            if(temp_head_2)
                continue;
        }
        prev_head_1=temp_head_1;
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
    head=insertion_sort(head);
    printf("\nAfter sorting:");
    print(head);
}
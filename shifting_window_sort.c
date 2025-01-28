/*
Problem statement:
You are given a linked list and need to perform two operations:
1. Find the index of the desired element (1 indexed).
2. Now for the resultant index, sort the index-sized window of the linked list by shifting it each time untill the last window.
3. Do nothing if the value is not present in the list.

example:
Linked List: 5->4->7->8->4->3->1->5->5->NULL
Search element: 7

Solution: window size=3 (7 is at 3 index)
iteration 1: 4 5 7 8 4 3 1 5 5 
iteration 2: 4 5 7 8 4 3 1 5 5
iteration 3: 4 5 4 7 8 3 1 5 5 
iteration 4: 4 5 4 3 7 8 1 5 5
iteration 5: 4 5 4 3 1 7 8 5 5
iteration 6: 4 5 4 3 1 5 7 8 5
iteration 7: 4 5 4 3 1 5 5 7 8
iteration 8: 4 5 4 3 1 5 5 7 8

Result:
4 5 4 3 1 5 5 7 8
*/

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

void print(Node* head){
    Node* temp=head;
    while(head!=NULL){
        printf("%d ",head->data);

        head=head->next;
    }
    printf("\n");
}

Node* get_mid(Node* list){
    Node* slow=list;
    Node* fast=list;
    Node* temp=list;

    while(fast && fast->next){
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return temp;
}
Node* merge(Node* left,Node* right){
    Node* result=NULL;
    while(left && right){
        if(left->data<right->data){
            result=insert_node(result,left);
            Node* temp=left;
            left=left->next;
            temp->next=NULL;
        }
        else{
            result=insert_node(result,right);
            Node* temp=right;
            right=right->next;
            temp->next=NULL;
        }
    }
    while(left){
        result=insert_node(result,left);
        Node* temp=left;
        left=left->next;
        temp->next=NULL;
    }
    while(right){
        result=insert_node(result,right);
        Node* temp=right;
        right=right->next;
        temp->next=NULL;
    }
    return result;
}

Node* merge_sort(Node* list){
    if(list==NULL || list->next==NULL)
        return list;

    Node* mid=get_mid(list);
    Node* temp=mid->next;
    mid->next=NULL;

    Node* left=merge_sort(list);
    Node* right=merge_sort(temp);

    list=merge(left,right);
    return list;

}
int serach(Node* head,int search_num){
    int index=0;
    while(head){
        if(head->data==search_num){
            break;
        }
        index++;
        head=head->next;
    }
    if(head==NULL)
        index=-1;

    return index;

}
Node* split(Node* head,int index){
    Node* temp=head;
    while(head && index){
        head=head->next;
        index--;
    }
    return head;
}

Node* shifting_window_sort(Node* head,int index){
    if(head==NULL)
        return NULL;
    if(index!=-1){
        Node* split_head=split(head,index);
        if(split_head==NULL)
            return head;
        Node* temp=split_head;
        split_head=split_head->next;
        temp->next=NULL;
        head=merge_sort(head);
        temp=head; 
        while(temp->next)
            temp=temp->next;
        temp->next=split_head;
    }
    print(head);
    head->next=shifting_window_sort(head->next,index);
    return head;
}

void main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';

    Node* head=get_linked_list(input);
    int search_element=0;
    scanf("%d",&search_element);
    int index=serach(head,search_element);
    head=shifting_window_sort(head,index);
    print(head);
    
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    struct Node* next;
    int id;
    char priority[50];
}Node;

Node* make_node(int id,char* priority){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->id=id;
    strcpy(new_node->priority,priority);
    new_node->next=NULL;
}
Node* add(Node* head,int id,char* priority){
    if(head==NULL)
        head=make_node(id,priority);
    else{
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=make_node(id,priority);
    }
    return head;
}
void print(Node* head){
    while(head){
        printf("%d %s\n",head->id,head->priority);
        head=head->next;
    }
}
Node* split(Node* head){
    Node* slow=head;
    Node* temp=head;
    Node* fast=head;
    while(fast && fast->next){
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    return temp;
}
Node* add_node(Node* head,Node* new_node){
    if(head==NULL)
        head=new_node;
    else{
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    return head;
}
int get_priority(char* priority){
    int result=0;
    if(strcmp(priority," Critical")==0)
        result=3;
    if(strcmp(priority," Serious")==0)
        result=2;
    if(strcmp(priority," Stable")==0)
        result=1;
    return result;
}
Node* merge(Node* left,Node* right){
    Node* result=NULL;
    while(left && right){
        if(get_priority(left->priority)>=get_priority(right->priority)){
            result=add_node(result,left);
            Node* temp=left;
            left=left->next;
            temp->next=NULL;
        }
        else{
            result=add_node(result,right);
            Node* temp=right;
            right=right->next;
            temp->next=NULL;
        }
    }
    while(left){
        result=add_node(result,left);
        Node* temp=left;
        left=left->next;
        temp->next=NULL;
    }
    while(right){
        result=add_node(result,right);
        Node* temp=right;
        right=right->next;
        temp->next=NULL;
    }

    return result;
}
Node* merge_sort(Node* head){
    if(head==NULL || head->next==NULL)
        return head;
    Node* mid=split(head);
    Node* temp=mid->next;
    mid->next=NULL;

    Node* left=merge_sort(head);
    Node* right=merge_sort(temp);
    return merge(left,right);
}
int is_patient_exists(Node* head,int id){
    int present=0;
    while(head){
        if(head->id==id){
            present=1;
            break;
        }
        head=head->next;
    }
    return present;
}
void main(){
    int number_of_patient=0;
    scanf("%d",&number_of_patient);

    Node* head=NULL;
    for(int index=0;index<number_of_patient;index++){
        int id=0;
        scanf("%d",&id);
        char priority[50];
        scanf("%[^\n]%*c",priority);
        if(get_priority(priority)==0){
            printf("Not a valid priority\n");
            scanf("%[^\n]%*c",priority);
        }
        if(is_patient_exists(head,id)){
            printf("Patient exists\n");
            index--;
            continue;
        }
        head=add(head,id,priority);
    }
    // print(head);
    printf("Result:\n");
    head=merge_sort(head);
    print(head);

}

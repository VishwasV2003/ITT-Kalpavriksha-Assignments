#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    struct Node* next;
    int data;
}Node;

int get_result(Node* head,int stream_index,int window_size){
    int result=0;

    for(int index=0;index<stream_index-window_size && head!=NULL;index++){
        head=head->next;
    }
    while(head!=NULL){
        result+=head->data;
        head=head->next;
    }
    return result;
}

Node* make_node(int num){
    Node* new=(Node*)malloc(sizeof(Node*));
    new->data=num;
    new->next=NULL;
    return new;
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
void main(){
    int number_of_operations;
    int window_size;
    scanf("%d%d",&number_of_operations,&window_size);
    getchar();
    int stream_index=0;
    Node* head=NULL;
    Node* result=NULL;
    int result_length=0;


    for(int index=0;index<number_of_operations;index++){
        char operation;
        scanf("%c",&operation);
        getchar();

        if(operation=='A'){
            int number;
            scanf("%d",&number);
            getchar();
            head=add(head,number);
            stream_index++;
        }
        else if(operation=='S'){
            result_length++;
            result=add(result,get_result(head,stream_index,window_size));
        }
        else{
            printf("Invalid");
            break;
        }

    }
    for(int index=0;index<result_length;index++){
        printf("%d\n",result->data);
        result=result->next;
    }
}
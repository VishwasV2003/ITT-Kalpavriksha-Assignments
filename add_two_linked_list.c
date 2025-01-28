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
Node* add_linked_list(Node* operand_1,Node* operand_2){
    Node* result=NULL;
    int carry=0;
    while(operand_1 && operand_2){
        int sum=operand_1->data+operand_2->data+carry;
        result=insert_node(result,make_node(sum%10));
        carry=sum/10;
        operand_1=operand_1->next;
        operand_2=operand_2->next;
    }
    while(operand_1){
        int sum=operand_1->data+carry;
        result=insert_node(result,make_node(sum%10));
        carry=sum/10;
        operand_1=operand_1->next;
    }
    while(operand_2){
        int sum=operand_2->data+carry;
        result=insert_node(result,make_node(sum%10));
        carry=sum/10;
        operand_2=operand_2->next;
    }
    if(carry>0)
        result=insert_node(result,make_node(carry));

    return result;
}
void print(Node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
void main(){
    char operand_1_string[100];
    fgets(operand_1_string,sizeof(char)*100,stdin);
    operand_1_string[strcspn(operand_1_string,"\n")]='\0';
    
    char operand_2_string[100];
    fgets(operand_2_string,sizeof(char)*100,stdin);
    operand_2_string[strcspn(operand_2_string,"\n")]='\0';

    Node* operand_1=get_linked_list(operand_1_string);
    Node* operand_2=get_linked_list(operand_2_string);
    
    Node* result=add_linked_list(operand_1,operand_2);
    print(result);
}
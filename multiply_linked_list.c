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
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
Node* add_in_result(Node* result,int add_value,int ignore_spaces){
    if(result==NULL)
        result=insert_node(result,make_node(add_value));
    else{
        Node* temp=result;
        int ignore_spaces_copy=ignore_spaces;
        while(temp && ignore_spaces){
            temp=temp->next;
            ignore_spaces--;
        }
        if(temp==NULL){
            result=insert_node(result,make_node(add_value));
        }
        else{
            int carry=(add_value+temp->data)/10;
            temp->data=(add_value+temp->data)%10;
            if(carry){
                result=add_in_result(result,carry,ignore_spaces_copy+1);
            }
        }
    }

    return result;
}
Node* multiply_linked_list(Node* operand_1,Node* operand_2){
    Node* result=NULL;
    Node* operand_1_copy=operand_1;
    int ignore_spaces=0;
    while(operand_2){
        int multiply_carry=0;
        int add_ignore=0;
        operand_1=operand_1_copy;
        while(operand_1){
            int multiply_result=(operand_1->data*operand_2->data+multiply_carry)%10;
            multiply_carry=(operand_1->data*operand_2->data+multiply_carry)/10;
            result=add_in_result(result,multiply_result,add_ignore+ignore_spaces);
            add_ignore++;
            operand_1=operand_1->next;
        }
        if(multiply_carry)
            result=add_in_result(result,multiply_carry,add_ignore+ignore_spaces);
        ignore_spaces++;
        operand_2=operand_2->next;
    }

    return result;
}
void main(){
    char *operand_1_string=(char*)calloc(100,sizeof(char));
    fgets(operand_1_string,sizeof(char)*100,stdin);
    operand_1_string[strcspn(operand_1_string,"\n")]='\0';
    int operand_1_negative=0;
    if(operand_1_string[0]=='-'){
        operand_1_negative=1;
        operand_1_string++;
    }
    
    char *operand_2_string=(char*)calloc(100,sizeof(char));
    int operand_2_negative=0;
    fgets(operand_2_string,sizeof(char)*100,stdin);
    operand_2_string[strcspn(operand_2_string,"\n")]='\0';
    if(operand_2_string[0]=='-'){
        operand_2_negative=1;
        operand_2_string++;
    }

    Node* operand_1=get_linked_list(operand_1_string);
    Node* operand_2=get_linked_list(operand_2_string);

    Node* result=multiply_linked_list(operand_1,operand_2);
    print(result);
}
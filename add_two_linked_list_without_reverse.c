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
        new_node->next=head;
        head=new_node;
    }
    return head;
}
int get_size(Node* head){
    int size=0;
    while(head){
        size++;
        head=head->next;
    }
    return size;
}

int add_equal_lists(Node** result,Node* operand_1,Node* operand_2){
    int carry=0;
    if(operand_1->next && operand_2->next){
        carry=add_equal_lists(result,operand_1->next,operand_2->next);
    }
    // printf("%d %d\n",operand_1->data,operand_2->data);
    int sum=operand_1->data+operand_2->data+carry;
    *result=insert_node(*result,make_node(sum%10));
    carry=sum/10;

    return carry;
}

int add_linked_list(Node** result,Node* operand_1,Node* operand_2,int size_difference){
    int carry=0;
    if(size_difference==0)
        carry=add_equal_lists(result,operand_1,operand_2);
    else if(size_difference>0){
        carry=add_linked_list(result,operand_1->next,operand_2,size_difference-1);
        int sum=carry+operand_1->data;
        carry=sum/10;
        *result=insert_node(*result,make_node(sum%10));
    }
    else{
        carry=add_linked_list(result,operand_1,operand_2->next,size_difference+1);
        int sum=carry+operand_2->data;
        carry=sum/10;
        *result=insert_node(*result,make_node(sum%10));
    }

    return carry;
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
    
    Node* result=NULL;
    
    int size_1=get_size(operand_1);
    int size_2=get_size(operand_2);
    int carry=add_linked_list(&result,operand_1,operand_2,size_1-size_2);
    if(carry)
        result=insert_node(result,make_node(carry));
    print(result);
}
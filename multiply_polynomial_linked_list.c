#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    int coffiecient;
    int exponent;
}Node;

Node* make_node(int coffiecient,int exponent){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->coffiecient=coffiecient;
    new_node->exponent=exponent;
    new_node->next=NULL;
    return new_node;
}

Node* get_linked_list(char* input){
    Node* head=NULL;
    Node* temp=head;
    int coffiecient=0;
    int exponent=0;
    int is_negative=0;
    int is_negative_exponent=0;
    int take_coffiecient=1;
    for(int index=0;index<=strlen(input);index++){
        if(take_coffiecient){
            if(input[index]==' '){
                take_coffiecient=0;
            }
            else if(input[index]=='-'){
                is_negative=1;
            }
            else if(input[index]>='0' && input[index]<='9'){
                coffiecient*=10;
                coffiecient+=input[index]-'0';
            }
        }
        else{

            if(input[index]==' ' || input[index]=='\0'){
                if(is_negative)
                    coffiecient*=-1;
                if(is_negative_exponent)
                    exponent*=-1;
                if(head==NULL){
                    head=make_node(coffiecient,exponent);
                    temp=head;
                }
                else{
                    temp->next=make_node(coffiecient,exponent);
                    temp=temp->next;
                }
                coffiecient=0;
                exponent=0;
                is_negative=0;
                is_negative_exponent=0;
                take_coffiecient=1;
            }
            else if(input[index]=='-'){
                is_negative_exponent=1;
            }
            else if(input[index]>='0' && input[index]<='9'){
                exponent*=10;
                exponent+=input[index]-'0';
            }
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
        int modified=0;
        while(temp->next!=NULL){
            if(temp->exponent==new_node->exponent){
                temp->coffiecient=temp->coffiecient+new_node->coffiecient;
                modified=1;
                break;
            }
            temp=temp->next;
        } 
        if(!modified && temp->exponent==new_node->exponent){
            temp->coffiecient=temp->coffiecient+new_node->coffiecient;
            modified=1;
        }
        if(!modified)
            temp->next=new_node;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(head!=NULL){
        if(head->coffiecient>0 && head!=temp)
            printf("+");
        if(head->exponent!=0)
            printf("%dx^%d",head->coffiecient,head->exponent);
        else
            printf("%d",head->coffiecient);

        head=head->next;
    }
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
        if(left->exponent>right->exponent){
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

Node* multiply_polynomial_linked_list(Node* operand_1,Node* operand_2){
    Node* result=NULL;
    
            // result=insert_node(result,make_node(coffiecient,operand_1->exponent));
    
    while(operand_2){
        Node* temp=operand_1;
        while(temp){
            int coffiecient=temp->coffiecient*operand_2->coffiecient;
            int exponent=temp->exponent+operand_2->exponent;

            result=insert_node(result,make_node(coffiecient,exponent));
            temp=temp->next;
        }
        operand_2=operand_2->next;
    }
    
    return result;
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

    operand_1=merge_sort(operand_1);
    operand_2=merge_sort(operand_2);
    printf("\n");
    print(operand_1);
    printf("\n");
    print(operand_2);

    printf("\n\n");
    Node* result=multiply_polynomial_linked_list(operand_1,operand_2);
    result=merge_sort(result);
    print(result);
}
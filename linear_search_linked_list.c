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
void main(){
    char input[100];
    fgets(input,sizeof(char)*100,stdin);
    input[strcspn(input,"\n")]='\0';
    
    Node* head=get_linked_list(input);

    int search_num=0;
    scanf("%d",&search_num);
    int index=serach(head,search_num);

    if(index!=-1){
        printf("%d is present at %d node",search_num,index+1);
    }
    else
        printf("%d is not present",search_num);
}
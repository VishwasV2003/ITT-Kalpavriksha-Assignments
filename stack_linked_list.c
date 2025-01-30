#include<stdio.h> 
#include<stdlib.h> 
typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* make_node(int value){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->value=value;
    new_node->next=NULL;
    return new_node;
}
void push(Node** stack,int value){
    if((*stack)==NULL)
        (*stack)=make_node(value);
    else{
        Node* temp=make_node(value);
        temp->next=(*stack);
        (*stack)=temp;
    }
}
void pop(Node** stack){
    if((*stack)){
        printf("Popped value:%d\n",(*stack)->value);
        Node* temp=(*stack);
        (*stack)=(*stack)->next;
        free(temp);
    }
    else
        printf("Empty Stack\n");
}
void peek(Node** stack){
    if((*stack))
        printf("Peeked value:%d\n",(*stack)->value);
    else
        printf("Empty Stack\n");
}
int is_empty(Node** stack){
    int empty=0;
    if((*stack)==NULL)
        empty=1;
    return empty;
}
int size(Node** stack){
    int size=0;
    Node* temp=(*stack);
    while(temp){
        size++;
        temp=temp->next;
    }
    return size;
}

void print(Node* stack){
    printf("Stack:");
    Node* temp=(stack);
    while(temp){
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n");
}

void main(){
    Node* stack=NULL;

    printf("Operations:\n");
    printf("1: Push\n");
    printf("2: Pop\n");
    printf("3: Peek\n");
    printf("4: Is empty\n");
    printf("5: Size\n");
    printf("6: Print stack\n");
    printf("7: Exit\n");

    int exit=0;
    while(!exit){
        int operation=0;
        scanf("%d",&operation);
        switch(operation){
            case 1:printf("Enter element:");
                int value;
                scanf("%d",&value);
                push(&stack,value);
                break;
            case 2:pop(&stack);
                break;
            case 3:peek(&stack);
                break;
            case 4:
                if(is_empty(&stack))
                    printf("true\n");
                else 
                    printf("false\n");
                break;
            case 5:printf("Size:%d\n",size(&stack));
                break;
            case 6:print(stack);
                break;
            case 7:exit=1;
                break;
            default:printf("Invalid");
                break; 

        }
        
    }

}

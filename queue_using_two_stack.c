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
int pop(Node** stack){
    int value=-1;
    if((*stack)){
        value=(*stack)->value;
        Node* temp=(*stack);
        (*stack)=(*stack)->next;
        free(temp);
    }
    return value;
}
int peek(Node** stack){
    int value=-1;
    if((*stack))
        value=(*stack)->value;
    return value;
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
void deque(Node** stack_1,Node** stack_2){
    int index=size(stack_1)-1;
    if(index>=0){
        while(index--)
            push(stack_2,pop(stack_1));
        pop(stack_1);
        index=size(stack_2);
        while(index--)
            push(stack_1,pop(stack_2));
    }
    else
        printf("Empty stack\n");
}
void peek_queue(Node** stack_1,Node** stack_2){
    int index=size(stack_1)-1;
    if(index>=0){
        while(index--)
            push(stack_2,pop(stack_1));
        printf("Peeked element:%d\n",peek(stack_1));
        push(stack_2,pop(stack_1));
        index=size(stack_2);
        while(index--)
            push(stack_1,pop(stack_2));
    }
    else
        printf("Empty stack\n");
}
void main(){
    Node* stack_1=NULL;
    Node* stack_2=NULL;

    printf("Operations:\n");
    printf("1: Enque\n");
    printf("2: Deque\n");
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
                push(&stack_1,value);
                break;
            case 2:deque(&stack_1,&stack_2);
                break;
            case 3:peek_queue(&stack_1,&stack_2);
                break;
            case 4:
                if(is_empty(&stack_1))
                    printf("true\n");
                else 
                    printf("false\n");
                break;
            case 5:printf("Size:%d\n",size(&stack_1));
                break;
            case 6:print(stack_1);
                break;
            case 7:exit=1;
                break;
            default:printf("Invalid");
                break; 

        }
        
    }

}

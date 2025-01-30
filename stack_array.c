#include<stdio.h> 
#include<stdlib.h> 
typedef struct Stack{
    int values[100];
    int top;
}Stack;

void push(Stack** stack,int value){
    if((*stack)->top+1==100){
        printf("Stack Overflow");
    }
    else{
        int top=++((*stack)->top);
        (*stack)->values[top]=value;
    }
}
void pop(Stack** stack){
    if((*stack)->top>=0)
        printf("Popped value:%d\n",(*stack)->values[(*stack)->top--]);
    else
        printf("Empty Stack\n");
}
void peek(Stack** stack){
    if((*stack)->top>=0)
        printf("Peeked value:%d\n",(*stack)->values[(*stack)->top]);
    else
        printf("Empty Stack\n");
}
int is_empty(Stack** stack){
    int empty=0;
    if((*stack)->top==-1)
        empty=1;
    return empty;
}
int size(Stack** stack){
    return (*stack)->top+1;
}

void print(Stack** stack){
    printf("Stack:");
    for(int index=(*stack)->top;index>=0;index--){
        printf("%d ",(*stack)->values[index]);
    }
    printf("\n");
}

void main(){
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;

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
            case 6:print(&stack);
                break;
            case 7:exit=1;
                break;
            default:printf("Invalid");
                break; 

        }
        
    }

}

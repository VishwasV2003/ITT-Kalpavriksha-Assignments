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
void enque(Node** queue,int value){
    if((*queue)==NULL)
        (*queue)=make_node(value);
    else{
        Node* temp=(*queue);
        while(temp->next)
            temp=temp->next;
        temp->next=make_node(value);
    }
}
int deque(Node** queue){
    int value=-1;
    if((*queue)){
        value=(*queue)->value;
        Node* temp=(*queue);
        (*queue)=(*queue)->next;
        free(temp);
    }
    return value;
}
int peek(Node** queue){
    int value=-1;
    if((*queue))
        value=(*queue)->value;
    return value;
}
int is_empty(Node** queue){
    int empty=0;
    if((*queue)==NULL)
        empty=1;
    return empty;
}
int size(Node** queue){
    int size=0;
    Node* temp=(*queue);
    while(temp){
        size++;
        temp=temp->next;
    }
    return size;
}

void print(Node* queue_1,Node* queue_2){
    printf("Queue as stack:");
    Node* temp=(queue_1);
    while(temp){
        printf("%d ",temp->value);
        temp=temp->next;
    }
    temp=(queue_2);
    while(temp){
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n");
}

void push(Node** queue_1,Node** queue_2,int value){
    if(is_empty(queue_1) && is_empty(queue_2))
        enque(queue_1,value);
    else if(is_empty(queue_1))
        enque(queue_2,value);
    else
        enque(queue_1,value);
}

void pop(Node** queue_1,Node** queue_2){
    if(is_empty(queue_1) && is_empty(queue_2))
        printf("Empty Stack\n");
    else{
        if(is_empty(queue_2)){
            int index=size(queue_1)-1;
            while(index--){
                enque(queue_2,deque(queue_1));
            }
            deque(queue_1);
        }
        else{
            int index=size(queue_2)-1;
            while(index--){
                enque(queue_1,deque(queue_2));
            }
            deque(queue_2);
        }
    }
}
void peek_stack(Node** queue_1,Node** queue_2){
    if(is_empty(queue_1) && is_empty(queue_2))
        printf("Empty Stack\n");
    else{
        if(is_empty(queue_2)){
            int index=size(queue_1)-1;
            while(index--){
                enque(queue_2,deque(queue_1));
            }
            printf("Peeked element:%d\n",peek(queue_1));
            enque(queue_2,deque(queue_1));
        }
        else{
            int index=size(queue_2)-1;
            while(index--){
                enque(queue_1,deque(queue_2));
            }
            printf("Peeked element:%d\n",peek(queue_2));
            enque(queue_1,deque(queue_2));
        }
    }
}
int size_stack(Node** queue_1,Node** queue_2){
    int size=0;
    Node* temp=(*queue_1);
    while(temp){
        size++;
        temp=temp->next;
    }
    temp=(*queue_2);
    while(temp){
        size++;
        temp=temp->next;
    }
    return size;
}
int is_empty_stack(Node** queue_1,Node** queue_2){
    int empty=0;
    if((*queue_1)==NULL)
        empty=1;
    if((*queue_2)==NULL)
        empty=1;
    return empty;
}
void main(){
    Node* queue_1=NULL;
    Node* queue_2=NULL;

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
                push(&queue_1,&queue_2,value);
                break;
            case 2:pop(&queue_1,&queue_2);
                break;
            case 3:peek_stack(&queue_1,&queue_2);
                break;
            case 4:
                if(is_empty_stack(&queue_1,&queue_2))
                    printf("true\n");
                else 
                    printf("false\n");
                break;
            case 5:printf("Size:%d\n",size_stack(&queue_1,&queue_2));
                break;
            case 6:print(queue_1,queue_2);
                break;
            case 7:exit=1;
                break;
            default:printf("Invalid");
                break; 

        }
        
    }

}

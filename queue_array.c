#include<stdio.h> 
#include<stdlib.h> 
typedef struct Queue{
    int values[100];
    int front;
    int rear;
}Queue;

void enque(Queue** queue,int value){
    if((*queue)->rear+1==100){
        printf("Queue Overflow\n");
    }
    else{
        if(((*queue)->rear)==-1)
            ++((*queue)->front);

        int rear=++((*queue)->rear);
        (*queue)->values[rear]=value;
    }
}
void deque(Queue** queue){
    if((*queue)->front>=0 && (*queue)->front<=(*queue)->rear){
        printf("dequeued value:%d\n",(*queue)->values[(*queue)->front++]);
        if((*queue)->front>(*queue)->rear){
            (*queue)->front=-1;
            (*queue)->rear=-1;
        }
    }
    else
        printf("Empty queue\n");
}
void peek(Queue** queue){
    if((*queue)->front>=0 && (*queue)->front<(*queue)->rear)
        printf("Peeked value:%d\n",(*queue)->values[(*queue)->front]);
    else
        printf("Empty queue\n");
}
int is_empty(Queue** queue){
    int empty=0;
    if((*queue)->front==-1)
        empty=1;
    return empty;
}
int size(Queue** queue){
    return (*queue)->rear-(*queue)->front+1;
}

void print(Queue** queue){
    printf("queue:");
    for(int index=(*queue)->front;index<=(*queue)->rear && (*queue)->rear!=-1;index++){
        printf("%d ",(*queue)->values[index]);
    }
    printf("\n");
}

void main(){
    Queue* queue=(Queue*)malloc(sizeof(Queue));
    queue->front=-1;
    queue->rear=-1;

    printf("Operations:\n");
    printf("1: Enque\n");
    printf("2: Deque\n");
    printf("3: Peek\n");
    printf("4: Is empty\n");
    printf("5: Size\n");
    printf("6: Print queue\n");
    printf("7: Exit\n");

    int exit=0;
    while(!exit){
        int operation=0;
        scanf("%d",&operation);
        switch(operation){
            case 1:printf("Enter element:");
                int value;
                scanf("%d",&value);
                enque(&queue,value);
                break;
            case 2:deque(&queue);
                break;
            case 3:peek(&queue);
                break;
            case 4:
                if(is_empty(&queue))
                    printf("true\n");
                else 
                    printf("false\n");
                break;
            case 5:printf("Size:%d\n",size(&queue));
                break;
            case 6:print(&queue);
                break;
            case 7:exit=1;
                break;
            default:printf("Invalid");
                break; 

        }
        
    }

}

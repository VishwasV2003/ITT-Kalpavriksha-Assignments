#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Queue{
    char array[100][100];
    int front;
    int rear;
}Queue;

void enqueue(Queue** queue,char* value){
    if((*queue)->front==-1){
        (*queue)->front++;
        (*queue)->rear++;
        strcpy((*queue)->array[(*queue)->rear],value);
    }
    else if((*queue)->rear+1<100){
        (*queue)->rear++;
        strcpy((*queue)->array[(*queue)->rear],value);
    }
    else{
        printf("Overflow\n");
    }
}

char* dequeue(Queue** queue){
    char* value=(char*)calloc(sizeof(char),100);
    if((*queue)->front!=-1){
        strcpy(value,(*queue)->array[(*queue)->front++]);
    }
    else{
        printf("Underflow\n");
    }
    return value;
}

void generate_binary(int number){
    Queue *queue=(Queue*)malloc(sizeof(Queue));
    queue->front=-1;
    queue->rear=-1;

    enqueue(&queue,"1");

    while(number--){
        char value_0[100];
        strcpy(value_0,dequeue(&queue));
        printf("%s\n",value_0);
        char value_1[100];
        strcpy(value_1,value_0);
        value_0[strlen(value_0)+1]='\0';
        value_0[strlen(value_0)]='0';
        
        value_1[strlen(value_1)+1]='\0';
        value_1[strlen(value_1)]='1';

        enqueue(&queue,value_0);
        enqueue(&queue,value_1);
    }
}

void main(){
    int number;
    scanf("%d",&number);

    generate_binary(number);
}
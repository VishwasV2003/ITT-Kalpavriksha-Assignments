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
void deque(Node** queue){
    if((*queue)){
        printf("Dequeued value:%d\n",(*queue)->value);
        Node* temp=(*queue);
        (*queue)=(*queue)->next;
        free(temp);
    }
    else
        printf("Empty queue\n");
}
void peek(Node** queue){
    if((*queue))
        printf("Peeked value:%d\n",(*queue)->value);
    else
        printf("Empty queue\n");
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

void print(Node* queue){
    printf("queue:");
    Node* temp=(queue);
    while(temp){
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n");
}

void main(){
    Node* queue=NULL;

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
            case 6:print(queue);
                break;
            case 7:exit=1;
                break;
            default:printf("Invalid");
                break; 

        }
        
    }

}

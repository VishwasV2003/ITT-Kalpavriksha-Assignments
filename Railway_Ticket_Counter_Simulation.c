#include<stdio.h>
#include<iostream>
#include<string.h>

enum category{
    VIP=1,SENIOR_CITIZEN,GENERAL
};

typedef struct Passenger{
    int id;
    enum category type;
    char name[50];
}Passenger;

int get_id(char* string){
    int id=0;
    for(int index=0;index<strlen(string);index++){
        id*=10;
        id+=string[index]-'0';
    }
    return id;
}

void enque(Passenger passenger_queue[],int* front,int* rear,int id,enum category type,char* name){
    if((*front)==-1){
        (*front)++;
        (*rear)++;
        passenger_queue[(*rear)].id=id;
        passenger_queue[(*rear)].type=type;
        strcpy(passenger_queue[(*rear)].name,name);
    }
    else if((*rear)>=100){
        printf("QUEUE OVERFLOW\n");
    }
    else{
        (*rear)++;
        int index=(*rear);
        while(index-1>=(*front) && passenger_queue[index-1].type>type){
            passenger_queue[index]=passenger_queue[index-1];
            index--;
        }
        passenger_queue[index].id=id;
        passenger_queue[index].type=type;
        strcpy(passenger_queue[index].name,name);
    }
}

void deque(Passenger passenger_queue[],int* front,int* rear){
    if((*front)==-1){
        printf("No passengers\n");
    }
    else{
        printf("Serving Passenger: ID %d, Name %s, Type: ",passenger_queue[(*front)].id,passenger_queue[(*front)].name);
        switch(passenger_queue[(*front)].type){
            case 1:printf("VIP\n");
            break;
            case 2:printf("SENIOR_CITIZEN\n");
            break;
            case 3:printf("GENERAL\n");
            break;
        }
        (*front)++;
    }
    if((*front)>(*rear)){
        (*front)=-1;
        (*rear)=-1;
    }
}

void display_queue(Passenger passenger_queue[],int front,int rear){
    printf("Waiting Passesngers:\n");
    for(int index=(front);index<=(rear);index++){
        printf("ID %d, Name %s, Type: ",passenger_queue[index].id,passenger_queue[index].name);
        switch(passenger_queue[index].type){
            case 1:printf("VIP\n");
            break;
            case 2:printf("SENIOR_CITIZEN\n");
            break;
            case 3:printf("GENERAL\n");
            break;
        }
    }
}

void main(){
    int number_of_operations;
    scanf("%d",&number_of_operations);
    getchar();
    Passenger passenger_queue[100];
    int front=-1;
    int rear=-1;

    while(number_of_operations--){
        char input[100];
        scanf("%[^\n]%*c",input);
        int type_of_operation=input[0]-'0';
        if(type_of_operation==1){
            char* token=strtok(input,",");
            token=strtok(NULL,",");
            int id=get_id(token);
            token=strtok(NULL,",");
            enum category type;
            if(strcmp(token,"VIP")==0)
                type=VIP;
            else if(strcmp(token,"SENIOR_CITIZEN")==0)
                type=SENIOR_CITIZEN;
            else if(strcmp(token,"GENERAL")==0)
                type=GENERAL;

            token=strtok(NULL,"\"");
            char name[50];
            strcpy(name,token);

            enque(passenger_queue,&front,&rear,id,type,name);
        }
        else if(type_of_operation==2){
            deque(passenger_queue,&front,&rear);
        }
        else if(type_of_operation==3){
            display_queue(passenger_queue,front,rear);
        }
        else
            printf("Invalid Input\n");
    }
}

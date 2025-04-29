#include<stdio.h>
#include<string.h>

void reverse(char* input){
    for(int index=0;index<strlen(input)/2;index++){
        char temp=input[index];
        input[index]=input[strlen(input)-index-1];
        input[strlen(input)-index-1]=temp;
    }
}

int is_operator(char c){
    return c=='+' || c=='-' || c=='*' || c=='/';
}

void postfix_to_infix(char* input,char* infix){
    char stack[20][10];
    int top=-1;

    for(int index=0;index<strlen(input);index++){
        if(!is_operator(input[index])){
            char operand[3];
            operand[0]=input[index];
            operand[1]='\0';
            
            strcpy(stack[++top],operand);
        }
        else{
            char operand_2[10];
            strcpy(operand_2,stack[top--]);
            char operand_1[10];
            strcpy(operand_1,stack[top--]);

            char operand[20];
            operand[0]=')';
            operand[1]='\0';
            strcat(operand,operand_1);
            operand[strlen(operand)+1]='\0';
            operand[strlen(operand)]=input[index];
            strcat(operand,operand_2);
            operand[strlen(operand)+1]='\0';
            operand[strlen(operand)]='(';

            strcpy(stack[++top],operand);
        }
    }
    
    strcpy(infix,stack[top]);
}

int main(){
    char input[50];
    scanf("%[^\n]%*c",input);
    reverse(input);

    char infix[strlen(input)+1];
    postfix_to_infix(input,infix);
    reverse(infix);
    printf("Result: %s",infix);

    return 0;
}
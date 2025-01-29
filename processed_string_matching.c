#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* process(char* string){
    int result_index=0;
    for(int index=0;index<strlen(string);index++){
        if(string[index]=='#' && result_index==0)
            continue;
        else if(string[index]=='#' && result_index>0){
            result_index--;
            continue;
        }
        string[result_index++]=string[index];
    }
    string[result_index]='\0';
    return string;
}
void main(){
    char* string_1=(char*)calloc(200,sizeof(char));;
    char* string_2=(char*)calloc(200,sizeof(char));;

    scanf("%[^\n]%*c",string_1);
    scanf("%[^\n]%*c",string_2);

    string_1=process(string_1);
    string_2=process(string_2);

    if(strcmp(string_1,string_2)==0){
        printf("true");
    }
    else
        printf("false");
}
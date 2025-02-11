/*
Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.
 
 
Example 1:
 
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:
 
Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:
 
Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
*/

#include<stdio.h>
#include<string.h>

int get_length(char* input){
    int size=0;
    for(int index=0;index<strlen(input);index++){
        if(input[index]==' ')
            size++;
    }
    return size;
}

int has_no_common(char* string_1,char* string_2){
    int occurance_1[26]={0};
    int occurance_2[26]={0};

    for(int index=0;index<strlen(string_1);index++){
        occurance_1[string_1[index]-'a']++;
    }
    for(int index=0;index<strlen(string_2);index++){
        occurance_2[string_2[index]-'a']++;
    }

    for(int index=0;index<26;index++){
        if(occurance_1[index]>0 && occurance_2[index]>0)
            return 0;
    }
    return 1;
}

int get_max_result(char array[][50],int number){
    int max_result=0;
    for(int iterate_1=0;iterate_1<number;iterate_1++){
        for(int iterate_2=iterate_1+1;iterate_2<number;iterate_2++){
            if(has_no_common(array[iterate_1],array[iterate_2])){
                if(max_result<strlen(array[iterate_1])*strlen(array[iterate_2]))
                    max_result=strlen(array[iterate_1])*strlen(array[iterate_2]);
            }
        }
    }
    return max_result;
}
void main(){
    char input[100];
    scanf("%[^\n]%*c",input);

    int number=get_length(input);
    if(number)
        number++;

    char array[number][50];
    char* token=strtok(input," ");
    int index=0;
    while(token){
        strcpy(array[index++],token);
        token=strtok(NULL," ");
    }
    printf("%d",get_max_result(array,number));

}

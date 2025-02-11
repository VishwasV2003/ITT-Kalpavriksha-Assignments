/*
Problem: First Non-Repeating Character in a Stream
Problem Statement
Given a stream of characters, process each character and find the first non-repeating character in the stream at every step. If there is no non-repeating character, return -1.
Input
A string S consisting of lowercase English letters.
Output
A string where each character represents the first non-repeating character at that moment.
Constraints
1 ≤ |S| ≤ 10^5 (Length of the stream is large, so optimize for O(N) time).
Example 1
Input:
plaintextCopyEditS = "aabc"
Explanation:
a → First non-repeating is "a".
aa → No non-repeating character, so "-1".
aab → First non-repeating is "b".
aabc → First non-repeating is "b".
✅ Output: "a-1bb"

*/
#include<stdio.h>
#include<string.h>

char get_non_repeating(char* input,int last_index){
    int occurance[26]={0};
    for(int index=0;index<=last_index;index++){
        occurance[input[index]-'a']++;
    }
    for(int index=0;index<=last_index;index++){
        if(occurance[input[index]-'a']==1){
            return input[index];
        }
    }
    return '!';
}

void main(){
    char input[50];
    fgets(input,50,stdin);
    input[strlen(input)-1]='\0';
    char result[strlen(input)];
    for(int index=0;index<strlen(input);index++){
        result[index]=get_non_repeating(input,index);
    }
    result[strlen(input)]='\0';
    if(input[0]!='\n' && input[0]!=' '){
        for(int index=0;index<strlen(input);index++){
            if(result[index]!='!')
                printf("%c",result[index]);
            else{
                printf("-1");
            }
        }
    }
    
}
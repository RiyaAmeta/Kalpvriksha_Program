#include<stdio.h>
#include<string.h>
#include<limits.h>

int getStringLength(char *sentence);
void shortestLongestWord(char *sentence, char *currentWord, char *smallestWord, char *longestWord);
int main(){
    char sentence[100];
    char currentWord[100] ="";
    char smallestWord[100] ="";
    char longestWord[100] = "";
    
    printf("Enter a sentence: \n");
    fgets(sentence, 100, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    
    shortestLongestWord(sentence, currentWord, smallestWord, longestWord);
    printf("The longest word is: %s\n",longestWord);
    printf("The smallest word is: %s", smallestWord);

}

int getStringLength(char *sentence){
    int length = 0;
    while(sentence[length] != '\0'){
        length++;
    }
    return length;
}

void shortestLongestWord(char *sentence, char *currentWord, char *smallestWord, char *longestWord){
    int len = getStringLength(sentence);
    int minLength =INT_MAX;
    int maxLength =INT_MIN;
    int cnt =0;
    for(int i =0; i<= len; i++){
        if (sentence[i] != ' ' && sentence[i] != '\0')
        {
            currentWord[cnt++] = sentence[i];
        }
        else
        {
            currentWord[cnt] = '\0';
            if(cnt >0){
                if(cnt < minLength){
                    minLength = cnt;
                    strcpy(smallestWord, currentWord);
                }
                if(cnt > maxLength){
                    maxLength = cnt;
                    strcpy(longestWord, currentWord);
                }
            }
            cnt =0;

        }        
    }
}

#include <stdio.h>

void getInput(char *sentence, char *oldWord, char *newWord);
int getStringLength(char *str);
void replaceWordInSentence(char *sentence, char *oldWord, char *newWord, char *result);
int main()
{
    char sentence[200], oldWord[50], newWord[50], result[200];
    getInput(sentence, oldWord, newWord);
    replaceWordInSentence(sentence, oldWord, newWord, result);
    printf("Updated sentence: %s\n", result);
    return 0;
}
void getInput(char *sentence, char *oldWord, char *newWord)
{
    printf("Enter a sentence: ");
    fgets(sentence, 200, stdin);  
    printf("Enter the word to replace: ");
    scanf("%s", oldWord);
    printf("Enter the replacement word: ");
    scanf("%s", newWord);
}
int getStringLength(char *str)
{
    int length = 0;
    while (str[length] != '\0'){
        length++;
    }
    return length;
}
void replaceWordInSentence(char *sentence, char *oldWord, char *newWord, char *result)
{
    int sentenceIndex = 0, resultIndex = 0, wordStartIndex = 0;
    int oldWordLength = getStringLength(oldWord);  
    while (sentence[sentenceIndex] != '\0')
    {
        if (sentence[sentenceIndex] == oldWord[0])
        {
            wordStartIndex = sentenceIndex;  
            int matchIndex = 0;
            while (oldWord[matchIndex] != '\0' && sentence[sentenceIndex] == oldWord[matchIndex])
            {
                sentenceIndex++;
                matchIndex++;
            }
            if (oldWord[matchIndex] == '\0' && (sentence[sentenceIndex] == ' ' || sentence[sentenceIndex] == '\0'))
            {
                int newWordIndex = 0;
                while (newWord[newWordIndex] != '\0')
                {
                    result[resultIndex++] = newWord[newWordIndex++];
                }
            }
            else
            {
                for (int i = wordStartIndex; i < sentenceIndex; i++)
                {
                    result[resultIndex++] = sentence[i];
                }
            }
        }
        else
        {
            result[resultIndex++] = sentence[sentenceIndex++];
        }
    }

}

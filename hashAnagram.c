#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 101

typedef struct node{
    char *word;
    struct node *next;
}node;

typedef struct hash{
    node *table[SIZE];
}hashTable;

node *createNewNode(char *word){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->word = (char *)malloc(strlen(word)+ 1);
    strcpy(newNode->word, word);
    newNode->next = NULL;

    return newNode;
}

int hashFunction(char *word){
    int length = strlen(word);
    char temp[length + 1];

    strcpy(temp, word);

    for(int wordIndex = 0; wordIndex < length-1; wordIndex++){
        for(int nextChar = wordIndex+1; nextChar < length; nextChar++){
            if(temp[wordIndex] > temp[nextChar]){
                char tempCharacter = temp[wordIndex];
                temp[wordIndex] = temp[nextChar];
                temp[nextChar] = tempCharacter;
            }
        }
    }
    int sum = 0;
    for(int wordIndex = 0; wordIndex < length; wordIndex++){
        sum = sum + temp[wordIndex];
    }
    return sum % SIZE;
}

void insertWordHashTable(hashTable *h, char *word){
    int index = hashFunction(word);
    node *newNode = createNewNode(word);

    if(h->table[index] == NULL){
        h->table[index] = newNode;
    }
    else{
        node *temp = h->table[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printAnagramTable(hashTable *h){
    int groupNumberCount = 1;
    for(int tableIndex =0; tableIndex< SIZE; tableIndex++){
        node *temp = h->table[tableIndex];
        if(temp != NULL){
            printf("Anagram group %d: ", groupNumberCount++);
            while(temp != NULL){
                printf("%s ", temp->word);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

hashTable *createHashTable(){
    hashTable *h = (hashTable *)malloc(sizeof(hashTable));
    for(int tableIndex = 0; tableIndex <SIZE; tableIndex++){
        h->table[tableIndex] = NULL;
    }
    return h;
}

int main(){
    int totalWords;
    printf("Enter the number of words: ");
    scanf("%d", &totalWords);

    char word[100];
    hashTable *h = createHashTable();
    
    for(int wordnumber =0; wordnumber< totalWords; wordnumber++){
        scanf("%s", word);
        insertWordHashTable(h, word);
    }

    printAnagramTable(h);

    return 0;
}

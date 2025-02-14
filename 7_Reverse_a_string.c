#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char ch;
    struct stack *next;
} node;

node *createNewNode(char ch, node **top)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->ch = ch;
    newNode->next = NULL;

    return newNode;
}

int isEmpty(node **top)
{
    return (*top == NULL);
}

void push(node **top, char ch)
{
    node *newNode = createNewNode(ch, top);
    newNode->next = *top;
    *top = newNode;
}

char pop(node **top)
{
    if (isEmpty(top))
    {
        return '\0';
    }
    node *temp = *top;
    char poppedChar = temp->ch;
    (*top) = (*top)->next;
    free(temp);
    return poppedChar;
}

int main()
{
    char string[100];
    scanf("%s", string);
    node *top = NULL;
    for (int stringIndex = 0; string[stringIndex] != '\0'; stringIndex++)
    {
        push(&top, string[stringIndex]);
    }
    
    while (!isEmpty(&top))
    {
        printf("%c", pop(&top));
    }
    return 0;
}

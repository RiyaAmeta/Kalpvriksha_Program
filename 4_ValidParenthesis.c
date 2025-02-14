#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char top;
    unsigned size;
    char *arr;
} stack;

stack *createStack(unsigned size)
{
    stack *newStack = (stack *)malloc(sizeof(stack));
    newStack->top = -1;
    newStack->size = size;
    newStack->arr = (char *)malloc(newStack->size * sizeof(char));

    return newStack;
}

int isFull(stack *newStack)
{
    return newStack->top == newStack->size - 1;
}

int isEmpty(stack *newStack)
{
    return newStack->top == -1;
}

void push(stack *newStack, char data)
{
    if (isFull(newStack))
    {
        printf("Size is full cannot push more elements.");
        return;
    }
    newStack->arr[++newStack->top] = data;
}

void pop(stack *newStack)
{
    if (isEmpty(newStack))
    {
        return;
    }
    newStack->top--;
}

char displayTop(stack *newStack)
{
    if (isEmpty(newStack))
    {
        printf("No element present in the stack.");
        return '\0';
    }
    return newStack->arr[newStack->top];
}

int main()
{
    char string[100];
    scanf("%s", string);
    stack *newStack = createStack(100);
    for (int stringIndex = 0; stringIndex < strlen(string); stringIndex++)
    {
        if (string[stringIndex] == '(' || string[stringIndex] == '[' || string[stringIndex] == '{')
        {
            push(newStack, string[stringIndex]);
        }
        else
        {
            if (isEmpty(newStack))
            {
                printf("Not balanced");
                return 0;
            }
            char ch = displayTop(newStack);
            pop(newStack);
            if (string[stringIndex] == ')' && ch == '(' || string[stringIndex] == ']' && ch == '[' || string[stringIndex] == '}' && ch == '{')
            {
                continue;
            }
            else
            {
                printf("Not balanced");
                return 0;
            }
        }
    }
    if (isEmpty(newStack))
    {
        printf("balanced");
    }
    else
    {
        printf("Not balanced");
    }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} node;

node *createNewNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int IsEmpty(node **top)
{
    return (*top == NULL);
}
void push(node **top, int data)
{
    node *newNode = createNewNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(node **top)
{
    node *temp = *top;
    int value = (*top)->data;
    (*top) = (*top)->next;
    free(temp);
    return value;
}

void sortAscending(node **top1)
{
    node *tempStack = NULL;
    while (!IsEmpty(top1))
    {
        int temp = pop(top1);
        while (!IsEmpty(&tempStack) && temp > tempStack->data)
        {
            push(top1, tempStack->data);
            pop(&tempStack);
        }
        push(&tempStack, temp);
    }
    while (!IsEmpty(&tempStack))
    {
        push(top1, pop(&tempStack));
    }
}

void printStack(node *topTemp)
{
    node *temp = topTemp;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    node *top1 = NULL;
    int n, data;
    printf("Enter the length of stack:");
    scanf("%d", &n);
    for (int stackIndex = 0; stackIndex < n; stackIndex++)
    {
        scanf("%d", &data);
        push(&top1, data);
    }
    sortAscending(&top1);
    printStack(top1);

    return 0;
}

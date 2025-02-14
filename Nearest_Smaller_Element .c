#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNewNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(node *top)
{
    return (top == NULL);
}

void push(node **top, int data)
{
    node *newNode = createNewNode(data);
    newNode->next = *top;
    *top = newNode;
}

void pop(node **top)
{
    if (isEmpty(*top))
    {
        return;
    }
    node *temp = *top;
    (*top) = (*top)->next;
    free(temp);
}

void nearestSmallestElement(int arr[], int n, int G[])
{
    node *top = NULL;
    for (int nodeIndex = 0; nodeIndex < n; nodeIndex++)
    {
        while (!isEmpty(top) && top->data >= arr[nodeIndex])
        {
            pop(&top);
        }
        if (!isEmpty(top))
        {
            G[nodeIndex] = top->data;
        }
        else
        {
            G[nodeIndex] = -1;
        }
        push(&top, arr[nodeIndex]);
    }
}

void printList(int G[], int n)
{
    for (int nodeIndex = 0; nodeIndex < n; nodeIndex++)
    {
        printf("%d ", G[nodeIndex]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int G[n];

    for (int arrIndex = 0; arrIndex < n; arrIndex++)
    {
        scanf("%d", &arr[arrIndex]);
    }
    nearestSmallestElement(arr, n, G);
    printList(G, n);
    return 0;
}

#include <stdlib.h>
#include <stdio.h>

typedef struct queue
{
    int start;
    int end;
    int *arr;
    unsigned size;
} queue;

queue *createQueue(int size)
{
    queue *newQ = (queue *)malloc(sizeof(queue));
    newQ->size = size;
    newQ->end = -1;
    newQ->start = -1;
    newQ->arr = (int *)malloc(newQ->size * sizeof(int));

    return newQ;
}

int isEmpty(queue *q)
{
    return q->start == -1;
}

int isFull(queue *q)
{
    return q->end == q->size - 1;
}

void enQueue(queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is overflowing");
        return;
    }
    if (isEmpty(q))
    {
        q->start = 0;
    }
    q->end++;
    q->arr[q->end] = data;
}

void deQueue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty");
        return;
    }
    if (q->start == q->end)
    {
        q->start = -1;
        q->end = -1;
    }
    else
    {
        q->start++;
    }
}

int sizeDisplay(queue *q)
{
    if (isEmpty(q))
    {
        printf("No elements to display stack is empty.");
        return 0;
    }
    return q->end - q->start + 1;
}

void push(queue *q, int data)
{
    enQueue(q, data);
    int s = sizeDisplay(q);
    for (int stackIndex = 0; stackIndex < s - 1; stackIndex++)
    {
        enQueue(q, q->arr[q->start]);
        deQueue(q);
    }
}

void pop(queue *q)
{
    if (isEmpty(q))
    {
        printf("No elements to display stack is empty.");
        return;
    }
    deQueue(q);
}
int topDisplay(queue *q)
{
    if (isEmpty(q))
    {
        printf("No elements to display stack is empty.");
        return -1;
    }
    return q->arr[q->start];
}

void displayStack(queue *q)
{
    if (isEmpty(q))
    {
        printf("No elements to display stack is empty.");
        return;
    }
    for (int stackIndex = q->start; stackIndex <= q->end; stackIndex++)
    {
        printf("%d ", q->arr[stackIndex]);
    }
    printf("\n");
}
int main()
{
    queue *newQueue = createQueue(100);

    int choice;
    int data;
    int topelement;
    int sizestack;

    do
    {
        printf("\nStack implementation using queue\n");
        printf("1. Push element onto the stack\n");
        printf("2. Display the top element of the stack\n");
        printf("3. Pop element from the stack\n");
        printf("4. Display the size of the queue\n");
        printf("5. Check if the stack is empty\n");
        printf("6. Display Stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to enter: ");
            scanf("%d", &data);
            push(newQueue, data);
            break;
        case 2:
            topelement = topDisplay(newQueue);
            printf("Top is: %d", topelement);
            break;
        case 3:
            pop(newQueue);
            break;
        case 4:
            sizestack = sizeDisplay(newQueue);
            printf("Size is: %d", sizestack);
            break;
        case 5:
            if (isEmpty(newQueue))
            {
                printf("Stack is empty");
            }
            else
            {
                printf("Stack is not empty");
            }
            break;
        case 6:
            displayStack(newQueue);
            break;
        case 7:
            printf("Exiting the program");
        default:
            break;
        }
    } while (choice != 6);
}

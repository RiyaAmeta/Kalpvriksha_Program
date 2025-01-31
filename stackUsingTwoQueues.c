#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int start;
    int end;
    int *arr;
    int size;
} queue;

queue *createQueue(int size)
{
    queue *newq = (queue *)malloc(sizeof(queue));
    newq->end = -1;
    newq->start = -1;
    newq->size = size;
    newq->arr = (int *)malloc(newq->size * sizeof(int));

    return newq;
}

int isFUll(queue *q)
{
    return q->end == q->size - 1;
}

int isEmpty(queue *q)
{
    return q->start == -1;
}

void enQueue(queue *q, int data)
{
    if (isFUll(q))
    {
        printf("Queue is full");
        return;
    }
    if (isEmpty(q))
    {
        q->start = 0;
    }
    q->end++;
    q->arr[q->end] = data;
}

int deQueue(queue *q)
{
    int data;
    if (isEmpty(q))
    {
        printf("Queue is empty");
        return -1;
    }
    if (q->start == q->end)
    {
        q->start = -1;
        q->end = -1;
    }
    else
    {
        data = q->arr[q->start];
        q->start++;
    }
    return data;
}

void push(queue *q1, queue *q2, int data)
{
    enQueue(q1, data);
}

int pop(queue **q1, queue **q2)
{
    if (isEmpty(*q1))
    {
        return 0;
    }
    while ((*q1)->start != (*q1)->end)
    {
        enQueue(*q2, deQueue(*q1));
    }
    int value = deQueue(*q1);
    queue *temp = *q1;
    *q1 = *q2;
    *q2 = temp;

    return value;
}

int topDisplay(queue *q1, queue *q2)
{
    if (isEmpty(q1))
    {
        return -1;
    }
    return q1->arr[q1->end];
}

int sizeDisplay(queue *q1)
{
    if (isEmpty(q1))
    {
        return 0;
    }
    return q1->end - q1->start + 1;
}

int main()
{
    queue *newQueue1 = createQueue(100);
    queue *newQueue2 = createQueue(100);

    int choice;
    int data;
    int topElement;
    int sizestack;

    do
    {
        printf("\nStack implementation using queue\n");
        printf("1. Push element onto the stack\n");
        printf("2. Display the top element of the stack\n");
        printf("3. Pop element from the stack\n");
        printf("4. Display the size of the queue\n");
        printf("5. Check if the stack is empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to enter: ");
            scanf("%d", &data);
            push(newQueue1, newQueue2, data);
            break;
        case 2:
            topElement = topDisplay(newQueue1, newQueue2);
            printf("Top is: %d", topElement);
            break;
        case 3:
            pop(&newQueue1, &newQueue2);
            break;
        case 4:
            sizestack = sizeDisplay(newQueue1);
            printf("Size is: %d", sizestack);
            break;
        case 5:
            if (isEmpty(newQueue1))
            {
                printf("Stack is empty");
            }
            else
            {
                printf("Stack is not empty");
            }
            break;
        case 6:
            printf("Exiting the program");
            break;
        default:
            break;
        }
    } while (choice != 6);
    return 0;
}

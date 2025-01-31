#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *que;
    int start;
    int end;
    int unsigned size;
} queue;

queue *createQueue(unsigned size)
{
    queue *newQueue = (queue *)malloc(sizeof(queue));
    newQueue->start = -1;
    newQueue->end = -1;
    newQueue->size = size;
    newQueue->que = (int *)malloc(newQueue->size * sizeof(int));
    return newQueue;
}

int isEmpty(queue *q)
{
    return (q->start == -1);
}

int isFull(queue *q)
{
    return (q->end == q->size - 1);
}

void enQueue(queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full.");
        return;
    }
    if (isEmpty(q))
    {
        q->start = 0;
    }
    q->end++;
    q->que[q->end] = data;
    printf("%d is enqueued into the queue.", data);
}

int deQueue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty");
        return -1;
    }
    int data = q->que[q->start];
    if (q->start == q->end)
    {
        q->start = -1;
        q->end = -1;
    }
    else
    {
        q->start++;
    }
    printf("%d is dequeued from the queue.", data);
    return data;
}

int topDisplay(queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    return q->que[q->start];
}

int sizeDisplay(queue *q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    return q->end - q->start + 1;
}

int main()
{
    queue *newQue = createQueue(100);
    int choice;
    int data;
    int topElement;
    int sizeQueue;

    do
    {
        printf("\nQueue implementation using array\n");
        printf("1. Enqueue element onto the queue\n");
        printf("2. Display the top element of the queue\n");
        printf("3. Dequeue element from the queue\n");
        printf("4. Display the size of the queue\n");
        printf("5. Check is the queue is empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue:");
            scanf("%d", &data);
            enQueue(newQue, data);
            break;
        case 2:
            topDisplay(newQue);
            printf("Top element is: %d", topDisplay(newQue));
            break;
        case 3:
            deQueue(newQue);
            break;
        case 4:
            sizeQueue = sizeDisplay(newQue);
            printf("The size of the queue is : %d", sizeQueue);
            break;
        case 5:
            if (isEmpty(newQue))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty");
            }
            break;
        case 6:
            printf("Exiting the program");
            break;
        default:
            break;
        }
    } while (choice != 6);
}

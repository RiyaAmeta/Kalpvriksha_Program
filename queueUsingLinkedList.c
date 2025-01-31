#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct queue
{
    node *start;
    node *end;
    int size;
} queue;

node *createNewNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

queue *createQueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->start = NULL;
    q->end = NULL;
    q->size = 0;
    return q;
}

int isEmpty(queue *q)
{
    return q->start == NULL;
}

void enQueue(queue *q, int data)
{
    node *newnode = createnode(data);
    if (q->end == NULL)
    {
        q->start = q->end = newnode;
    }
    else
    {
        q->end->next = newnode;
        q->end = newnode;
    }
    q->size++;
}

int deQueue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    node *temp = q->start;
    int data = temp->data;
    q->start = q->start->next;
    if (q->start == NULL)
    {
        q->end = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

int topDisplay(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->start->data;
}

int sizeDisplay(queue *q)
{
    return q->size;
}

int main()
{
    queue *newQue = createQueue();
    int choice, data;

    do
    {
        printf("\nQueue implementation using linked list\n");
        printf("1. Enqueue element into the queue\n");
        printf("2. Display the top element of the queue\n");
        printf("3. Dequeue element from the queue\n");
        printf("4. Display the size of the queue\n");
        printf("5. Check if the queue is empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &data);
            enQueue(newQue, data);
            break;

        case 2:
            data = top(newQue);
            if (data != -1)
                printf("Top element is: %d\n", data);
            break;

        case 3:
            data = deQueue(newQue);
            if (data != -1)
                printf("Dequeued element: %d\n", data);
            break;

        case 4:
            printf("The size of the queue is: %d\n", sizeDisplay(newQue));
            break;

        case 5:
            if (isEmpty(newQue))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;

        case 6:
            printf("Exiting the program\n");
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 6);
    return 0;
}

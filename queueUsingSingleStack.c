#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *arr;
    int top;
    int size;
} stack;

stack *createNewStack(int size)
{
    stack *newS = (stack *)malloc(sizeof(stack));
    newS->arr = (int *)malloc(size * sizeof(int));
    newS->top = -1;
    newS->size = size;

    return newS;
}

int isFull(stack *s)
{
    return s->top == s->size - 1;
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

void push(stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack is full.\n");
        return;
    }
    s->arr[++s->top] = data;
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->arr[s->top--];
}

int peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->arr[s->top];
}

void enQueue(stack *s, int data)
{
    push(s, data);
}

int deQueue(stack *s)
{
    if (isEmpty(s))
    {
        printf("Queue is empty.\n");
        return -1;
    }

    if (s->top == 0)
    {
        return pop(s);
    }

    int temp = pop(s);
    int result = deQueue(s);

    push(s, temp);

    return result;
}

int sizeDisplay(stack *s)
{
    return s->top + 1;
}

int main()
{
    stack *newStack = createNewStack(100);
    int data, choice, topElement, queueSize;

    do
    {
        printf("\nQueue implementation using a single stack\n");
        printf("1. Enqueue element into the queue\n");
        printf("2. Display the front element of the queue\n");
        printf("3. Dequeue element from the queue\n");
        printf("4. Display the size of the queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to enqueue: ");
            scanf("%d", &data);
            enQueue(newStack, data);
            break;
        case 2:
            topElement = peek(newStack);
            printf("Front element is: %d\n", topElement);
            break;
        case 3:
            data = deQueue(newStack);
            if (data != -1)
            {
                printf("Dequeued element: %d\n", data);
            }
            break;
        case 4:
            queueSize = sizeDisplay(newStack);
            printf("Queue size is: %d\n", queueSize);
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}

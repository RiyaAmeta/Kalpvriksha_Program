#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int *stack1;
    int *stack2;
    int top1;
    int top2;
    int size;
} stack;

stack *creatNewstack(stack *s, int size)
{
    stack *newS = (stack *)malloc(sizeof(stack));
    newS->top1 = -1;
    newS->top2 = -1;
    newS->size = size;
    newS->stack1 = (int *)malloc(newS->size * sizeof(int));
    newS->stack2 = (int *)malloc(newS->size * sizeof(int));
    return newS;
}

int isEmpty(stack *s)
{
    return s->top1 == -1;
}

void push(stack *newStack, int data)
{
    if (newStack->top1 == newStack->size - 1)
    {
        printf("Size is full cannot push more elements.");
        return;
    }

    while (newStack->top1 >= 0)
    {
        newStack->stack2[++newStack->top2] = newStack->stack1[newStack->top1--];
    }
    newStack->stack1[++newStack->top1] = data;

    while (newStack->top2 >= 0)
    {
        newStack->stack1[++newStack->top1] = newStack->stack2[newStack->top2--];
    }
    printf("Pushed to stack succesfully.");
}

int popElement(stack *newStack)
{
    if (newStack->top1 < 0)
    {
        printf("No element present.");
        return -1;
    }
    return newStack->stack1[newStack->top1--];
}

int displayTop(stack *newStack)
{
    if (newStack->top1 < 0)
    {
        printf("No element present in the stack.");
        return -1;
    }
    return newStack->stack1[newStack->top1];
}

int sizeDisplay(stack *newStack)
{
    return newStack->top1 + 1;
}

int main()
{
    stack *newStack = creatNewstack(newStack, 100);
    int choice;
    int data;
    int topele;
    int sizestack;

    do
    {
        printf("\nQueue implementation using stack\n");
        printf("1. Push element onto the stack\n");
        printf("2. Display the top element of the queue\n");
        printf("3. Pop element from the queue\n");
        printf("4. Display the size of the queue\n");
        printf("5. Check is the queue is empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to enter: ");
            scanf("%d", &data);
            push(newStack, data);
            break;
        case 2:
            topele = displayTop(newStack);
            printf("Top is: %d", topele);
            break;
        case 3:
            popElement(newStack);
            break;
        case 4:
            sizestack = sizeDisplay(newStack);
            printf("Size is: %d", sizestack);
            break;
        case 5:
            if (isEmpty(newStack))
            {
                printf("Queue is empty");
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
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    unsigned size;
    int *array;
} stack;

stack *createStack(unsigned size)
{
    stack *newStack = (stack *)malloc(sizeof(stack));
    newStack->size = size;
    newStack->top = -1;
    newStack->array = (int *)malloc(newStack->size * sizeof(int));

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

void push(stack *newStack, int element)
{
    if (isFull(newStack))
    {
        printf("Size is full cannot push more elements.");
        return;
    }
    newStack->array[++newStack->top] = element;
    printf("Pushed to stack succesfully.");
}

int peek(stack *newStack)
{
    if (isEmpty(newStack))
    {
        printf("No element present in the stack.");
        return -1;
    }
    return newStack->array[newStack->top];
}

int popElement(stack *newStack)
{
    if (isEmpty(newStack))
    {
        printf("No element present.");
        return -1;
    }
    return newStack->array[newStack->top--];
}

int displaySize(stack *newStack)
{
    if (isEmpty(newStack))
    {
        printf("No element to display.");
        return 0;
    }
    return newStack->top + 1;
}

int main()
{
    stack *newStack = createStack(100);
    int choice;
    int element;
    int topElement, stackSize;
    do
    {
        printf("\nStack implementation using array\n");
        printf("1. Push element onto the stack\n");
        printf("2. Display the top element of the stack\n");
        printf("3. Pop element from the stack\n");
        printf("4. Display the size of the stack\n");
        printf("5. Check if stack is Empty.\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element you want to push: ");
            scanf("%d", &element);
            push(newStack, element);
            break;
        case 2:
            topElement = peek(newStack);
            if (topElement != -1)
            {
                printf("The top of the stack is: %d\n", topElement);
            }
            break;
        case 3:
            element = popElement(newStack);
            if (element != -1)
            {
                printf("Popped element: %d\n", element);
            }
            break;
        case 4:
            stackSize = displaySize(newStack);
            if (stackSize != 0)
            {
                printf("The size of the stack is: %d\n", stackSize);
            }
            break;
        case 5:
            if(isEmpty(newStack)){
                printf("Stack is empty.");
            };
            break;
        case 6:
            printf("Exiting the system.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 6);
}

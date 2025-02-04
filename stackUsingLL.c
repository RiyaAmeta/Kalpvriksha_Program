#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void isEmpty(node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
}
void push(node **top, int data, int *size)
{
    node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    *size = *size + 1;
}

void pop(node **top, int *size)
{
    node *temp = *top;
    *top = (*top)->next;
    free(temp);
    *size = *size - 1;
}

int topDisplay(node **top)
{
    return (*top)->data;
}

int sizeDisplay(node *top, int *size)
{
    return *size;
}

int main()
{
    node *top = NULL;
    int data;
    int size = 0;
    int choice;
    int topElement;
    int stackSize;
    do
    {
        printf("\nStack implementation using array\n");
        printf("1. Push element onto the stack\n");
        printf("2. Display the top element of the stack\n");
        printf("3. Pop element from the stack\n");
        printf("4. Display the size of the stack\n");
        printf("5. Check if stack is empty or not\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element you want to push: ");
            scanf("%d", &data);
            push(&top, data, &size);
            break;
        case 2:
            topElement = topDisplay(&top);
            printf("The top of the stack is: %d\n", topElement);
            break;
        case 3:
            pop(&top, &size);
            printf("Element popped succesfully.");
            break;
        case 4:
            stackSize = sizeDisplay(top, &size);
            if (stackSize != 0)
            {
                printf("The size of the stack is: %d\n", stackSize);
            }
            break;
        case 5:
            isEmpty(&top);
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

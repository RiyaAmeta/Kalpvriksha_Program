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

void insertAtEnd(node **head, int data)
{
    node *newNode = createNewNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void evenOddOrder(node **head)
{
    int arr[100];
    int arrIndex = 0;
    node *temp = *head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            arr[arrIndex++] = temp->data;
        }
        temp = temp->next;
    }
    temp = *head;
    while (temp != NULL)
    {
        if (temp->data % 2 != 0)
        {
            arr[arrIndex++] = temp->data;
        }
        temp = temp->next;
    }
    temp = *head;
    arrIndex = 0;
    while (temp != NULL)
    {
        temp->data = arr[arrIndex++];
        temp = temp->next;
    }
}
void printList(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    node *head = NULL;

    int length, data;
    printf("Enter the length of the list.");
    scanf("%d", &length);

    for (int nodeData = 0; nodeData < length; nodeData++)
    {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    evenOddOrder(&head);
    printList(head);
    return 0;
}

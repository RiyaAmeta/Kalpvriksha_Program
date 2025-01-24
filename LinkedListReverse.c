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
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

node *reverse(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newHead = reverse(head->next);
    node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

void printList(node *head)
{
    if (head == NULL)
    {
        printf("No nodes present.");
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
    int nodeNum, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodeNum);
    for (int nodeIndex = 0; nodeIndex < nodeNum; nodeIndex++)
    {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    node *result = reverse(head);
    printList(result);
}

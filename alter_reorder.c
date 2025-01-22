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

node *reverseLL(node *head)
{
    node *temp = head;
    node *prev = NULL;
    node *front = NULL;

    while (temp != NULL)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    head = prev;
    return head;
}

void alternateArrangment(node **head)
{
    node *slow = *head;
    node *fast = *head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *newHead = reverseLL(slow->next);
    slow->next = NULL;
    node *first = *head;
    node *last = newHead;
    node *temp = NULL;
    while (first != NULL && last != NULL)
    {
        temp = first->next;
        first->next = last;
        first = temp;

        temp = last->next;
        last->next = first;
        last = temp;
    }
    return;
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
    alternateArrangment(&head);
    printList(head);
    return 0;
}

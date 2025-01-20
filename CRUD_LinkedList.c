#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNewNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int dataValidity(int data)
{
    return (data >= -10000 && data <= 10000);
}

void insertAtBeginning(struct node **head, int data)
{
    if (!dataValidity(data))
    {
        printf("Invalid data.\n");
        return;
    }
    struct node *newNode = createNewNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct node **head, int data)
{
    if (!dataValidity(data))
    {
        printf("Invalid data.\n");
        return;
    }
    struct node *newNode = createNewNode(data);
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

void insertAtPosition(struct node **head, int data, int position)
{
    struct node *newNode = createNewNode(data);
    if (!dataValidity(data))
    {
        printf("Invalid data.\n");
        return;
    }
    if (position < 1)
    {
        printf("Invalid.\n");
        return;
    }
    if (position == 1)
    {
        insertAtBeginning(head, data);
        return;
    }
    struct node *temp = *head;
    for (int posIndex = 1; temp != NULL && posIndex < position - 1; posIndex++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void displayListElements(struct node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void updateAtPosition(struct node **head, int position, int newData)
{
    if (!dataValidity(newData))
    {
        printf("Invalid data.\n");
        return;
    }
    if (position < 1 || *head == NULL)
    {
        printf("Invalid.\n");
        return;
    }
    struct node *temp = *head;
    for (int posIndex = 1; temp != NULL && posIndex < position; posIndex++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid.\n");
        return;
    }
    temp->data = newData;
}

void deleteAtStart(struct node **head)
{
    struct node *temp = *head;
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    *head = (*head)->next;
    free(temp);
    return;
}

void deleteAtEnd(struct node **head)
{
    if (*head == NULL)
    {
        printf("LIst is empty.\n");
        return;
    }
    struct node *temp = *head;
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteOnPosition(struct node **head, int position)
{
    if (position < 1 || *head == NULL)
    {
        printf("Invalid.\n");
        return;
    }
    struct node *temp = *head;
    if (position == 1)
    {
        deleteAtStart(head);
        return;
    }
    for (int posIndex = 1; temp != NULL && posIndex < position - 1; posIndex++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid.\n");
        return;
    }
    struct node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

int main()
{
    int operationsNumber;
    struct node *head = NULL;
    printf("Enter the number of operations to perform:");

    while (1)
    {
        scanf("%d", &operationsNumber);
        if (operationsNumber > 1 && operationsNumber <= 100)
        {
            break;
        }
        else
        {
            printf("Invalid, enter again.\n");
        }
    }
    while (operationsNumber--)
    {
        int choice, data, position;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 2:
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 3:
            scanf("%d %d", &position, &data);
            insertAtPosition(&head, data, position);
            break;
        case 4:
            displayListElements(head);
            break;
        case 5:
            scanf("%d %d", &position, &data);
            updateAtPosition(&head, position, data);
            break;
        case 6:
            deleteAtStart(&head);
            break;
        case 7:
            deleteAtEnd(&head);
            break;
        case 8:
            scanf("%d ", &position);
            deleteOnPosition(&head, position);
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

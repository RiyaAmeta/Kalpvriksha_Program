#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createnode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(node **head, int data)
{
    node *newnode = createnode(data);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

int getLength(node *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}

void linkedListToArray(node *head, int arr[], int length)
{
    for (int arrIndex = 0; arrIndex < length; arrIndex++)
    {
        arr[arrIndex] = head->data;
        head = head->next;
    }
}

void bubbleSort(int arr[], int length)
{
    for (int arrIndex = 0; arrIndex < length - 1; arrIndex++)
    {
        for (int arrayIndexIterator = 0; arrayIndexIterator < length -arrIndex - 1; arrayIndexIterator++)
        {
            if (arr[arrayIndexIterator] > arr[arrayIndexIterator + 1])
            {
                int temp = arr[arrayIndexIterator];
                arr[arrayIndexIterator] = arr[arrayIndexIterator + 1];
                arr[arrayIndexIterator + 1] = temp;
            }
        }
    }
}

double calculateMedian(node *head)
{
    int length = getLength(head);
    if (length == 0)
        return 0.0;

    int arr[100];
    linkedListToArray(head, arr, length);

    bubbleSort(arr, length);

    if (length % 2 == 0)
    {
        return (arr[length / 2 - 1] + arr[length / 2]) / 2.0;
    }
    else
    {
        return arr[length / 2];
    }
}

void printList(node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    node *head = NULL;

    int totalNodes, data;

    printf("Enter the number of elements of the list:");
    scanf("%d", &totalNodes);

    for (int arrayIndex = 0; arrayIndex < totalNodes; arrayIndex++)
    {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    printf("Linked list: ");
    printList(head);
    printf("Median: %.2f\n", calculateMedian(head));

    return 0;
}

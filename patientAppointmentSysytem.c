#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int patientID;
    char *severity;
    struct node *next;
} node;

node *createNewNode(int patientID, char *severity)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->patientID = patientID;
    newNode->severity = (char *)malloc(strlen(severity) + 1);
    strcpy(newNode->severity, severity);
    newNode->next = NULL;

    return newNode;
}

void insertAtEnd(node **head, int patientID, char *severity)
{
    node *newNode = createNewNode(patientID, severity);

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

int severityValue(char *severity)
{
    if (strcmp(severity, "Critical") == 0)
    {
        return 0;
    }
    if (strcmp(severity, "Serious") == 0)
    {
        return 1;
    }
    if (strcmp(severity, "Stable") == 0)
    {
        return 2;
    }
    return -1;
}

void sortList(node *head, int nodes)
{
    if (head == NULL)
    {
        return;
    }
    node *temp1, *temp2;
    int swapped;
    for (int nodeIndex = 0; nodeIndex < nodes - 1; nodeIndex++)
    {
        swapped = 0;
        temp1 = head;
        while (temp1 != NULL && temp1->next != NULL)
        {
            temp2 = temp1->next;
            if (severityValue(temp1->severity) > severityValue(temp2->severity))
            {
                int tempID = temp1->patientID;
                char *tempSeverity = temp1->severity;
                temp1->patientID = temp2->patientID;
                temp1->severity = temp2->severity;
                temp2->patientID = tempID;
                temp2->severity = tempSeverity;
                swapped = 1;
            }
            temp1 = temp1->next;
        }
        if (swapped == 0)
        {
            break;
        }
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
        printf("%d %s\n", temp->patientID, temp->severity);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    node *head = NULL;
    int totalPatient;
    int patientID;
    char severity[100];
    scanf("%d", &totalPatient);
    for (int nodeIndex = 0; nodeIndex < totalPatient; nodeIndex++)
    {
        scanf("%d %s", &patientID, severity);
        insertAtEnd(&head, patientID, severity);
    }
    sortList(head, totalPatient);
    printf("The sorted patient list is: \n");
    printList(head);
}

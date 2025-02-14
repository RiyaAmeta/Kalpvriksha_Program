#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *URL;
    struct node *next;
} node;

node *createNewNode(char *URL)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->URL = (char *)malloc(strlen(URL) + 1);
    strcpy(newNode->URL, URL);
    newNode->next = NULL;

    return newNode;
}

int isEmpty(node **top)
{
    return (*top == NULL);
}

void push(node **top, char *URL)
{
    node *newNode = createNewNode(URL);
    newNode->next = *top;
    *top = newNode;
}

void pop(node **top)
{
    if (isEmpty(top))
    {
        return;
    }
    node *temp = *top;
    (*top) = (*top)->next;
    free(temp);
}

void readWebsite(node **top)
{
    node *temp = *top;
    while (temp != NULL)
    {
        printf("%s\n", temp->URL);
        temp = temp->next;
    }
}

void editURL(node **top, char *oldURl, char *newURL)
{
    node *temp = *top;
    while (temp != NULL)
    {
        if (strcmp(temp->URL, oldURl) == 0)
        {
            free(temp->URL);
            temp->URL = (char *)malloc(strlen(newURL) + 1);
            strcpy(temp->URL, newURL);
            return;
        }
        temp = temp->next;
    }
}

void clearHistory(node **top)
{
    while (!isEmpty(top))
    {
        pop(top);
    }
    return;
}

void topDisplay(node *top)
{
    printf("%s\n", top->URL);
}

int main()
{
    node *top = NULL;

    char URL[100];

    int choice;
    char oldURL[100];
    char newURL[100];
    do
    {
        printf("\nBrowser History Management System\n");
        printf("1. Add website\n");
        printf("2. View History (Read)\n");
        printf("3. Edit a URL (Update)\n");
        printf("4. Remove Recent Website (Pop)\n");
        printf("5. Clear History\n");
        printf("6. Most Recent website\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the website you want to add: ");
            scanf("%s", URL);
            push(&top, URL);
            break;
        case 2:
            readWebsite(&top);
            break;
        case 3:
            printf("Enter the URL you want to edit: ");
            scanf("%s", oldURL);
            printf("Enter the new URL: ");
            scanf("%s", newURL);
            editURL(&top, oldURL, newURL);
            break;
        case 4:
            pop(&top);
            break;
        case 5:
            clearHistory(&top);
            break;
        case 6:
            topDisplay(top);
            break;
        case 7:
            printf("Exiting the program");
            break;
        default:
            break;
        }
    } while (choice != 7);
}

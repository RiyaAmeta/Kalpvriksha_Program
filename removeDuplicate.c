#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int tranID;
    int userID;
    float amount;
    int timeStamp;
    struct node *next;
} node;

typedef struct hashMap
{
    int capacity;
    node **arr;
} hashMap;

void initializeHashMap(hashMap *ht, int capacity)
{
    ht->capacity = capacity;
    ht->arr = (node **)malloc(capacity * sizeof(node *));
    for (int i = 0; i < capacity; i++)
    {
        ht->arr[i] = NULL;
    }
}

int hashFunction(hashMap *ht, int userID)
{
    return userID % ht->capacity;
}

node *createNewNode(int tranID, int userID, float amount, int timeStamp)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->tranID = tranID;
    newNode->userID = userID;
    newNode->amount = amount;
    newNode->timeStamp = timeStamp;
    newNode->next = NULL;

    return newNode;
}

void insertHash(hashMap *ht, int tranId, int userId, float amount, int timeStamp)
{
    int index = hashFunction(ht, userId);
    node *newNode = createNewNode(tranId, userId, amount, timeStamp);
    newNode->next = ht->arr[index];
    ht->arr[index] = newNode;
}

void removeDuplicates(hashMap *ht)
{
    for (int i = 0; i < ht->capacity; i++)
    {
        node *current = ht->arr[i];
        node *prev = NULL;

        while (current != NULL)
        {
            node *temp = current;
            prev = current;

            while (temp->next != NULL)
            {
                if (current->userID == temp->next->userID && current->amount == temp->next->amount &&
                    abs(current->timeStamp - temp->next->timeStamp) <= 60)
                {
                    node *remove = temp->next;
                    temp->next = remove->next;
                    free(remove);
                }
                else
                {
                    temp = temp->next;
                }
            }
            current = current->next;
        }
    }
}

void displayUniqueTransactions(hashMap *ht)
{
    int found = 0;
    for (int i = 0; i < ht->capacity; i++)
    {
        node *current = ht->arr[i];
        while (current != NULL)
        {
            printf("Transaction ID: %d, User ID: %d, Amount: %.2f, Timestamp: %d\n",
                   current->tranID, current->userID, current->amount, current->timeStamp);
            current = current->next;
            found = 1;
        }
    }
    if (!found)
    {
        printf("No unique transactions found.\n");
    }
}

int main()
{
    int n;
    printf("Enter the size of the hashmap: ");
    scanf("%d", &n);

    hashMap *ht = (hashMap *)malloc(sizeof(hashMap));
    initializeHashMap(ht, n);
    int tranId, userId, timeStamp;
    float amount;
    int choice;
    do
    {
        printf("1. Insert Transaction\n");
        printf("2. Remove Duplicates\n");
        printf("3. Display Unique Transactions\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the transaction ID: ");
            scanf("%d", &tranId);

            printf("Enter the User ID: ");
            scanf("%d", &userId);

            printf("Enter the amount: ");
            scanf("%f", &amount);

            printf("Enter the timestamp: ");
            scanf("%d", &timeStamp);

            insertHash(ht, tranId, userId, amount, timeStamp);
            break;
        case 2:
            removeDuplicates(ht);
            break;
        case 3:
            displayUniqueTransactions(ht);
            break;
        case 4:
            printf("Exiting the program");
            break;
        default:
            break;
        }
    } while (choice != 4);
    return 0;
}

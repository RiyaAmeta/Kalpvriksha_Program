#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int key;
    int value;
    struct node *next;
} node;

typedef struct
{
    int capacity;
    node **arr;
} hashMap;

void initializeHashMap(hashMap *map, int capacity)
{
    map->capacity = capacity;
    map->arr = (node **)malloc(capacity * sizeof(node *));
    for (int arrIndex = 0; arrIndex < capacity; arrIndex++)
    {
        map->arr[arrIndex] = NULL;
    }
}

int hashFunction(hashMap *map, int key)
{
    return key % map->capacity;
}

node *createNode(int tempKey, int tempValue)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        return NULL;
    }
    newNode->key = tempKey;
    newNode->value = tempValue;
    newNode->next = NULL;

    return newNode;
}

void insert(hashMap *map)
{
    int tempKey;
    int tempValue;
    printf("enter key: ");
    scanf("%d", &tempKey);

    printf("Enter the value: ");
    scanf("%d", &tempValue);

    node *newNode = createNode(tempKey, tempValue);
    int index = hashFunction(map, tempKey);
    if (map->arr[index] == NULL)
    {
        map->arr[index] = newNode;
    }
    else
    {
        newNode->next = map->arr[index];
        map->arr[index] = newNode;
    }
}

void search(hashMap *map)
{
    int searchKey;
    printf("Enter key: ");
    scanf("%d", &searchKey);
    int searchIndex = hashFunction(map, searchKey);
    node *searchNode = map->arr[searchIndex];

    while (searchNode != NULL)
    {
        if (searchNode->key == searchKey)
        {
            printf("Value: %d\n", searchKey, searchNode->value);
            return;
        }
        searchNode = searchNode->next;
    }
    printf("Not found\n");
}

void delete(hashMap *map)
{
    int deleteKey;
    printf("Enter the key to be deleted:");
    scanf("%d", &deleteKey);

    int deleteIndex = hashFunction(map, deleteKey);
    node *prev = NULL;
    node *curr = map->arr[deleteIndex];

    while (curr != NULL)
    {
        if (curr->key == deleteKey)
        {
            if (prev == NULL)
            {
                map->arr[deleteIndex] = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            printf("Deleted\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Not found\n");
}

void display(hashMap *map)
{
    int found = 0;
    for (int arrIndex = 0; arrIndex < map->capacity; arrIndex++)
    {
        node *curr = map->arr[arrIndex];
        found = 0;
        while (curr != NULL)
        {
            if (found == 0)
            {
                printf("(%d, %d)", curr->key, curr->value);
            }
            else
            {
                printf("->");
                printf("(%d, %d)", curr->key, curr->value);
            }
            curr = curr->next;
            found = 1;
        }
        printf("\n");
    }
    if (found == 0)
    {
        printf("Map is empty\n");
    }
}

int main()
{
    int n;
    printf("Enter the size of the map: ");
    scanf("%d", &n);

    hashMap *map = (hashMap *)malloc(sizeof(hashMap));
    initializeHashMap(map, n);
    int choice;
    while (1)
    {
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(map);
            break;
        case 2:
            search(map);
            break;
        case 3:
            delete (map);
            break;
        case 4:
            display(map);
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }
}

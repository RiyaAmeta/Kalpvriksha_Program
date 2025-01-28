#include <stdio.h>

int linearSearch(int arr[], int size, int key, int index)
{
    if (size == 0)
    {
        return -1;
    }
    if (arr[0] == key)
    {
        return index;
    }
    else
    {
        linearSearch(arr + 1, size - 1, key, index + 1);
    }
}

int main()
{
    int arr[100];
    int key;
    int size = sizeof(arr);
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    for (int arrayIndex = 0; arrayIndex < size; arrayIndex++)
    {
        scanf("%d", &arr[arrayIndex]);
    }
    printf("Enter key: ");
    scanf("%d", &key);
    int ans = linearSearch(arr, size, key, 0);
    if (ans == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", ans);
    }
}

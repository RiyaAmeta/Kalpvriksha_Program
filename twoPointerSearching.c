#include <stdio.h>

int twoPointerSearching(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[100];
    int key;
    int size = sizeof(arr);
    int start = 0;

    printf("Enter the size of the array : ");
    scanf("%d", &size);
    int end = size - 1;

    for (int arrayIndex = 0; arrayIndex < size; arrayIndex++)
    {
        scanf("%d", &arr[arrayIndex]);
    }
    printf("Enter key: ");
    scanf("%d", &key);

    int ans = twoPointerSearching(arr, size, key);

    printf("The index of the key is : %d", ans);
    if (ans == -1)
    {
        printf("Element not found n the array.");
    }
}

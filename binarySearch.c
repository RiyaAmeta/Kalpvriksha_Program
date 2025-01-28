#include <stdio.h>

void printArray(int arr[], int start, int end)
{
    for (int arrayIndex = start; arrayIndex <= end; arrayIndex++)
    {
        printf("%d ", arr[arrayIndex]);
    }
}

int binarySearch(int *arr, int size, int start, int end, int key)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {

        return mid;
    }
    if (arr[mid] > key)
    {
        binarySearch(arr, size, start, mid - 1, key);
    }
    if (arr[mid] < key)
    {
        binarySearch(arr, size, mid + 1, end, key);
    }
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

    int ans = binarySearch(arr, size, start, end, key);
    printf("The index of the key is : %d", ans);
}

#include <stdio.h>

void selectionSort(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }
    int min = 0;
    for (int arrayIndex = 1; arrayIndex < size; arrayIndex++)
    {
        if (arr[min] > arr[arrayIndex])
        {
            min = arrayIndex;
        }
    }
    int temp = arr[min];
    arr[min] = arr[0];
    arr[0] = temp;
    selectionSort(arr + 1, size - 1);
}

int main()
{
    int arr[100];
    int size;
    ;
    scanf("%d", &size);
    for (int arryIndex = 0; arryIndex < size; arryIndex++)
    {
        scanf("%d", &arr[arryIndex]);
    }
    selectionSort(arr, size);
    for (int arraryIndex = 0; arraryIndex < size; arraryIndex++)
    {
        printf("%d ", arr[arraryIndex]);
    }
}

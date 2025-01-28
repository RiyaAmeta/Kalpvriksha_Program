#include <stdio.h>

int partition(int arr[], int start, int end)
{
    int count = 0;
    int pivot = arr[start];
    for (int arrayIndex = start + 1; arrayIndex <= end; arrayIndex++)
    {
        if (arr[arrayIndex] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = start + count;
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[start];
    arr[start] = temp;

    int leftIterator = start;
    int rightIterator = end;
    while (leftIterator < pivotIndex && rightIterator > pivotIndex)
    {
        while (arr[leftIterator] < pivot)
        {
            leftIterator++;
        }
        while (arr[rightIterator] > pivot)
        {
            rightIterator--;
        }
        if (leftIterator < pivotIndex && rightIterator > pivotIndex)
        {
            int temp = arr[leftIterator];
            arr[leftIterator] = arr[rightIterator];
            arr[rightIterator] = temp;
            leftIterator++;
            rightIterator--;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main()
{
    int size;
    int arr[100];
    scanf("%d", &size);

    for (int arrayIndex = 0; arrayIndex < size; arrayIndex++)
    {
        scanf("%d", &arr[arrayIndex]);
    }
    quickSort(arr, 0, size - 1);

    for (int arrayIndex = 0; arrayIndex < size; arrayIndex++)
    {
        printf("%d ", arr[arrayIndex]);
    }
}

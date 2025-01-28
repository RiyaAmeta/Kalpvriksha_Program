#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int start, int end)
{

    int mid = (start + end) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *left = (int *)malloc(len1 * sizeof(int));
    int *right = (int *)malloc(len2 * sizeof(int));

    int mainArrayIndex = start;
    for (int leftArrayIndex = 0; leftArrayIndex < len1; leftArrayIndex++)
    {
        left[leftArrayIndex] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int rightArrayIndex = 0; rightArrayIndex < len2; rightArrayIndex++)
    {
        right[rightArrayIndex] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;
    while (index1 < len1 && index2 < len2)
    {
        if (left[index1] < right[index2])
        {
            arr[mainArrayIndex++] = left[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = right[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = left[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = right[index2++];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
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
    mergeSort(arr, 0, size - 1);

    for (int arrayIndex = 0; arrayIndex < size; arrayIndex++)
    {
        printf("%d ", arr[arrayIndex]);
    }
}

#include <stdio.h>

void insertionSort(int arr[], int size, int arrayIndex)
{
    if (arrayIndex == size)
    {
        return;
    }
    int currentElement = arr[arrayIndex];
    int index = arrayIndex - 1;

    while (index >= 0 && arr[index] > currentElement)
    {
        arr[index + 1] = arr[index];
        index--;
    }

    arr[index + 1] = currentElement;

    insertionSort(arr, size, arrayIndex + 1);
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

    insertionSort(arr, size, 0);

    for (int arrayIndex = 0; arrayIndex < size; arrayIndex++)
    {
        printf("%d ", arr[arrayIndex]);
    }
}

#include <stdio.h>

void bubbleSort(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return;
    }
    for (int arrayIndex = 0; arrayIndex < size - 1; arrayIndex++)
    {
        if (arr[arrayIndex] > arr[arrayIndex + 1])
        {
            int temp = arr[arrayIndex];
            arr[arrayIndex] = arr[arrayIndex + 1];
            arr[arrayIndex + 1] = temp;
        }
    }
    bubbleSort(arr, size - 1);
}

int main()
{
    int size;
    int arr[100];
    size = sizeof(arr);

    scanf("%d", &size);

    for (int arrayIndex = 0; arrayIndex < size; arrayIndex++)
    {
        scanf("%d", &arr[arrayIndex]);
    }
    bubbleSort(arr, size);
    for (int arrayIndex = 0; arrayIndex < size; arrayIndex++)
    {
        printf("%d ", arr[arrayIndex]);
    }
}

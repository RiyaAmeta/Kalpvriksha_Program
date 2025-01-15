#include <stdio.h>

void inputMatrix(int row, int col, int matrix[row][col])
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            printf("Enter element for [%d][%d]: ", rowIndex, colIndex);
            scanf("%d", &matrix[rowIndex][colIndex]);
        }
    }
}

int findKthSmallest(int row, int col, int matrix[row][col], int k_th_element)
{
    int temp = 0, count = 0;

    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            if (count != k_th_element && matrix[rowIndex][colIndex] != temp)
            {
                count++;
            }
            temp = matrix[rowIndex][colIndex];

            if (count == k_th_element)
            {
                return temp; 
            }
        }
    }

    return -1; 
}

void printResult(int result, int k_th_element)
{
    if (result != -1)
    {
        printf("The %d-th smallest element is: %d\n", k_th_element, result);
    }
    else
    {
        printf("The %d-th smallest element does not exist in the matrix.\n", k_th_element);
    }
}

int main()
{
    int row, col, k_th_element;

    printf("Enter the dimensions of the matrix (row col): ");
    scanf("%d %d", &row, &col);

    int matrix[row][col];

    printf("Enter the value of k (position of the smallest element): ");
    scanf("%d", &k_th_element);

    inputMatrix(row, col, matrix);

    int result = findKthSmallest(row, col, matrix, k_th_element);

    printResult(result, k_th_element);

    return 0;
}


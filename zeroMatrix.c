#include <stdio.h>

void rowZero(int matrix[][100], int col, int constRow)
{
    for (int colIndex = 0; colIndex < col; colIndex++)
    {
        matrix[constRow][colIndex] = 0;
    }
}

void colZero(int matrix[][100], int row, int constCol)
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        matrix[rowIndex][constCol] = 0;
    }
}

void inputMatrix(int matrix[][100], int row, int col)
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            printf("Enter element at [%d][%d]: ", rowIndex, colIndex);
            scanf("%d", &matrix[rowIndex][colIndex]);
        }
    }
}

int findZeroPositions(int matrix[][100], int row, int col, int arr[])
{
    int index = 0;
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            if (matrix[rowIndex][colIndex] == 0)
            {
                arr[index] = rowIndex;
                arr[index + 1] = colIndex;
                index += 2;
            }
        }
    }
    return index;
}

void processMatrix(int matrix[][100], int row, int col, int arr[], int k)
{
    for (int indexArr = 0; indexArr < k; indexArr += 2)
    {
        int constRow = arr[indexArr];
        rowZero(matrix, col, constRow);
        int constCol = arr[indexArr + 1];
        colZero(matrix, row, constCol);
    }
}

void printMatrix(int matrix[][100], int row, int col)
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            printf("%d ", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

int main()
{
    int row, col;
    printf("Enter the dimensions of the matrix: ");
    scanf("%d %d", &row, &col);

    int matrix[100][100];
    inputMatrix(matrix, row, col);

    int arr[200];
    int zeroIndices = findZeroPositions(matrix, row, col, arr);

    processMatrix(matrix, row, col, arr, zeroIndices);

    printf("Modified Matrix:\n");
    printMatrix(matrix, row, col);

    return 0;
}


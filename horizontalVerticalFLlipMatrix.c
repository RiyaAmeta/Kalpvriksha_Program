#include <stdio.h>

void verticalmatrix(int matrix[][10], int row, int col)
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col / 2; colIndex++)
        {
            int temp = matrix[rowIndex][colIndex];
            matrix[rowIndex][colIndex] = matrix[rowIndex][col - colIndex - 1];
            matrix[rowIndex][col - colIndex - 1] = temp;
        }
    }
}

void horizontalmatrix(int matrix[][10], int row, int col)
{
    for (int rowIndex = 0; rowIndex < row / 2; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            int temp = matrix[rowIndex][colIndex];
            matrix[rowIndex][colIndex] = matrix[row - rowIndex - 1][colIndex];
            matrix[row - rowIndex - 1][colIndex] = temp;
        }
    }
}

void printMatrix(int matrix[][10], int row, int col)
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

    printf("Enter the rows and columns of the matrix: ");
    scanf("%d %d", &row, &col);

    int matrix[10][10];

    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            printf("Enter the element at [%d][%d]: ", rowIndex, colIndex);
            scanf("%d", &matrix[rowIndex][colIndex]);
        }
    }

    printf("Original Matrix:\n");
    printMatrix(matrix, row, col);

    horizontalmatrix(matrix, row, col);
    printf("Horizontally Flipped Matrix:\n");
    printMatrix(matrix, row, col);

    verticalmatrix(matrix, row, col);
    printf("Vertically Flipped Matrix:\n");
    printMatrix(matrix, row, col);

    return 0;
}

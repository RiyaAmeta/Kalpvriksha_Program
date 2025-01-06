#include <stdio.h>
#include <stdlib.h>

void matrixMultiplication(int **matrix1, int **matrix2, int **resultMatrix, int rowMatrix1, int columnMatrix1, int rowMatrix2, int columnMatrix2);
void inputMatrix(int **matrix, int rows, int cols);

int main()
{
    int rowMatrix1, columnMatrix1, rowMatrix2, columnMatrix2;

    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &rowMatrix1, &columnMatrix1);

    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &rowMatrix2, &columnMatrix2);

    if (columnMatrix1 != rowMatrix2)
    {
        printf("Matrix multiplication cannot be performed\n");
        return 1;
    }

    int **matrix1 = (int **)malloc(rowMatrix1 * sizeof(int *));
    int **matrix2 = (int **)malloc(rowMatrix2 * sizeof(int *));
    int **resultMatrix = (int **)malloc(rowMatrix1 * sizeof(int *));

    for (int row = 0; row < rowMatrix1; row++)
    {
        matrix1[row] = (int *)malloc(columnMatrix1 * sizeof(int));
        resultMatrix[row] = (int *)malloc(columnMatrix2 * sizeof(int));
    }

    for (int row = 0; row < rowMatrix2; row++)
    {
        matrix2[row] = (int *)malloc(columnMatrix2 * sizeof(int));
    }

    // Taking Matrix as input from the user
    printf("Enter first matrix\n");
    inputMatrix(matrix1, rowMatrix1, columnMatrix1);

    printf("Enter second matrix\n");
    inputMatrix(matrix2, rowMatrix2, columnMatrix2);

    // Matrix multiplication is performed
    matrixMultiplication(matrix1, matrix2, resultMatrix, rowMatrix1, columnMatrix1, rowMatrix2, columnMatrix2);

    // Output the resultant matrix
    printf("Resultant matrix:\n");
    for (int row = 0; row < rowMatrix1; row++)
    {
        for (int col = 0; col < columnMatrix2; col++)
        {
            printf("%5d", resultMatrix[row][col]);
        }
        printf("\n");
    }

    // Free up the allocated memory 
    for (int row = 0; row < rowMatrix1; row++)
    {
        free(matrix1[row]);
        free(resultMatrix[row]);
    }

    for (int row = 0; row < rowMatrix2; row++)
    {
        free(matrix2[row]);
    }

    free(matrix1);
    free(matrix2);
    free(resultMatrix);

    return 0;
}

// Function to input a matrix
void inputMatrix(int **matrix, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            printf("Enter number for matrix: ");
            scanf("%d", &matrix[row][col]);
        }
    }
}

// Function to perform matrix multiplication
void matrixMultiplication(int **matrix1, int **matrix2, int **resultMatrix, int rowMatrix1, int columnMatrix1, int rowMatrix2, int columnMatrix2)
{
    for (int row = 0; row < rowMatrix1; row++)
    {
        for (int col = 0; col < columnMatrix2; col++)
        {
            resultMatrix[row][col] = 0;
            for (int inner = 0; inner < columnMatrix1; inner++)
            {
                resultMatrix[row][col] += matrix1[row][inner] * matrix2[inner][col];
            }
        }
    }
}

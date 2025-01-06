#include <stdio.h>
#include <stdlib.h>

void matrixMultiplication(int **matrix1, int **matrix2, int **resultMatrix, int rowMatrix1, int columnMatrix1, int rowMatrix2, int columnMatrix2);
void inputMatrix(int **matrix, int rows, int cols);
int **allocateMemory(int rows, int cols);
void deallocateMemory(int **matrix, int rows);
void resultantMatrix(int **matrix, int rows, int cols);

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

    // Allocate memory for the matrices
    int **matrix1 = allocateMemory(rowMatrix1, columnMatrix1);
    int **matrix2 = allocateMemory(rowMatrix2, columnMatrix2);
    int **resultMatrix = allocateMemory(rowMatrix1, columnMatrix2);

    // Taking Matrix as input from the user
    printf("Enter first matrix\n");
    inputMatrix(matrix1, rowMatrix1, columnMatrix1);

    printf("Enter second matrix\n");
    inputMatrix(matrix2, rowMatrix2, columnMatrix2);

    // Matrix multiplication is performed
    matrixMultiplication(matrix1, matrix2, resultMatrix, rowMatrix1, columnMatrix1, rowMatrix2, columnMatrix2);

    // Output the resultant matrix
    printf("Resultant matrix:\n");
    resultantMatrix(resultMatrix, rowMatrix1, columnMatrix2);

    // Free up the allocated memory 
    deallocateMemory(matrix1, rowMatrix1);
    deallocateMemory(matrix2, rowMatrix2);
    deallocateMemory(resultMatrix, rowMatrix1);

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

// Function to allocate memory for a matrix
int **allocateMemory(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int row = 0; row < rows; row++)
    {
        matrix[row] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to deallocate memory for a matrix
void deallocateMemory(int **matrix, int rows)
{
    for (int row = 0; row < rows; row++)
    {
        free(matrix[row]);
    }
    free(matrix);
}

// Function to print a matrix
void resultantMatrix(int **matrix, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            printf("%5d", matrix[row][col]);
        }
        printf("\n");
    }
}

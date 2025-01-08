#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **data;
    int rows;
    int cols;
}Matrix;
void matrixMultiplication(Matrix *matrix1, Matrix *matrix2, Matrix *resultMatrix);
void inputMatrix(Matrix *matrix);
void allocateMemory(Matrix *matrix, int rows, int cols);
void deallocateMemory(Matrix *matrix);
void resultantMatrix(Matrix *matrix);

int main()
{
    Matrix matrix1, matrix2, resultMatrix;
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
    allocateMemory(&matrix1, rowMatrix1, columnMatrix1);
    allocateMemory(&matrix2, rowMatrix2, columnMatrix2);
    allocateMemory(&resultMatrix, rowMatrix1, columnMatrix2);

    // Taking Matrix as input from the user
    printf("Enter first matrix\n");
    inputMatrix(&matrix1);

    printf("Enter second matrix\n");
    inputMatrix(&matrix2);

    // Matrix multiplication is performed
    matrixMultiplication(&matrix1, &matrix2, &resultMatrix);

    // Output the resultant matrix
    printf("Resultant matrix:\n");
    resultantMatrix(&resultMatrix);

    // Free up the allocated memory 
    deallocateMemory(&matrix1);
    deallocateMemory(&matrix2);
    deallocateMemory(&resultMatrix);

    return 0;
}

// Function to input a matrix
void inputMatrix(Matrix *matrix)
{
    for (int row = 0; row < matrix->rows; row++)
    {
        for (int col = 0; col < matrix->cols; col++)
        {
            printf("Enter number for matrix: ");
            scanf("%d", &matrix->data[row][col]);
        }
    }
}

// Function to perform matrix multiplication
void matrixMultiplication(Matrix *matrix1, Matrix *matrix2, Matrix *resultMatrix)
{
    for (int row = 0; row < matrix1->rows; row++)
    {
        for (int col = 0; col < matrix2->cols; col++)
        {
            resultMatrix->data[row][col] = 0;
            for (int inner = 0; inner < matrix1->cols; inner++)
            {
                resultMatrix->data[row][col] += matrix1->data[row][inner] * matrix2->data[inner][col];
            }
        }
    }
}

// Function to allocate memory for a matrix
void allocateMemory(Matrix *matrix, int rows, int cols)
{
    matrix -> rows = rows;
    matrix -> cols = cols;
    matrix -> data = (int **)malloc(rows * sizeof(int *));
    for (int row = 0; row < rows; row++)
    {
        matrix-> data[row] = (int *)malloc(cols * sizeof(int));
    }
}

// Function to deallocate memory for a matrix
void deallocateMemory(Matrix *matrix)
{
    for (int row = 0; row < matrix->rows; row++)
    {
        free(matrix->data[row]);
    }
    free(matrix->data);
}

// Function to print a matrix
void resultantMatrix(Matrix *matrix)
{
    for (int row = 0; row < matrix->rows; row++)
    {
        for (int col = 0; col < matrix->cols; col++)
        {
            printf("%5d", matrix->data[row][col]);
        }
        printf("\n");
    }
}

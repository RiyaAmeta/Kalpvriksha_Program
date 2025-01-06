#include <stdio.h>
#include <stdlib.h>
void MatrixMultiplication(int **Matrix1, int **Matrix2, int **ResultMatrix, int RowMatrix1, int ColumnMatrix1, int RowMatrix2, int ColoumnMatrix2);
int main()
{
    int RowMatrix1, ColumnMatrix1, RowMatrix2, ColoumnMatrix2;
    printf("Enter number of rows and coloumn for first matrix:");
    scanf("%d %d", &RowMatrix1, &ColumnMatrix1);

    printf("Enter number of rows and coloumn for second matrix:");
    scanf("%d %d", &RowMatrix2, &ColoumnMatrix2);

    if (ColumnMatrix1 != RowMatrix2)
    {
        printf("Matrix multiplication cannot be performed\n");
        return 1;
    }

    int **Matrix1 = (int **)malloc(RowMatrix1 * sizeof(int *));
    int **Matrix2 = (int **)malloc(RowMatrix2 * sizeof(int *));
    int **ResultMatrix = (int **)malloc(RowMatrix1 * sizeof(int *));

    for (int i = 0; i < RowMatrix1; i++)
    {
        Matrix1[i] = (int *)malloc(ColumnMatrix1 * sizeof(int));
        ResultMatrix[i] = (int *)malloc(ColoumnMatrix2 * sizeof(int));
    }
    for (int i = 0; i < RowMatrix2; i++)
    {
        Matrix2[i] = (int *)malloc(ColoumnMatrix2 * sizeof(int));
    }
    printf("Enter first matrxi\n");
    for (int i = 0; i < RowMatrix1; i++)
    {
        for (int j = 0; j < ColumnMatrix1; j++)
        {
            printf("Enter number :");
            scanf("%d", &Matrix1[i][j]);
        }
    }
    printf("Enter secnd matrix\n");
    for (int i = 0; i < RowMatrix2; i++)
    {
        for (int j = 0; j < ColoumnMatrix2; j++)
        {
            printf("Enter number :");
            scanf("%d", &Matrix2[i][j]);
        }
    }

    MatrixMultiplication(Matrix1, Matrix2, ResultMatrix, RowMatrix1, ColumnMatrix1, RowMatrix2, ColoumnMatrix2);

    printf("Resultanat matrix :\n");
    for (int i = 0; i < RowMatrix1; i++)
    {
        for (int j = 0; j < ColoumnMatrix2; j++)
        {
            printf("%5d", ResultMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < RowMatrix1; i++)
    {
        free(Matrix1[i]);
        free(ResultMatrix[i]);
    }
    for (int i = 0; i < RowMatrix2; i++)
    {
        free(Matrix2[i]);
    }

    free(Matrix1);
    free(Matrix2);
    free(ResultMatrix);
    return 0;
}
void MatrixMultiplication(int **Matrix1, int **Matrix2, int **ResultMatrix, int RowMatrix1, int ColumnMatrix1, int RowMatrix2, int ColoumnMatrix2)
{
    for (int i = 0; i < RowMatrix1; i++)
    {
        for (int j = 0; j < ColoumnMatrix2; j++)
        {
            ResultMatrix[i][j] = 0;
            for (int k = 0; k < ColumnMatrix1; k++)
            {
                ResultMatrix[i][j] = ResultMatrix[i][j] + Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }
}
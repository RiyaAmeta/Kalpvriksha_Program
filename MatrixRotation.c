#include <stdio.h>

int row, coloumn, dimension;

void inputMatrix(int matrix[dimension][dimension]);
void rotateMatrix(int matrix[dimension][dimension], int result[dimension][dimension]);
void outputMatrix(int result[dimension][dimension]);

int main() 
{
    printf("Enter the dimension of the marix:\n");
    scanf("%d", &dimension);
    
    int matrix[dimension][dimension];
    int result[dimension][dimension];
    
    inputMatrix(matrix);
    rotateMatrix(matrix, result);
    
    printf("Rotated matrix:\n");
    outputMatrix(result);
    return 0;
}

//Function to take elements of matrix as input from user 
void inputMatrix(int matrix[dimension][dimension])
{
    for(int row = 0; row < dimension; row++)
    {
        for(int coloumn = 0; coloumn < dimension; coloumn++)
        {
            printf("Enter the element %d,%d:", row, coloumn);
            scanf("%d", &matrix[row][coloumn]);
        }
    }
}

//Function for clockwise rotation of matrix by 90 degree 
void rotateMatrix(int matrix[dimension][dimension], int result[dimension][dimension])
{
    for(int row = 0; row < dimension; row++)
    {
        for(int coloumn = 0; coloumn < dimension; coloumn++)
        {
            result[coloumn][dimension-1-row] = matrix[row][coloumn];
        }
    }
}

//Function to outpiut the rotated matrix
void outputMatrix(int result[dimension][dimension])
{
    for(int row = 0; row < dimension; row++){
        for(int j = 0; j < dimension; j++){
            printf("%d ",result[row][j]);
        }
        printf("\n");
    }
}

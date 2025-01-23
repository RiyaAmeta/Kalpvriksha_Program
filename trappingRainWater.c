#include <stdio.h>

void leftMax(int row, int col, int matrix[row][col], int left[row][col])
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        left[rowIndex][0] = matrix[rowIndex][0];
        for (int colIndex = 1; colIndex < col; colIndex++)
        {
            int max = left[rowIndex][colIndex - 1];
            if (max > matrix[rowIndex][colIndex])
            {
                left[rowIndex][colIndex] = max;
                continue;
            }
            else
            {
                left[rowIndex][colIndex] = matrix[rowIndex][colIndex];
                continue;
            }
        }
    }
}

void rightMax(int row, int col, int matrix[row][col], int right[row][col])
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        right[rowIndex][col - 1] = matrix[rowIndex][col - 1];
        for (int colIndex = col - 2; colIndex >= 0; colIndex--)
        {
            int max = right[rowIndex][colIndex + 1];
            if (max > matrix[rowIndex][colIndex])
            {
                right[rowIndex][colIndex] = right[rowIndex][colIndex + 1];
                continue;
            }
            else
            {
                right[rowIndex][colIndex] = matrix[rowIndex][colIndex];
                continue;
            }
        }
    }
}
void topMax(int row, int col, int matrix[row][col], int top[row][col])
{
    for (int colIndex = 0; colIndex < col; colIndex++)
    {
        top[0][colIndex] = matrix[0][colIndex];
        for (int rowIndex = 1; rowIndex < row; rowIndex++)
        {
            int max = top[rowIndex - 1][colIndex];
            if (max > matrix[rowIndex][colIndex])
            {
                top[rowIndex][colIndex] = top[rowIndex - 1][colIndex];
                continue;
            }
            else
            {
                top[rowIndex][colIndex] = matrix[rowIndex][colIndex];
                continue;
            }
        }
    }
}

void bottomMax(int row, int col, int matrix[row][col], int bottom[row][col])
{
    for (int colIndex = 0; colIndex < col; colIndex++)
    {
        bottom[row - 1][colIndex] = matrix[row - 1][colIndex];
        for (int rowIndex = row - 2; rowIndex >= 0; rowIndex--)
        {
            int max = bottom[rowIndex + 1][colIndex];
            if (max > matrix[rowIndex][colIndex])
            {
                bottom[rowIndex][colIndex] = bottom[rowIndex + 1][colIndex];
                continue;
            }
            else
            {
                bottom[rowIndex][colIndex] = matrix[rowIndex][colIndex];
                continue;
            }
        }
    }
}
int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    int matrix[row][col];

    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            scanf("%d", &matrix[rowIndex][colIndex]);
        }
    }
    int left[row][col], right[row][col], top[row][col], bottom[row][col];

    leftMax(row, col, matrix, left);
    rightMax(row, col, matrix, right);
    topMax(row, col, matrix, top);
    bottomMax(row, col, matrix, bottom);

    int trapped = 0;
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int colIndex = 0; colIndex < col; colIndex++)
        {
            int minWater = left[rowIndex][colIndex];
            if (minWater < right[rowIndex][colIndex])
            {
                minWater = right[rowIndex][colIndex];
            }
            if (minWater < top[rowIndex][colIndex])
            {
                minWater = top[rowIndex][colIndex];
            }
            if (minWater < bottom[rowIndex][colIndex])
            {
                minWater = bottom[rowIndex][colIndex];
            }

            if (minWater > matrix[rowIndex][colIndex])
            {
                trapped += (minWater - matrix[rowIndex][colIndex]);
            }
        }
    }
    printf("%d\n", trapped);
    return 0;
}

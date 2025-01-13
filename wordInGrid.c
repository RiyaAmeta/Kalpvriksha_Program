#include <stdio.h>
#include <string.h>

int wordIndex = 0;
int findMatch(char grid[][100], int row, int col, char *word, int rowIndex, int colIndex)
{
    int wordLength = strlen(word);
    if (word[wordIndex] == '\0')
    {
        return 1;
    }

    if (rowIndex < 0 || colIndex < 0 || rowIndex >= row || colIndex >= col || grid[rowIndex][colIndex] != word[wordIndex])
    {
        return 0;
    }

    char temp = grid[rowIndex][colIndex];
    grid[rowIndex][colIndex] = '0';

    wordIndex++;

    int result = findMatch(grid, row, col, word, rowIndex - 1, colIndex) ||
              findMatch(grid, row, col, word, rowIndex + 1, colIndex) ||
              findMatch(grid, row, col, word, rowIndex, colIndex - 1) ||
              findMatch(grid, row, col, word, rowIndex, colIndex + 1) || 
              findMatch(grid, row, col, word, rowIndex - 1, colIndex-1) ||
              findMatch(grid, row, col, word, rowIndex - 1, colIndex+1) ||
              findMatch(grid, row, col, word, rowIndex + 1, colIndex-1) ||
              findMatch(grid, row, col, word, rowIndex + 1, colIndex+1);

    grid[rowIndex][colIndex] = temp;
    wordIndex--;
    return result;
}

int wordExist(char grid[][100], int row, int col, char *word)
{
    int wordLength = strlen(word);

    if (wordLength > row * col)
    {
        return 0;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == word[0])
            {
                if (findMatch(grid, row, col, word, i, j))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int row, col;
    char word[100];

    printf("Enter the row of matrix:");
    scanf("%d", &row);
    printf("Enter the coloumn of matrix:");
    scanf("%d", &col);
    char grid[100][100];
    printf("Enter the word to find in the grid:");
    scanf("%s", word);

    for (int rIndex = 0; rIndex < row; rIndex++)
    {
        for (int cIndex = 0; cIndex < col; cIndex++)
        {
            printf("Enter character at [%d][%d]:", rIndex, cIndex);
            scanf(" %c", &grid[rIndex][cIndex]);
        }
    }

    if (wordExist(grid, row, col, word))
    {
        printf("Word Found\n");
    }
    else
    {
        printf("Word not found in the grid.\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int findMatch(char grid[][100], int n, int m, char *word, int x, int y, int wordIndex)
{
    int wordLength = strlen(word);
    if (wordIndex == wordLength)
    {
        return 1;
    }

    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != word[wordIndex])
    {
        return 0;
    }

    char temp = grid[x][y];
    grid[x][y] = '0';

    int res = findMatch(grid, n, m, word, x - 1, y, wordIndex + 1) ||
              findMatch(grid, n, m, word, x + 1, y, wordIndex + 1) ||
              findMatch(grid, n, m, word, x, y - 1, wordIndex + 1) ||
              findMatch(grid, n, m, word, x, y + 1, wordIndex + 1);

    grid[x][y] = temp;
    return res;
}

int wordExist(char grid[][100], int n, int m, char *word)
{
    int wordLength = strlen(word);

    if (wordLength > n * m)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == word[0])
            {
                if (findMatch(grid, n, m, word, i, j, 0))
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

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter character at [%d][%d]:", i, j);
            scanf(" %c", &grid[i][j]);
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

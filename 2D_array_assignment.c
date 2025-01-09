#include <stdio.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 101
#define MAX_NAME_LENGTH 51

int inputValidation(int rows, int columns);
void inputNames(char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns);
int outputVowelNameCount(char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns);
void outputLongestName(char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns, char longestName[MAX_NAME_LENGTH]);
void printNameMatrix(char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns);

int main()
{
    int rows, columns;
    char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH];
    char longestName[MAX_NAME_LENGTH] = "";
    int vowelCount = 0;

    printf("Enter number of rows between 1 to %d: ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns between 1 to %d: ", MAX_COLUMNS);
    scanf("%d", &columns);

    if (!inputValidation(rows, columns))
    {
        return 1;
    }

    inputNames(names, rows, columns);

    vowelCount = outputVowelNameCount(names, rows, columns);
    outputLongestName(names, rows, columns, longestName);
    printNameMatrix(names, rows, columns);

    printf("Number of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name: %s\n", longestName);

    return 0;
}

int inputValidation(int rows, int columns)
{
    if (rows < 1 || rows > MAX_ROWS || columns < 1 || columns > MAX_COLUMNS)
    {
        printf("Wrong input, the entered value is outside the constraint limit 1 to %d for rows and 1 to %d for columns.\n", MAX_ROWS, MAX_COLUMNS);
        return 0;
    }
    return 1;
}

void inputNames(char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns)
{
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
        }
    }
}

int outputVowelNameCount(char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            char firstChar = names[i][j][0];
            if (firstChar == 'A' || firstChar == 'E' || firstChar == 'I' || firstChar == 'O' || firstChar == 'U' ||
                firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u')
            {
                count++;
            }
        }
    }
    return count;
}

void outputLongestName(char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns, char longestName[MAX_NAME_LENGTH])
{
    int maxLength = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int currentLength = 0;

            while (names[i][j][currentLength] != '\0')
            {
                currentLength++;
            }

            if (currentLength > maxLength)
            {
                maxLength = currentLength;

                int k = 0;
                while (names[i][j][k] != '\0')
                {
                    longestName[k] = names[i][j][k];
                    k++;
                }
                longestName[k] = '\0';
            }
        }
    }
}

void printNameMatrix(char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns)
{
    printf("The 2D array of names is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }
}

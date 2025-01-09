#include <stdio.h>
#include <string.h>
 
#define MAX_ROWS 10
#define MAX_COLUMNS 101
#define MAX_NAME_LENGTH 51
 
int inputValidation(int rows, int columns);
void inputNames(char studentNames[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns);
int outputVowelNameCount(char studentNames[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns);
void outputLongestName(char studentNames[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns, char longestName[MAX_NAME_LENGTH]);
void printNameMatrix(char studentNames[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns);
 
int main() {
    int rows, columns;
    char studentNames[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH];
    char longestName[MAX_NAME_LENGTH] = "";
 
    printf("Enter number of rows between 1 to %d: ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns between 1 to %d: ", MAX_COLUMNS);
    scanf("%d", &columns);
 
    if (!inputValidation(rows, columns)) {
        return 1;
    }
 
    inputNames(studentNames, rows, columns);
 
    int vowelCount = outputVowelNameCount(studentNames, rows, columns);
 
    outputLongestName(studentNames, rows, columns, longestName);
 
    printNameMatrix(studentNames, rows, columns);
 
    printf("Number of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name: %s\n", longestName);
 
    return 0;
}
 
int inputValidation(int rows, int columns) {
    if (rows < 1 || rows > MAX_ROWS || columns < 1 || columns > MAX_COLUMNS) {
        printf("Wrong input, the entered value is outside the constraint limit 1 to %d for rows and 1 to %d for columns.\n", MAX_ROWS, MAX_COLUMNS);
        return 0;
    }
    return 1;
}
 
void inputNames(char studentNames[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns) {
    printf("Enter the names:\n");
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++) {
            printf("Name at (%d,%d): ", rowIndex, columnIndex);
            scanf("%s", studentNames[rowIndex][columnIndex]);
        }
    }
}
 
int outputVowelNameCount(char studentNames[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns) {
    int vowelCount = 0;
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++) {
            char firstChar = studentNames[rowIndex][columnIndex][0];
            if (firstChar == 'A' || firstChar == 'E' || firstChar == 'I' || firstChar == 'O' || firstChar == 'U' ||
                firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') {
                vowelCount++;
            }
        }
    }
    return vowelCount;
}
 
void outputLongestName(char studentNames[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns, char longestName[MAX_NAME_LENGTH]) {
    int maxLength = 0;
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++) {
            int currentLength = strlen(studentNames[rowIndex][columnIndex]);
            if (currentLength > maxLength) {
                maxLength = currentLength;
                strcpy(longestName, studentNames[rowIndex][columnIndex]);
            }
        }
    }
}
 
void printNameMatrix(char studentNames[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH], int rows, int columns) {
    printf("The 2D array of names is:\n");
    for (int rowIndex = 0; rowIndex < rows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++) {
            printf("%s ", studentNames[rowIndex][columnIndex]);
        }
        printf("\n");
    }
}

#include <stdio.h>
#include <string.h>
 
#define MAX_ROWS 10
#define MAX_COLUMNS 101
#define MAX_NAME_LENGTH 51
 
typedef struct {
    int rows;
    int columns;
} MatrixDimensions;
 
typedef struct {
    char names[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH];
    char longestName[MAX_NAME_LENGTH];
    int vowelCount;
} StudentMatrix;
 
int inputValidation(MatrixDimensions dims);
void inputNames(StudentMatrix *matrix, MatrixDimensions dims);
int outputVowelNameCount(StudentMatrix *matrix, MatrixDimensions dims);
void outputLongestName(StudentMatrix *matrix, MatrixDimensions dims);
void printNameMatrix(StudentMatrix *matrix, MatrixDimensions dims);
 
int main() {
    MatrixDimensions dims;
    StudentMatrix matrix = { .vowelCount = 0, .longestName = "" };
 
    printf("Enter number of rows between 1 to %d: ", MAX_ROWS);
    scanf("%d", &dims.rows);
    printf("Enter number of columns between 1 to %d: ", MAX_COLUMNS);
    scanf("%d", &dims.columns);
 
    if (!inputValidation(dims)) {
        return 1;
    }
 
    inputNames(&matrix, dims);
 
    matrix.vowelCount = outputVowelNameCount(&matrix, dims);
 
    outputLongestName(&matrix, dims);
 
    printNameMatrix(&matrix, dims);
 
    printf("Number of names starting with a vowel: %d\n", matrix.vowelCount);
    printf("The longest name: %s\n", matrix.longestName);
 
    return 0;
}
 
int inputValidation(MatrixDimensions dims) {
    if (dims.rows < 1 || dims.rows > MAX_ROWS || dims.columns < 1 || dims.columns > MAX_COLUMNS) {
        printf("Wrong input, the entered value is outside the constraint limit 1 to %d for rows and 1 to %d for columns.\n", MAX_ROWS, MAX_COLUMNS);
        return 0;
    }
    return 1;
}
 
void inputNames(StudentMatrix *matrix, MatrixDimensions dims) {
    printf("Enter the names:\n");
    for (int rowIndex = 0; rowIndex < dims.rows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < dims.columns; columnIndex++) {
            printf("Name at (%d,%d): ", rowIndex, columnIndex);
            scanf("%s", matrix->names[rowIndex][columnIndex]);
        }
    }
}
 
int outputVowelNameCount(StudentMatrix *matrix, MatrixDimensions dims) {
    int vowelCount = 0;
    for (int rowIndex = 0; rowIndex < dims.rows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < dims.columns; columnIndex++) {
            char firstChar = matrix->names[rowIndex][columnIndex][0];
            if (firstChar == 'A' || firstChar == 'E' || firstChar == 'I' || firstChar == 'O' || firstChar == 'U' ||
                firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') {
                vowelCount++;
            }
        }
    }
    return vowelCount;
}
 
void outputLongestName(StudentMatrix *matrix, MatrixDimensions dims) {
    int maxLength = 0;
    for (int rowIndex = 0; rowIndex < dims.rows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < dims.columns; columnIndex++) {
            int currentLength = strlen(matrix->names[rowIndex][columnIndex]);
            if (currentLength > maxLength) {
                maxLength = currentLength;
                strcpy(matrix->longestName, matrix->names[rowIndex][columnIndex]);
            }
        }
    }
}
 
void printNameMatrix(StudentMatrix *matrix, MatrixDimensions dims) {
    printf("The 2D array of names is:\n");
    for (int rowIndex = 0; rowIndex < dims.rows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < dims.columns; columnIndex++) {
            printf("%s ", matrix->names[rowIndex][columnIndex]);
        }
        printf("\n");
    }
}

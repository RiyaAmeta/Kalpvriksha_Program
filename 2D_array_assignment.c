#include <stdio.h>
#include<string.h>

int rows, coloumns;
char studentNames[10][101][51];
int vowelCount =0;
char longestName[51] = "";
int maxLength = 0;

int inputValidation();
void inputNames();
int outputVowelNameCount();
void outputLongestName();
void printNameMatrix();

int main() 
{
    printf("Enter number of rows between 1 to 10:");
    scanf("%d", &rows);
    printf("Enter number of coloumns between 1 to 101:");
    scanf("%d", &coloumns);
    
    if(!inputValidation)
    {
        return 1;
    }
    
    inputNames();
    int vcnt = outputVowelNameCount();
    outputLongestName();
    printNameMatrix();
     
    printf("Number of names starting with a vowel:%d\n",vcnt);
    printf("The longest name: %s\n",longestName);
    
    return 0;
}
int inputValidation()
{
    if(rows < 1 || rows > 10)
    {
        printf("Wrong input, the entered value is outside the constraint limit 1 to 10.\n");
        return 0;
    }
    if(coloumns < 1 || coloumns > 101)
    {
        printf("Wrong input, the entered value is outside the constraint limit 1 to 101.\n");
        return 0;
    }
    return 1;
}
void inputNames()
{
    printf("Enter the names:\n");
    for(int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for(int coloumnIndex = 0; coloumnIndex < coloumns; coloumnIndex++)
        {
            printf("Name at (%d,%d):", rowIndex, coloumnIndex);
            scanf("%s",studentNames[rowIndex][coloumnIndex]);
        }
    }
}
int outputVowelNameCount()
{
    vowelCount = 0;
    for(int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for(int coloumnIndex = 0; coloumnIndex < coloumns; coloumnIndex++)
        {
            if(studentNames[rowIndex][coloumnIndex][0] == 'A' || studentNames[rowIndex][coloumnIndex][0] == 'E' || studentNames[rowIndex][coloumnIndex][0] == 'I' || studentNames[rowIndex][coloumnIndex][0] == 'O' || studentNames[rowIndex][coloumnIndex][0] == 'U' || studentNames[rowIndex][coloumnIndex][0] == 'a' || studentNames[rowIndex][coloumnIndex][0] == 'e' || studentNames[rowIndex][coloumnIndex][0] == 'i' || studentNames[rowIndex][coloumnIndex][0] == 'o' || studentNames[rowIndex][coloumnIndex][0] == 'u')
            {
                vowelCount++;
            }
        }
    }
    return vowelCount;
}
void outputLongestName()
{
    maxLength = 0;
    for(int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for(int coloumnIndex = 0; coloumnIndex < coloumns; coloumnIndex++)
        {
            int currentLength = strlen(studentNames[rowIndex][coloumnIndex]);
            if(currentLength > maxLength)
            {
                maxLength = currentLength;
                strcpy(longestName, studentNames[rowIndex][coloumnIndex]);
            }
        }
    }
}
void printNameMatrix()
{
    printf("The 2D array of names is:\n");
    for(int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for(int coloumnIndex = 0; coloumnIndex < coloumns; coloumnIndex++)
        {
            printf("%s ",studentNames[rowIndex][coloumnIndex]);
        }
        printf("\n");
    }
}

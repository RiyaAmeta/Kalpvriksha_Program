#include <stdio.h>
#include <string.h>

void concatinateString(char string1[], char string2[])
{
    int string1Index = 0;
    int string2Index = 0;

    while (string1[string1Index] != '\0')
    {
        string1Index++;
    }

    string1[string1Index] = ' ';
    string1Index++;

    while (string2[string2Index] != '\0')
    {
        string1[string1Index] = string2[string2Index];
        string1Index++;
        string2Index++;
    }

    string1[string1Index] = '\0';
}

int main()
{
    char string1[200];
    char string2[100];

    printf("Enter string 1: ");
    fgets(string1, 100, stdin);
    string1[strcspn(string1, "\n")] = '\0';

    printf("Enter string 2: ");
    fgets(string2, 100, stdin);
    string2[strcspn(string2, "\n")] = '\0';

    concatinateString(string1, string2);

    printf("Concatenated String: %s\n", string1);

    return 0;
}

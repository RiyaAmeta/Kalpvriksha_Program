#include <stdio.h>
#include <string.h>

int calculateStringLength(char str[]);
int subStringPalindrome(char str[], int startIndex, int endIndex);
void longestPalindrome(char str[], int *length);

int main()
{
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);
    int length = calculateStringLength(inputString);
    longestPalindrome(inputString, &length);
    return 0;
}

int calculateStringLength(char str[])
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int subStringPalindrome(char str[], int startIndex, int endIndex)
{
    while (startIndex < endIndex)
    {
        if (str[startIndex] != str[endIndex])
        {
            return 0;
        }
        startIndex++;
        endIndex--;
    }
    return 1;
}

void longestPalindrome(char str[], int *length)
{
    int maxlength = 1;
    int startofPalindrome = 0;

    for (int start = 0; start < *length; start++)
    {
        for (int end = start; end < *length; end++)
        {
            if (subStringPalindrome(str, start, end))
            {
                int currentLength = end - start + 1;
                if (currentLength > maxlength)
                {
                    maxlength = currentLength;
                    startofPalindrome = start;
                }
            }
        }
    }
    printf("Longest Palindrome  substring is: ");
    for (int i = startofPalindrome; i < startofPalindrome + maxlength; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

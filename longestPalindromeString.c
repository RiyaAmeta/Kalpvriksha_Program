#include <stdio.h>
#include <string.h>

int subStringPalindrome(char str[], int startIndex, int endIndex);
void longestPalindrome(char str[]);

int main()
{
    char inputString[100];
    printf("Enter a string: ");
    scanf("%s", inputString);
    longestPalindrome(inputString);
    return 0;
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

void longestPalindrome(char str[])
{
    int maxlength = 1;
    int startofPalindrome = 0;
    int stringLenght = strlen(str);

    for (int start = 0; start < stringLenght; start++)
    {
        for (int end = start; end < stringLenght; end++)
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

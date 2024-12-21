#include <stdio.h>
#include <string.h>
#include <ctype.h>
void DMAS_Calculator(char *math_expression);
int main()
{
    char math_expression[100];
    int count = 0;

    printf("Enter an mathematical expression: ");
    fgets(math_expression, 100, stdin);
    math_expression[strcspn(math_expression, "\n")] = '\0';
    for (int i = 0; math_expression[i] != '\0'; i++)
    {
        if (math_expression[i] != ' ')
        {
            math_expression[count++] = math_expression[i];
        }
    }
    math_expression[count] = '\0';
    int string_length = strlen(math_expression);
    for (int i = 0; i < string_length; i++)
    {
        char ch = math_expression[i];
        if (!isdigit(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/')
        {
            printf("Error: Invalid expression\n");
            return 0;
        }
    }
    DMAS_Calculator(math_expression);
    return 0;
}
void DMAS_Calculator(char *math_expression)
{
    int string_length = strlen(math_expression);
    for (int i = 0; i < string_length; i++)
    {
        if (math_expression[i] == '*' || math_expression[i] == '/')
        {
            int a = math_expression[i - 1] - '0';
            int b = math_expression[i + 1] - '0';
            int result;
            if (math_expression[i] == '*')
            {
                result = a * b;
            }
            if (math_expression[i] == '/')
            {
                result = a / b;
            }
            char temp[10];
            sprintf(temp, "%d", result);

            int j = i - 1;
            for (int k = 0; temp[k] != '\0'; j++, k++)
            {
                math_expression[j] = temp[k];
            }
            for (int k = i + 2; k < string_length; j++, k++)
            {
                math_expression[j] = math_expression[k];
            }
            math_expression[j] = '\0';
            string_length = strlen(math_expression);
            i = -1;
        }
    }

    for (int i = 0; i < string_length; i++)
    {
        if (math_expression[i] == '+' || math_expression[i] == '-')
        {
            int a = math_expression[i - 1] - '0';
            int b = math_expression[i + 1] - '0';
            int result;
            if (math_expression[i] == '+')
            {
                result = a + b;
            }
            if (math_expression[i] == '-')
            {
                result = a - b;
            }
            char temp[10];
            sprintf(temp, "%d", result);

            int j = i - 1;
            for (int k = 0; temp[k] != '\0'; j++, k++)
            {
                math_expression[j] = temp[k];
            }
            for (int k = i + 2; k < string_length; j++, k++)
            {
                math_expression[j] = math_expression[k];
            }
            math_expression[j] = '\0';
            string_length = strlen(math_expression);
            i = -1;
        }
    }
    printf("The answer for the math_expression is: %s\n", math_expression);
}

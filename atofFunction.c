#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include<ctype.h>
 
void removeExtraSpace(char *str){
    int start =0;
    int stringIndex =0;
    while (str[start] == ' ' || str[start] == '\t')
    {
        start++;
    }
    for(stringIndex =0; str[stringIndex] != '\0'; stringIndex++, start++){
        str[stringIndex] = str[start];
    }
    str[stringIndex] = '\0';
    
}
double atofFunction(char *str)
{
    char stringChar;
    int stringIndex = 0;
    int decimalCount = 0;
    int decimalFlag = 0;
    double value = 0.0;
    int exponentFlag =0;
    double exponent =0.0;
    int sign = 1;

    if(str[stringIndex] == '+' || str[stringIndex] == '-'){
        if(str[stringIndex] == '='){
            sign = -1;
        }
        stringIndex++;
    }

    while ((stringChar = str[stringIndex]) != '\0')
    {
        if (stringChar >= '0' && stringChar <= '9')
        {
 
            value = (value * 10) + (stringChar - '0');
            if (decimalFlag == 1)
            {
                decimalCount++;
            }
        }
        else if (stringChar == '.')
        {
            if (decimalFlag == 1)
            {
                return 0;
            }
            decimalFlag = 1;
        }
        else if(tolower(stringChar) == 'e'){
            exponentFlag = 1;
            stringIndex++;
            break;
        }
        else
        {
            return 0;
        }
        stringIndex++;
    }
 
    if(exponentFlag){
        int expValue = 0;
        int sign = 1;
        if(str[stringIndex] == '+' || str[stringIndex] == '-'){
            if(str[stringIndex] == '='){
                sign = -1;
        }
        stringIndex++;
    }
        while (str[stringIndex] >= '0' && str[stringIndex] <= '9')
        {
            expValue = (expValue*10) + (str[stringIndex] - '0');
            stringIndex++;
        }
        exponent = expValue * sign;
        value = value * pow(10, exponent);
        
    }
 
    value = value * pow(10, -decimalCount);
    return value;
}
 
int main()
{
    char str[100];
    printf("Enter a string of floating point numbers:\n");
    scanf("%s", str);
 
    removeExtraSpace(str);
    double result = atofFunction(str);
    printf("%lf", result);
}


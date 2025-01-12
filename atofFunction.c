#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include<ctype.h>
 
void removeExtraSpace(char *str){
    int start =0;
    int i =0;
    while (str[start] == ' ' || str[start] == '\t')
    {
        start++;
    }
    for(i =0; str[i] != '\0'; i++, start++){
        str[i] = str[start];
    }
    str[i] = '\0';
    
}
double atofFunction(char *str)
{
    char c;
    int i = 0;
    int j = 0;
    int flag = 0;
    double value = 0.0;
    int exp =0;
    double exponent =0.0;
    while ((c = str[i]) != '\0')
    {
        if (c >= '0' && c <= '9')
        {
 
            value = (value * 10) + (c - '0');
            if (flag == 1)
            {
                j++;
            }
        }
        else if (c == '.')
        {
            if (flag == 1)
            {
                return 0;
            }
            flag = 1;
        }
        else if(tolower(c) == 'e'){
            exp =1;
            i++;
            break;
        }
        else
        {
            return 0;
        }
        i++;
    }
 
    if(exp){
        while ((isdigit(str[i])))
        {
            exponent = (exponent*10) + (str[i] - '0');
            i++;
        }
        value = value * pow(10, exponent);
        
    }
 
    value = value * pow(10, -j);
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

#include<stdio.h>
#include <string.h>
void addition_subtraction(char *exp);
int main(){
    char exp[100];
    int cnt =0;
    int len = strlen(exp);
    printf("Enter an expression: ");
    fgets(exp, 100, stdin);
    exp[strcspn(exp, "\n")] = '\0';
    for(int i =0; exp[i] !='\0' ;i++){
        if(exp[i] != ' '){
            exp[cnt++]=exp[i];
    }
    }
    exp[cnt] ='\0';
    addition_subtraction(exp);
}
void addition_subtraction(char *exp){ 

    int len = strlen(exp);  
    for(int i=0;i<len;i++){
        if(exp[i]!= '*'&&exp[i]!='+'&&exp[i]!='-'&&exp[i]!='/'&&exp[i]!='0'&&exp[i]!='1'&&exp[i]!='2'&&exp[i]!='3'&&exp[i]!='4'&&exp[i]!='5'&&exp[i]!='6'&&exp[i]!='7'&&exp[i]!='8'&&exp[i]!='9'){
            printf("Error: Invalid expression\n");
            return;
        }
    }
    for(int i =0;i<len;i++){
        if(exp[i]=='*'|| exp[i]=='/'){
            int a = exp[i-1] -'0';
            int b = exp[i+1] -'0';
            int result;
            if(exp[i]=='*'){
                result = a*b;
            }
            if(exp[i]=='/'){
                result = a/b;
            }
            char temp[10];
            sprintf(temp, "%d", result);

            int j = i-1;
            for(int k =0; temp[k] !='\0';j++,k++){
                exp[j] = temp[k];
            }
            for(int k =i+2;k<len;j++,k++){
                exp[j] = exp[k];
            }
            exp[j] = '\0';
            len = strlen(exp);
            i =-1;
        }
    }
        

    for(int i=0;i<len;i++){
        if(exp[i]=='+'|| exp[i]=='-'){
            int a = exp[i-1] -'0';
            int b = exp[i+1] -'0';
            int result;
            if(exp[i]=='+'){
                result = a+b;
            }
            if(exp[i]=='-'){
                result = a-b;
            }
            char temp[10];
            sprintf(temp, "%d", result);

            int j = i-1;
            for(int k =0; temp[k] !='\0';j++,k++){
                exp[j] = temp[k];
            }
            for(int k =i+2;k<len;j++,k++){
                exp[j] = exp[k];
            }
            exp[j] = '\0';
            len = strlen(exp);
            i =-1;
        }
    }
    printf("The answer for the exp is: %s\n",exp);
}

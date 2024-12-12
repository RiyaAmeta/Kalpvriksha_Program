#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>       
#include <string.h>

#define MAX_TOKENS 100  

typedef struct {
    int type;     
    int value;    
    char op;      
} Token;               


int tokenize(const char *expression, Token tokens[]) {             
    int num = 0;
    int numFound = 0;
    int tokenCount = 0;

    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            num = num * 10 + (expression[i] - '0');  
            numFound = 1;
        } else {
            if (numFound) {
                tokens[tokenCount].type = 0;
                tokens[tokenCount++].value = num;
                num = 0;
                numFound = 0;
            }
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
                tokens[tokenCount].type = 1;
                tokens[tokenCount++].op = expression[i];
            }
        }
    }

    if (numFound) {
        tokens[tokenCount].type = 0;
        tokens[tokenCount++].value = num;
    }

    return tokenCount;
}

int evaluate_multiplication_division(Token tokens[], int *tokenCount) {
    for (int i = 0; i < *tokenCount; i++) {
        if (tokens[i].type == 1 && (tokens[i].op == '*' || tokens[i].op == '/')) {
            int result;
            if (tokens[i].op == '*') {
                result = tokens[i - 1].value * tokens[i + 1].value;
            } else {
                if (tokens[i + 1].value == 0) {
                    printf("Error: Division by zero.\n");
                    exit(1);
                }
                result = tokens[i - 1].value / tokens[i + 1].value;
            }
            tokens[i - 1].value = result;

            for (int j = i; j < *tokenCount - 2; j++) {
                tokens[j] = tokens[j + 2];
            }
            *tokenCount -= 2;
            i--;  
        }
    }
    return 0;
}

int evaluate_addition_subtraction(Token tokens[], int *tokenCount) {
    for (int i = 0; i < *tokenCount; i++) {
        if (tokens[i].type == 1 && (tokens[i].op == '+' || tokens[i].op == '-')) {
            int result;
            if (tokens[i].op == '+') {
                result = tokens[i - 1].value + tokens[i + 1].value;
            } else {
                result = tokens[i - 1].value - tokens[i + 1].value;
            }
            tokens[i - 1].value = result;

            for (int j = i; j < *tokenCount - 2; j++) {
                tokens[j] = tokens[j + 2];
            }
            *tokenCount -= 2;
            i--;  
        }
    }
    return 0;
}

int main() {
    char expression[100];
    printf("Enter a mathematical expression: ");
    fgets(expression, 100, stdin);
    expression[strcspn(expression, "\n")] = '\0';  

    Token tokens[MAX_TOKENS];
    int tokenCount = tokenize(expression, tokens);

    evaluate_multiplication_division(tokens, &tokenCount);

    evaluate_addition_subtraction(tokens, &tokenCount);

    if (tokenCount == 1 && tokens[0].type == 0) {
        printf("Result: %d\n", tokens[0].value);
    } else {
        printf("Error: Invalid expression.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    char expression[50];
    int stack[50];
    int top = -1;

    // Read the postfix expression
    fgets(expression, sizeof(expression), stdin);

    char *token = expression;

    while (*token != '\0') {

        // Skip spaces
        if (*token == ' ') {
            token++;
            continue;
        }

        // If operand
        if (*token >= '0' && *token <= '9') {
            int num = 0;

            while (*token >= '0' && *token <= '9') {
                num = num * 10 + (*token - '0');
                token++;
            }

            stack[++top] = num;
        }

        // If operator
        else {
            int b = stack[top--];
            int a = stack[top--];

            switch (*token) {
                case '+':
                    stack[++top] = a + b;
                    break;

                case '-':
                    stack[++top] = a - b;
                    break;

                case '*':
                    stack[++top] = a * b;
                    break;

                case '/':
                    stack[++top] = a / b;
                    break;
            }

            token++;
        }
    }

    printf("%d", stack[top]);

    return 0;
}
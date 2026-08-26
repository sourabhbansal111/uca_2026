#include <stdio.h>
#include <stdbool.h>

bool balancedParenthesis(char expression[]) {
    char stack[30];
    int top = -1;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }

        // Closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1)
                return false;

            if ((ch == ')' && stack[top] != '(') ||
                (ch == '}' && stack[top] != '{') ||
                (ch == ']' && stack[top] != '[')) {
                return false;
            }

            top--;
        }
    }

    return top == -1;
}

int main() {
    char expression[31];

    scanf("%30s", expression);

    if (balancedParenthesis(expression))
        printf("true");
    else
        printf("false");

    return 0;
}
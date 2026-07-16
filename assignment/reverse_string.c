#include <stdio.h>

void reverse_string(char *str) {
    int length = 0;

    // Find the length of the string
    while (str[length] != '\0') {
        length++;
    }

    // Reverse the string in-place
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char str[] = "Data Structures";

    reverse_string(str);

    printf("%s\n", str);

    return 0;
}
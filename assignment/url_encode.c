#include <stdio.h>

void url_encode(char *str, int true_length) {
    int space_count = 0;

    // Count spaces in the true string
    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ') {
            space_count++;
        }
    }

    // Calculate new length
    int new_length = true_length + space_count * 2;
    str[new_length] = '\0';

    // Work backwards to replace spaces in-place
    for (int i = true_length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[new_length - 1] = '0';
            str[new_length - 2] = '2';
            str[new_length - 3] = '%';
            new_length -= 3;
        } else {
            str[new_length - 1] = str[i];
            new_length--;
        }
    }
}

int main() {
    char str[50] = "Hello World";

    url_encode(str, 11);

    printf("%s\n", str);

    return 0;
}
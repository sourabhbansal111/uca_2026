#include <stdio.h>

int main() {
    int c, next;

    int in_single_comment = 0;
    int in_multi_comment = 0;
    int in_string = 0;
    int in_char = 0;
    int escaped = 0;

    while ((c = getchar()) != EOF) {

        if (in_single_comment) {
            if (c == '\n') {
                in_single_comment = 0;
                putchar('\n');
            }
            continue;
        }

        if (in_multi_comment) {
            if (c == '*') {
                next = getchar();

                if (next == '/') {
                    in_multi_comment = 0;
                } else if (next != EOF) {
                    ungetc(next, stdin);
                }
            } else if (c == '\n') {
                putchar('\n');
            }

            continue;
        }

        if (in_string) {
            putchar(c);

            if (escaped) {
                escaped = 0;
            } else if (c == '\\') {
                escaped = 1;
            } else if (c == '"') {
                in_string = 0;
            }

            continue;
        }

        if (in_char) {
            putchar(c);

            if (escaped) {
                escaped = 0;
            } else if (c == '\\') {
                escaped = 1;
            } else if (c == '\'') {
                in_char = 0;
            }

            continue;
        }

        if (c == '"') {
            in_string = 1;
            putchar(c);
        } else if (c == '\'') {
            in_char = 1;
            putchar(c);
        } else if (c == '/') {
            next = getchar();

            if (next == '/') {
                in_single_comment = 1;
            } else if (next == '*') {
                in_multi_comment = 1;
            } else {
                putchar(c);

                if (next != EOF)
                    ungetc(next, stdin);
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}
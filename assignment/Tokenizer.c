#include <stdio.h>
#include <string.h>

int main() {
    char languages[] = "C,C++,Java,Python,Rust";

    char *token = strtok(languages, ",");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}
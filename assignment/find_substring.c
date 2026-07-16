#include <stdio.h>

int find_substring(const char *haystack, const char *needle) {
    int i, j;

    // An empty needle is found at index 0
    if (needle[0] == '\0') {
        return 0;
    }

    for (i = 0; haystack[i] != '\0'; i++) {
        j = 0;

        while (needle[j] != '\0' &&
               haystack[i + j] != '\0' &&
               haystack[i + j] == needle[j]) {
            j++;
        }

        if (needle[j] == '\0') {
            return i;
        }
    }

    return -1;
}

int main() {
    const char *haystack = "Embedded Systems";
    const char *needle = "bed";

    int index = find_substring(haystack, needle);

    printf("%d\n", index);

    return 0;
}
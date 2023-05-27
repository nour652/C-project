#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidISBN(char *isbn) {
    int len = strlen(isbn);
    int i, j = 0, s1 = 0, s2 = 0;

    // Remove hyphens and convert X to 10
    char digits[10];
    for (i = 0; i < len; i++) {
        if (isdigit(isbn[i])) {
            digits[j++] = isbn[i] - '0';
        } else if (isbn[i] == 'X') {
            digits[j++] = 10;
        }
    }

    // Check length
    if (j != 10) {
        return 0;
    }

    // Calculate s1 and s2
    for (i = 0; i < 10; i++) {
        s1 += digits[i];
        s2 += s1;
    }

    // Check divisibility by 11
    return (s2 % 11 == 0);
}

int main() {
    char isbn[80];

    while (fgets(isbn, 80, stdin) != NULL) {
        // Trim leading and trailing whitespace
        int start = 0, end = strlen(isbn) - 1;
        while (isspace(isbn[start])) {
            start++;
        }
        while (isspace(isbn[end])) {
            end--;
        }
        isbn[end+1] = '\0';

        // Validate ISBN
        printf("%s", isbn);
        if (isValidISBN(isbn + start)) {
            printf(" is correct.\n");
        } else {
            printf(" is incorrect.\n");
        }
    }

    return 0;
}

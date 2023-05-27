#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to perform XOR encryption/decryption */
void xor_cipher(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] ^= key;
    }
}

/* Function to perform bit-wise inversion */
void invert_bits(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = ~str[i];
    }
}

/* Function to print string */
void print_string(char* str) {
    printf("Resultant text: %s\n", str);
}

int main() {
    char text[100];
    int choice, key;

    /* Get input text from user */
    printf("Enter text: ");
    fgets(text, 100, stdin);

    /* Remove newline character at end of input text */
    text[strcspn(text, "\n")] = '\0';

    while (1) {
        /* Display menu and get user's choice */
        printf("\nChoose an operation:\n");
        printf("1. XOR encryption/decryption\n");
        printf("2. Bit-wise inversion\n");
        scanf("%d", &choice);

        /* Perform the chosen operation on the input text */
        if (choice == 1) {
            printf("Enter key: ");
            scanf("%d", &key);
            xor_cipher(text, key);
            print_string(text);
        } else if (choice == 2) {
            invert_bits(text);
            print_string(text);
        } else {
            printf("Invalid choice!\n");
            continue;
        }

        /* Ask user if they want to perform another operation */
        printf("Perform the inverse operation again? (y/n): ");
        char answer;
        scanf(" %c", &answer);
        if (answer == 'y' || answer == 'Y') {
            if (choice == 1) {
                xor_cipher(text, key); /* Perform inverse XOR operation */
            } else {
                invert_bits(text); /* Perform inverse bit-wise inversion */
            }
            print_string(text);
        } else {
            break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int find_smallest_base(char* num_str, int num_len) {
    int max_digit = 0;
    for (int i = 0; i < num_len; i++) {
        if (num_str[i] >= '0' && num_str[i] <= '9') {
            max_digit = fmax(max_digit, num_str[i] - '0');
        } else if (num_str[i] >= 'A' && num_str[i] <= 'Z') {
            max_digit = fmax(max_digit, num_str[i] - 'A' + 10);
        }
    }
    return max_digit + 1;
}

int main() {
    char x_str[100], y_str[100];
    while (scanf("%s %s", x_str, y_str) == 2) {
        int smallest_x_base = -1, smallest_y_base = -1;
        int x_len = strlen(x_str), y_len = strlen(y_str);

        // Check bases 2 through 10
        for (int base = 2; base <= 10; base++) {
            int x_val = strtol(x_str, NULL, base);
            int y_val = strtol(y_str, NULL, base);
            if (x_val == y_val) {
                smallest_x_base = smallest_y_base = base;
                break;
            }
        }

        // Check all possible base combinations
        if (smallest_x_base == -1) {
            for (int x_base = 2; x_base <= 36; x_base++) {
                for (int y_base = 2; y_base <= 36; y_base++) {
                    int x_val = strtol(x_str, NULL, x_base);
                    int y_val = strtol(y_str, NULL, y_base);
                    if (x_val == y_val) {
                        smallest_x_base = x_base;
                        smallest_y_base = y_base;
                        break;
                    }
                }
                if (smallest_x_base != -1) {
                    break;
                }
            }
        }
    if (smallest_x_base == -1)
        printf("%s is not equal to %s in any base 2..36", x_str, y_str);
    else
        printf("%s (base %d) = %s (base %d)\n", x_str, smallest_x_base, y_str, smallest_y_base);
    }
    return (0);
}

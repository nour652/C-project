#include <stdio.h>

int find_ugly_number(int n) {
    int ugly_numbers[n];
    int i2 = 0, i3 = 0, i5 = 0;
    int next_ugly_2 = 2, next_ugly_3 = 3, next_ugly_5 = 5;
    ugly_numbers[0] = 1;

    for (int i = 1; i < n; i++) {
        int next_ugly = (next_ugly_2 < next_ugly_3) ? next_ugly_2 : next_ugly_3;
        next_ugly = (next_ugly < next_ugly_5) ? next_ugly : next_ugly_5;
        ugly_numbers[i] = next_ugly;

        if (next_ugly == next_ugly_2) {
            i2++;
            next_ugly_2 = ugly_numbers[i2] * 2;
        }

        if (next_ugly == next_ugly_3) {
            i3++;
            next_ugly_3 = ugly_numbers[i3] * 3;
        }

        if (next_ugly == next_ugly_5) {
            i5++;
            next_ugly_5 = ugly_numbers[i5] * 5;
        }
    }

    return ugly_numbers[n-1];
}

int main() {
    int n = 1500;
    int ugly_number = find_ugly_number(n);
    printf("The %dth ugly number is: %d\n", n, ugly_number);

    return 0;
}

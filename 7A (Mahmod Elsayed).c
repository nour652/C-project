#include <stdio.h>

#define MAX_N 25

int main() {
    int n, k;
    int queue[MAX_N];
    int i, j;

    while (1) {
        scanf("%d %d", &n, &k);
        if (n == 0 && k == 0) break;

        for (i = 0; i < n; i++) {
            queue[i] = i + 1;
        }

        int current = -1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < k; j++) {
                do {
                    current = (current + 1) % n;
                } while (queue[current] == -1);
            }
            printf("%3d", queue[current]);
            queue[current] = -1;
        }
        printf("\n");
    }

    return 0;
}

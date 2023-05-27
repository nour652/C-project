
#include <stdio.h>

#define MAX_AMOUNT 30000 /* Maximum amount in cents */

int main() {
    int coins[] = {500, 200, 100, 50, 20, 10, 5}; /* Values of coins in cents */
    int n_coins = 7; /* Number of different coins */
    int ways[MAX_AMOUNT+1] = {0}; /* Number of ways for each amount */
    float amount;

    /* Compute number of ways for each amount */
    ways[0] = 1;
    for (int i = 0; i < n_coins; i++) {
        for (int j = coins[i]; j <= MAX_AMOUNT; j++) {
            ways[j] += ways[j - coins[i]];
        }
    }

    /* Read input amounts and output number of ways */
    while (scanf("%f", &amount)) {
        if (amount == 0.00) break;
        int cents = (int)(amount * 100 + 0.5); /* Convert amount to cents */
        printf("%6.2f%17d\n", amount, ways[cents]);
    }

    return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
    int H, m;
    while (scanf("%d%d", &H, &m) && (H || m)) {
        int n = 1;
        while (fabs(log10(n) / log10(n + 1) - log10(m) / log10(H)) > 1e-10) {
            n++;
        }
        int k = (int)(log10(H) / log10(n + 1) + 0.5);

        int non_working_cats;
        double total_height;
        if (n == 1) {
            non_working_cats = k;
            total_height = H;
        } else {
            double result = 1.0;
            for (int i = 0; i < k; i++) {
                result *= n;
            }
            non_working_cats = (int)(0.5 + (1 - result) / (1 - n));

            result = 1.0;
            for (int i = 0; i < k + 1; i++) {
                result *= (double)n / (n + 1);
            }
            total_height = (int)(0.5 + (1 - result) * (n + 1) / (n - 1) * H);
        }

        printf("%d %lf\n", non_working_cats, total_height);
    }

    return 0;
}

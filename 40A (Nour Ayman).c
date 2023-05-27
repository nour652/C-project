#include <stdio.h>
#include <string.h>
#include <math.h>

char ends[5] = "END";
char s[200];
double x, y;
long dis, dx, dy, i, t = 1;

int main() {
    while (scanf("%s", s) != EOF) {
        if (strcmp(s, ends) == 0) break;
        x = 0.0; y = 0.0;
        dis = 0; dx = 0; dy = 0;
        i = 0;
        while (i < strlen(s)) {
            if (s[i] == 'N') dy = 1;
            else if (s[i] == 'S') dy = -1;
            else if (s[i] == 'W') dx = -1;
            else if (s[i] == 'E') dx = 1;
            else if (s[i] == ',' || s[i] == '.') {
                if (dx == 0 || dy == 0) {
                    x += (double)dis * (double)dx;
                    y += (double)dis * (double)dy;
                }
                else {
                    x += (double)dx * (double)dis / sqrt(2.0);
                    y += (double)dy * (double)dis / sqrt(2.0);
               }
                dis = 0; dx = 0; dy = 0;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                dis = s[i] - '0';
                while (i + 1 < strlen(s) && s[i + 1] >= '0' && s[i + 1] <= '9') {
                    i++;
                    dis = dis * 10 + s[i] - '0';
                }
            }
            i++;
        }
        printf("Map #%ld\n", t++);
        printf("The treasure is located at (%0.3lf,%0.3lf).\n", x, y);
        printf("The distance to the treasure is %0.3lf.\n", sqrt(x*x + y*y));
        printf("\n");
    }
    return 0;
}

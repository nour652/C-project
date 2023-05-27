
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100000+10
#define MOD 99997
const int inf = 0xfffffff;

char buffer[1000];
int left_col[32][10];
int right_col[32][10];
int sol[10];
int have_star[100];

int read(int *val, int *mul) {
    *val = *mul = 0;
    if (fgets(buffer, 1000, stdin) == NULL) {
        return 0;
    }
    int len = strlen(buffer);
    for (int i = 0; i < len; ++i) {
        if (buffer[i] == '|') {
            (*val)++;
        }
        else if (buffer[i] == 'n') {
            (*val) += 10;
        }
        else if (buffer[i] == '9') {
            (*val) += 100;
        }
        else if (buffer[i] == '8') {
            (*val) += 1000;
        }
        else if (buffer[i] == 'r') {
            (*val) += 10000;
        }
    }
    if (fgets(buffer, 1000, stdin) == NULL) {
        return 0;
    }
    len = strlen(buffer);
    for (int i = 0;i < len; ++i) {
        if (buffer[i] == '|') {
            (*mul)++;
        }
        else if (buffer[i] == 'n') {
            (*mul) += 10;
        }
        else if (buffer[i] == '9') {
            (*mul) += 100;
        }
        else if (buffer[i] == '8') {
            (*mul) += 1000;
        }
        else if (buffer[i] == 'r') {
            (*mul) += 10000;
        }
    }
    return 1;
}

int dfs(int k, int rest, int step) {
    if (rest == 0) {
        return 1;
    }
    if (rest - k < 0) {
        return 0;
    }
    have_star[step] = 1;
    if (dfs(2*k, rest-k, step+1)) {
        return 1;
    }
    else {
        have_star[step] = 0;
        if (dfs(2*k, rest, step+1)) {
            return 1;
        }
    }
    return 0;
}

void toString(int k, int* arr) {
    for (int i = 0; i < 5; ++i) {
        arr[i] = k % 10;
        k /= 10;
    }
}

void solution(int val) {
    toString(val, sol);
    printf("The solution is: ");
    for (int j = 0; j < sol[0]; ++j) {
        printf("|");
    }
    if (sol[0]) {
        printf(" ");
    }
    for (int j = 0; j < sol[1]; ++j) {
        printf("n");
    }
    if (sol[1]) {
        printf(" ");
    }
    for (int j = 0; j < sol[2]; ++j) {
        printf("9");
    }
    if (sol[2]) {
        printf(" ");
    }
    for (int j = 0; j < sol[3]; ++j) {
        printf("8");
    }
    if (sol[3]) {
        printf(" ");
    }
    for (int j = 0; j < sol[4]; ++j) {
        printf("r");
    }
    if (sol[4]) {
        printf(" ");
    }
    printf("\n");
}

void output(int val, int mul) {
    int k = 1;
    int tem;
    int cnt = 0;
    while (k <= mul) {
        toString(k, left_col[cnt]);
        toString(val*k, right_col[cnt]);
        ++cnt;
        k *= 2;
    }
    for (int i = 0; i < cnt; ++i) {
        int tem = 0;
        for (int j = 0; j < left_col[i][0]; ++j) {
            tem++;
            printf("|");
        }
        if (left_col[i][0]) {
            ++tem;
            printf(" ");
        }
        for (int j = 0; j < left_col[i][1]; ++j) {
            tem++;
            printf("n");
        }
        if (left_col[i][1]) {
            ++tem;
            printf(" ");
        }
        for (int j = 0; j < left_col[i][2]; ++j) {
            ++tem;
            printf("9");
        }
        if (left_col[i][2]) {
            ++tem;
            printf(" ");
        }
        for (int j = 0; j < left_col[i][3]; ++j) {
            ++tem;
            printf("8");
        }
        if (left_col[i][3]) {
            ++tem;
            printf(" ");
        }
        for (int j = 0; j < left_col[i][4]; ++j) {
            ++tem;
            printf("r");
        }
        if (left_col[i][4]) {
            ++tem;
            printf(" ");
        }
        if (have_star[i]) {
            ++tem;
            printf("*");
        }
        for (int j = 0; j < 34 - tem; ++j) {
            printf(" ");
        }
        for(int j = 0; j < right_col[i][0]; ++j) {
            printf("|");
        }
        if (right_col[i][0]) {
            printf(" ");
        }
        for (int j = 0; j < right_col[i][1]; ++j) {
            printf("n");
        }
        if (right_col[i][1]) {
            printf(" ");
        }
        for (int j = 0; j < right_col[i][2]; ++j) {
            printf("9");
        }
        if (right_col[i][2]) {
            printf(" ");
        }
        for (int j = 0; j < right_col[i][3]; ++j) {
            printf("8");
        }
        if (right_col[i][3]) {
            printf(" ");
        }
        for (int j = 0; j < right_col[i][4]; ++j) {
            printf("r");
        }
        if (right_col[i][4]) {
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int a, b;
    while (read(&a, &b)) {
        memset(have_star, 0, sizeof(have_star));
        dfs(1, b, 0);
        output(a, b);
        solution(a*b);
    }
    return 0;
}


#include <stdio.h>
#include <string.h>

#define maxn 10 + 5

char table[maxn][maxn];
int cnts[maxn][maxn];
int r,c;

int isRe(int x,int y){
    if(!y || table[x][y-1] == '*') return 1;
    return 0;
}

int isCe(int x,int y){
    if(!x || table[x-1][y] == '*') return 1;
    return 0;
}

void Aoutput(int x,int y){
    printf("%3d.",cnts[x][y]);
    for(int i = y;i < c && table[x][i] != '*';i++){
        printf("%c",table[x][i]);
    }
    putchar('\n');
}

void Doutput(int x,int y){
    printf("%3d.",cnts[x][y]);
    for(int i = x;i < r && table[i][y] != '*';i++){
        printf("%c",table[i][y]);
    }
    putchar('\n');
}

int main(){
    int puzzle = 0;
    while(scanf("%d",&r) == 1 && r){
        scanf("%d",&c);
        memset(table,'\0',sizeof(table));
        memset(cnts,0,sizeof(cnts));
        for(int i = 0;i < r;i++){
            scanf("%s",table[i]);
        }
        int cnt = 0;
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(table[i][j] != '*' && (isRe(i,j) || isCe(i,j))){
                    cnts[i][j] = ++cnt;
                }
            }
        }
        if(++puzzle > 1) putchar('\n');
        printf("puzzle #%d:\n",puzzle);
        printf("Across\n");
        cnt = 0;
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(cnts[i][j] && isRe(i,j)) Aoutput(i,j);
            }
        }
        printf("Down\n");
        cnt = 0;
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(cnts[i][j] && isCe(i,j)) Doutput(i,j);
            }
        }
    }
    return 0;
}

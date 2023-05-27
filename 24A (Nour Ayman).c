
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 250
#define O 105

int n, ans;
int gra[MAX][MAX];
int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, 1, -1, 0 };
bool vis[MAX][MAX];
char Direction[] = { 'e', 'n', 's', 'w' };
int sta[30], num[] = { 0,3 };

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void dfs(int x, int y, int pos, int dir){
    if (pos == n + 1){
        if (x == O && y == O){
            ans++;
            printf("%c", Direction[sta[1]]);
            for (int i = 2; i <= n; i++){
                printf("%c", Direction[sta[i]]);
            }
            printf("\n");
        }
        return;
    }

    int step = 0;
    for (int i = pos; i <= n; i++)
        step += i;
    if (abs(x - O) + abs(y - O) > step)
        return;

    if (dir == -1){
        for (int i = 0; i < 4; i++){
            int xx = x + pos * dx[i], yy = y + pos * dy[i];
            if (vis[xx][yy])
                continue;
            int k;
            if (1 <= i && i < 3){
                for (k = min(y, yy); k <= max(y, yy); k++){
                    if (gra[xx][k])
                        break;
                }
                if (k == max(y, yy) + 1){
                    sta[pos] = i;
                    vis[xx][yy] =true;
                    dfs(xx, yy, pos + 1, 1);
                    vis[xx][yy] = false;
                }
            }
            else{
                for (k = min(x, xx); k <= max(x, xx); k++){
                    if (gra[k][yy])
                        break;
                }
                if (k == max(x, xx) + 1){
                    sta[pos] = i;
                    vis[xx][yy] = true;
                    dfs(xx, yy, pos + 1, 0);
                    vis[xx][yy] = false;
                }
            }
        }
    }
    else{
        if (dir == 0){
            for (int i = 1; i < 3; i++){
                int xx = x + pos * dx[i], yy = y + pos * dy[i];
                if (vis[xx][yy])
                    continue;
                int k;
                for (k = min(y, yy); k <= max(y, yy); k++){
                    if (gra[xx][k])
                        break;
                }
                if (k == max(y, yy) + 1){
                    sta[pos] = i;
                    vis[xx][yy] = true;
                    dfs(xx, yy, pos + 1, 1);
                    vis[xx][yy] = false;
                }
            }
        }
        else if (dir == 1){
            for (int j =0; j < 2; j++){
                int i = num[j];
                int xx = x + pos * dx[i], yy = y + pos * dy[i];
                if (vis[xx][yy])
                    continue;
                int k;
                for (k = min(x, xx); k <= max(x, xx); k++){
                    if (gra[k][yy])
                        break;
                }
                if (k == max(x, xx) + 1){
                    sta[pos] = i;
                    vis[xx][yy] = true;
                    dfs(xx, yy, pos + 1, 0);
                    vis[xx][yy] = false;
                }
            }
        }
    }
}

int main(){
    int iCase;
    scanf("%d", &iCase);
    while (iCase--){
        ans = 0;
        memset(vis, false, sizeof(vis));
        memset(gra, 0, sizeof(gra));
        int k, x, y;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < k; i++){
            scanf("%d%d", &x, &y);
            if (abs(x) > O || abs(y) > O)
                continue;
            gra[O + x][O + y] = 1;
        }
        dfs(O, O, 1, -1);
        printf("Found %d golygon(s).\n", ans);
    }
    return 0;
}

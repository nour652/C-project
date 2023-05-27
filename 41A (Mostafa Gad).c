#include <stdio.h>
#include <limits.h>
#include <string.h>

int dp[1001][1001];
int topic;
int sum[1001];
int L,C;

int solve(int tmp)
{
    int res=L-tmp;
    if(res==0)
        return 0;
    if(res<=10)
        return -C;
    return (res-10)*(res-10);
}

int main()
{
    int n,t=0;
    while(scanf("%d",&n),n)
    {
        scanf("%d %d",&L,&C);
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&topic);
            sum[i]=topic+sum[i-1];
        }
        for(int i=0;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                dp[i][j]=INT_MAX;
            dp[i][0]=0;
        }
        for(int i=1;i<=n||dp[i-1][n]==INT_MAX;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if(sum[j]>i*L)
                    break;
                for(int k=j;k>=i-1&&sum[j]-sum[k]<=L;k--)
                {
                    int res=sum[j]-sum[k];
                    if(res<=L&&dp[i-1][k]!=INT_MAX)
                        dp[i][j]=dp[i][j]<dp[i-1][k]+solve(res)?dp[i][j]:dp[i-1][k]+solve(res);
                }
            }
        }
        int ind;
        for(int i=1;i<=n;i++)
        {
            if(dp[i][n]!=INT_MAX)
            {
                ind=i;
                break;
            }
        }
        if(t)
            printf("\n");
        printf("Case %d:\n",++t);
        printf("Minimum number of lectures: %d\n",ind);
        printf("Total dissatisfaction index:%d\n",dp[ind][n]);
    }
    return 0;
}

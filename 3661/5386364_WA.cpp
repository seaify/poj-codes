#include<cstdio>
#include<cstring>
int dp[2][510],a[11000],N,M,i,j,k;

int main()
{
    while(EOF!=scanf("%d %d",&N,&M))
    {
        for(i=1;i<=N;++i)
             scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        dp[1][0]=0;dp[1][1]=a[1];
        for(i=2;i<=N;++i)
        {
            j=i-1;
            if(j>=M)
              j=M-1;
            for(k=0;k<=j;++k)
            {
                if(dp[(i+1)%2][k]+a[i]>dp[i%2][k+1])
                     dp[i%2][k+1]=dp[(i+1)%2][k]+a[i];
                     
                if(k>=1&&dp[(i+1)%2][k]>dp[i%2][k-1])
                    dp[i%2][k-1]=dp[(i+1)%2][k];
                else if(dp[(i+1)%2][k]>dp[i%2][0])
                    dp[i%2][0]=dp[(i+1)%2][k];
            }
        }
        printf("%d\n",dp[(N+1)%2][0]);
    }
    return 0;
}

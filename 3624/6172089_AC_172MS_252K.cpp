#include<iostream>

int N,M,ans;
int dp[20000],w[4000],d[4000];

int main()
{
    int i,j;
    while(EOF!=scanf("%d %d",&N,&M))
    {
         for(i=1;i<=N;i++)
           scanf("%d %d",&w[i],&d[i]);
           
         for(j=0;j<=M;j++)
            dp[j]=0;
            
            
         for(i=1;i<=N;i++)
         {
             for(j=0;j<=M-w[i];j++)
             {
                 if(dp[j+w[i]]+d[i]>dp[j])
                    dp[j]=dp[j+w[i]]+d[i];
             }
             
         }
               
         printf("%d\n",dp[0]);
    } 
	return 0;
}


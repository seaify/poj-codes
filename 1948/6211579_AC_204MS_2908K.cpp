#include<iostream>
#include<math.h>

int n,flag;
int a[100],sum,t;
int dp[2000][2000];
double p,ans,tmp;

int main()
{
    int i,j,k;
    
    while(EOF!=scanf("%d",&n))
    {
         sum=0;
         for(i=1;i<=n;i++)
         {
            scanf("%d",&a[i]);
            sum+=a[i];
         } 
         
         p=(double)sum/2.0;
         
         if(sum&1)
              t=(sum-1)/2;
         else
              t=sum/2; 
         
         for(i=0;i<=t;i++)
            for(j=0;j<=t;j++)
                dp[i][j]=0;
         
         dp[0][0]=1;
         
         for(i=1;i<=n;i++)
         {
             for(j=t;j>=0;j--)
             {
                 for(k=t;k>=0;k--)
                 {
                       if(dp[j][k])
                       {
                            if(k+a[i]<=t)
                                dp[j][k+a[i]]=1;
                            if(j+a[i]<=t) 
                                dp[j+a[i]][k]=1; 
                       }
                 }
             }
         } 
         
         flag=0;  
         ans=-1;
         
         for(i=1;i<=t;i++)
           for(j=1;j<=t;j++)
               if(dp[i][j])
               {
                   k=sum-i-j;
                   if(k<=t)
                   {
                        flag=1;
                        tmp=sqrt(p*(p-i)*(p-j)*(p-k));
                        if(tmp>ans)
                           ans=tmp;
                   }
               }
         
         if(flag)
              printf("%d\n",(int)(100*ans)); 
         else
              printf("-1\n");
    }
    return 0;
} 

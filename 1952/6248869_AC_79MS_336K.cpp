#include<iostream>

const int INF=(1<<30)-1+(1<<30);  //////

int a[6000],dp[6000];
int flag[60000];
int num[6000];
int n;

int main()
{
    int i,j;
    
   // freopen("buylow.1.in","r",stdin);
   // freopen("check.out","w",stdout);   ///flag起初都为0 
    
    while(EOF!=scanf("%d",&n))
    {
          for(i=n;i>=1;i--)     ////
              scanf("%d",&a[i]);
          a[++n]=INF;
              
          dp[1]=1;
          num[1]=1;
               
          for(i=2;i<=n;i++)
          {
             dp[i]=0;
             num[i]=0;       
             for(j=i-1;j>=1;j--)
                if(a[j]<a[i])
                {
                   if(dp[j]+1>dp[i])
                   {
                      flag[a[j]]=i;  ////标记插入.... 
                      dp[i]=dp[j]+1;
                      num[i]=num[j];
                   }
                   else if(dp[j]+1==dp[i]&&flag[a[j]]<i)
                   {
                      num[i]+=num[j];           
                      flag[a[j]]=i;       
                   }
                }
                
             if(dp[i]==0)
             {
                dp[i]=1;
                num[i]=1;
             }
          }
          
          printf("%d %d\n",dp[n]-1,num[n]);
               
    }
    return 0;
} 

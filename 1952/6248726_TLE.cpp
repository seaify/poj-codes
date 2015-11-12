#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int INF=(1<<30)-1+(1<<30);  //////

set < int > H;
int a[6000],num[6000],dp[6000];
int n;

int main()
{
    int i,j;
    
    while(EOF!=scanf("%d",&n))
    {
          for(i=n;i>=1;i--)
              scanf("%d",&a[i]);
          a[++n]=INF;
              
          dp[1]=1;
          num[1]=1;
        
          
          for(i=2;i<=n;i++)
          {
             H.clear();
             dp[i]=0;
             num[i]=0;
             
             for(j=1;j<i;j++)
                if(a[j]<a[i])
                {
                   if(dp[j]+1>dp[i])
                   {
                      H.clear();
                      H.insert(a[j]);
                      dp[i]=dp[j]+1;
                      num[i]=num[j];
                   }
                   else if(dp[j]+1==dp[i]&&H.count(a[j])==0)
                   {
                      num[i]+=num[j];                 
                      H.insert(a[j]);
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

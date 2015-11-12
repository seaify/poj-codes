#include<iostream>
#include<algorithm>
using namespace std;

const __int64 top=31270;

__int64 n,T;
__int64 p[20],ans[32000],tmp[32000];

__int64 solve(__int64 n)
{
    __int64 i,sum=0;
    for(i=1;n>=9*p[i];i++)
    {
        sum+=9*p[i]*i;
        n-=9*p[i];
    }
    sum+=n*i; 
    return sum;
}

void output(__int64 x)
{
    __int64 n,pos,result;
    
    
    n=lower_bound(ans+1,ans+top+1,x)-ans;
    x-=ans[n-1]; 
        
    pos=lower_bound(tmp+1,tmp+n+1,x)-tmp;
    
    x-=tmp[pos-1];
    x=tmp[pos]-tmp[pos-1]-x+1;
    
    result=(pos/p[x])%10;
    
    printf("%I64d\n",result);
    
}

int main()
{
    __int64 i;
    
    p[1]=1;
    for(i=2;i<=12;i++)
          p[i]=p[i-1]*10;
          
    ans[0]=0;
    for(i=1;i<=top;i++)
    {
        tmp[i]=solve(i);
        ans[i]=ans[i-1]+tmp[i];
    }
    
    scanf("%I64d",&T);
    while(T--)
    {
         scanf("%I64d",&n);
         output(n);
    }
    return 0;
} 


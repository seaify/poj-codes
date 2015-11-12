#include"stdio.h"
#define limit 1000001
__int64 prime[limit+1]={0};
char ok[limit+1]={0};
__int64 phi[limit+1]={0};
__int64 s[limit+1];
void shax()
{
     __int64 i,j;
     for(i=2;i<=limit;i++)
     {
      if(ok[i]==0) 
      {
       prime[++prime[0]]=i;
       phi[i]=i-1;
      }
      for(j=1;j<=prime[0]&&prime[j]*i<=limit;j++)
      {
       ok[prime[j]*i]=1;
       if(i%prime[j]==0)
       {
         phi[i*prime[j]]=phi[i]*prime[j];  
         break;
       }
       else
         phi[i*prime[j]]=phi[i]*(prime[j]-1);
      }
     }
}
int main()
{
    __int64 i;
    phi[1]=0;
    shax();
    for(i=1;i<=limit;i++)
      s[i]=s[i-1]+phi[i];
    while(1)
    {
     scanf("%I64d",&i);
     if(i==0) break;
     printf("%I64d\n",s[i]);
    }
    return 0;
}


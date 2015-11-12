#include<stdio.h>
#include<string.h>
#include<math.h>
const int maxn=1000;
bool flag[maxn+2];
int prime[1000],j,k,t,m,top,n,time;
int f[1100000],num[1100000];
__int64 sum[1100000];

void init()
{
 int i,k;
 memset(flag,true,sizeof(flag));//生成素数,
 flag[1]=false;
 k=int(sqrt(1.0*maxn));
 for(i=2;i<=k;i++)
 {
   if(flag[i])
   {
    j=i*i;
    while(j<=maxn)
    {
     flag[j]=false;
     j=j+2*i;
    }
   }
 }
 k=1;
 prime[1]=2;
  for(i=3;i<=maxn;i=i+2)
    if(flag[i])
        prime[++k]=i;
 top=k;
}

void phi() 
{
  
  for(k=2;k<=1000000;k++)
          num[k]=f[k]=k;
      
  for(k=1;k<=top;++k)
  {
      for(j=prime[k];j<=1000000;j+=prime[k])
      {
               f[j]/=prime[k];
               f[j]*=(prime[k]-1);
               while(num[j]%prime[k]==0)
                    num[j]/=prime[k];
      }     
  } 
  
  sum[1]=0;
  
  for(k=2;k<=1000000;k++)
  {
       if(num[k]!=1)
       {
           f[k]/=num[k];
           f[k]*=(num[k]-1);
       }
       
       sum[k]=sum[k-1]+f[k];
  }
           

}

int main()
{

  init();
  phi();
 
  while(EOF!=scanf("%d",&n)&&n)//求n的欧拉函数。。。。 
       printf("%I64d\n",sum[n]);
       
  return 0;
  
}

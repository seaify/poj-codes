#include<stdio.h>
#include<string.h>
#include<math.h>
const int maxn=100000;
bool flag[maxn+2];
int prime[100000],j,k,t,m,top,n;
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
  for(i=3;i<=maxn;i=i+2)//flag[i]为true，表示i为素数。。。 
    if(flag[i])
        prime[++k]=i;
 top=k;
}
void solve(int n) 
{
  int a,mid;
  mid=n/2; 
  for(k=2;k<=top&&prime[k]<=mid;++k)
  {
     a=prime[k];
     if(flag[n-a])
     {
          printf("%d = %d + %d\n",n,a,n-a);
          return ;
     }
  } 
  printf("Goldbach's conjecture is wrong.\n"); 
  
}
int main()
{
  init();
  while(EOF!=scanf("%d",&n))//求n的欧拉函数。。。。 
  {
    if(n==0)
       break;
	solve(n);
  }
  return 0;
}

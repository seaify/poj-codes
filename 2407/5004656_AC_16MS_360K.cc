#include<stdio.h>
#include<string.h>
#include<math.h>
const int maxn=31622;
bool flag[maxn+2];
int prime[40000],j,k,t,m,top,n;
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
void divide(int n) 
{
  int temp,sum,last=1; 
  for(k=1;k<=top&&prime[k]<=n;++k)
  {
    sum=0;temp=1;
    while(n%prime[k]==0)
    {
      n/=prime[k];
      ++sum;
      temp*=prime[k];
    }
    last*=(temp-temp/prime[k]);
  } 
  if(n!=1)
      last*=(n-1);
  printf("%d\n",last);
}
int main()
{
  init();
  while(EOF!=scanf("%d",&n))
  {
    if(n==0)
       break;
	divide(n);
  }
  return 0;
}

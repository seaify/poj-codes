#include<stdio.h>
#include<string.h>
#include<math.h>
const int max=46341;
bool flag[max];
int prime[100000],j,k,t,m,top,n;
void init()
{
 int i;
 memset(flag,true,sizeof(flag));//生成素数,共9592 个 
 flag[1]=false;
 k=int(sqrt(1.0*max));
 for(i=2;i<=k;i++)
 {
   if(flag[i])
   {
    j=i*i;
    while(j<=max)
    {
     flag[j]=false;
     j=j+2*i;
    }
   }
 }
 k=1;
 prime[1]=2;
  for(i=3;i<=max;i=i+2)
    if(flag[i])
        prime[++k]=i;
 top=k;
}
void divide(int n)
{
  __int64 temp,sum,last=1; 
  for(k=1;k<=top&&prime[k]<=n;++k)
  {
    sum=0;temp=1;
    while(n%prime[k]==0)
    {
      n/=prime[k];
      ++sum;
      temp*=prime[k];
    }
    if(sum==1)
        last*=(2*prime[k]-1);
    else if(sum>0) 
        last*=((temp-temp/prime[k])*sum+temp);
  } 
  printf("%I64d\n",last);
}


int main()
{
  init();
  while(EOF!=scanf("%d",&n))
  {
	divide(n);
  }
  return 0;
}

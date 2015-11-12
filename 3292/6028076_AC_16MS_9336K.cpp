#include<stdio.h>
#include<string.h>
#include<math.h>
const int maxn=1000001;
int n,top;
int prime[maxn],c[maxn+2],sum[maxn];
bool flag[maxn+2];


void init()
{
	int i,j,ans;
	memset(flag,true,sizeof(flag));          ///素数为true
	
	for(i=5;i*i<=maxn;i+=4)
		if(flag[i])
		{
          for(j=5;j*i<=maxn;j+=4)
		  {
			  flag[j*i]=false;
		  }
		}

   top=0;
   for(i=5;i<=maxn;i+=4)
	   if(flag[i])
		   prime[++top]=i;


   memset(c,0,sizeof(c)); 

   for(i=1;i<=top;i++)
   {
	   ans=maxn/prime[i];
	   for(j=i;j<=top&&prime[j]<=ans;j++)
		   c[prime[i]*prime[j]]=1;
   }
   
   sum[0]=0;
   for(i=1;i<=maxn;i++)
	   sum[i]=sum[i-1]+c[i];
}

int main()
{
	init();
	while(EOF!=scanf("%d",&n))
	{
		if(n==0)
			break;
		printf("%d %d\n",n,sum[n]); 
	}
	return 0;
}
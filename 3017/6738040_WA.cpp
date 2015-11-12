#include<stdio.h>

const long long INF=1000000000000LL;
#define min(a,b) a<b?a:b;
#define max(a,b) a>b?a:b;

int N;
long long M,sum[110000],f[110000];
int a[110000],p[110000],q[110000];

void dp()
{
   int i,j,tmp,maxv;
   f[1]=a[1];
   p[1]=0;
   maxv=a[1];
   for(i=2;i<=N;i++)
   {
	f[i]=INF;
        if(sum[i]-sum[p[i-1]]>M)
	{
	      tmp=a[i];
	      for(j=i-1;j>p[i-1]&&sum[i]-sum[j]<=M;j--)
	      {
		    tmp=max(tmp,a[j]);
                    if(f[j]+tmp<f[i])
		    {
			f[i]=f[j]+tmp;
			p[i]=j;
			maxv=tmp;
		    }
	      }
	}
	else
	{
	     if(a[i]<=maxv)
	     {
		    f[i]=f[i-1];
		    p[i]=p[i-1];
	     }
	     else
	     {
		    tmp=a[i];
		    for(j=p[i-1];sum[i]-sum[j]<=M;j--)
		    {
			tmp=max(tmp,a[j]);
                        if(f[j]+tmp<f[i])
			{
			   f[i]=f[j]+tmp;
			   p[i]=j;
			   maxv=tmp;
			}
		    }
	     }
	}

   }
   printf("%lld\n",f[N]);
}

int main()
{
    int i,flag;
    while(EOF!=scanf("%d %d",&N,&M))
    {
	  flag=0;sum[0]=0;
	  for(i=1;i<=N;i++)
	  {
	      scanf("%d",&a[i]);
	      sum[i]=sum[i-1]+a[i];
	      if(a[i]>M)
		   flag=1;
	  }
	  sum[N+1]=sum[N];
	  if(flag)
	      printf("-1\n");
          dp();
    }
    return 0;

}
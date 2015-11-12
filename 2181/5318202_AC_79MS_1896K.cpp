#include<cstdio>
const int maxn=200000;
int a[maxn],f[maxn],g[maxn],i,n,maxf,maxg;
int main()
{
	while(EOF!=scanf("%d",&n))
	{
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		maxf=a[1];maxg=0;
		for(i=2;i<=n;++i)
		{
		   f[i]=maxg+a[i];
		   g[i]=maxf-a[i];
		   if(f[i]>maxf)
			   maxf=f[i];
		   if(g[i]>maxg)
			   maxg=g[i];
		}
		if(maxf>maxg)
            printf("%d\n",maxf);
		else
			printf("%d\n",maxg);
	}
	return 0;
}

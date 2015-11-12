#include<stdio.h>

#define min(a,b) a<b?a:b;
#define max(a,b) a>b?a:b;

int n,t,m;
int a[2000],f[2000];

int main()
{
	int i,j,v,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&t,&m);
        for(i=1;i<=m;i++)
			scanf("%d",&a[i]);
        f[0]=0;
		for(i=1;i<=m;i++)
		{
			f[i]=-1;
			for(j=i-1;j>=i-n&&j>=0;j--)
			{
                v=max(a[i],f[j]);
				if(f[i]==-1)
					f[i]=v+2*t;
				else
					f[i]=min(f[i],v+2*t);
			}

		}
		if((m%n)==0)
            v=m/n;
		else
			v=m/n+1;
		printf("%d %d\n",f[m]-t,v);
	}
	return 0;
}
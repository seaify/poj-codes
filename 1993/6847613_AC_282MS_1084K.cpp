#include<stdio.h>
#include<string.h>

long long m,n,p,N;
long long a[200][200],b[200][200],c[200][200];

int main()
{
	long long i,j,k,x,T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&N);
		for(x=1;x<=N;x++)
		{
			scanf("%lld %lld",&p,&n);
			for(i=1;i<=p;i++)
			   for(j=1;j<=n;j++)
				scanf("%lld",&b[i][j]);
			if(x==1)
			{
				memcpy(a,b,sizeof(b));
				m=p;
			}
            else
			{
				for(i=1;i<=m;i++)
					for(j=1;j<=n;j++)
					{
						c[i][j]=0;
						for(k=1;k<=p;k++)
							c[i][j]+=a[i][k]*b[k][j];
					}
                memcpy(a,c,sizeof(c));
			}
		}
		for(i=1;i<=m;i++)
		{
			for(j=1;j<n;j++)
				printf("%lld ",a[i][j]);
			printf("%lld\n",a[i][n]);
		}
		printf("\n");
	}
	return 0;
}
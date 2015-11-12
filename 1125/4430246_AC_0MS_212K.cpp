#include<stdio.h>
int n,a[101][101],i,j,k,c,min,max,m,time;
void init()
{
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(a[i][j]>a[i][k]+a[k][j])
					a[i][j]=a[i][k]+a[k][j];
}
void solve()
{
	min=20000;
	for(i=1;i<=n;i++)
	{
		max=0;
		for(j=1;j<=n;j++)
			if(a[i][j]>max)
				max=a[i][j];
		if(max<min)
		{
			min=max;
			c=i;
		}
	}
	if(min==20000)
		printf("disjoint\n");
	else
		printf("%d %d\n",c,min);
}
int main()
{
	while(EOF!=scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				a[i][j]=20000;
		for(i=1;i<=n;i++)
			a[i][i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d%d",&k,&time);
				a[i][k]=time;
			}
		}
		init();
		solve();

	}
	return 0;
}


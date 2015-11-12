#include<stdio.h>
const int maxn=1005;
int n,c,cost[maxn][maxn],mincost[maxn];
int main()
{
	int i,j,k;
	while(EOF!=scanf("%d",&c))
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=i;j<=n;j++)
				scanf("%d",&cost[i][j]);
		for(i=1;i<=n;i++)
			mincost[i]=c+cost[1][i];
		for(i=2;i<=n;i++)
			for(j=i;j<=n;j++)
				if(mincost[j]>mincost[i-1]+c+cost[i][j])
					mincost[j]=mincost[i-1]+c+cost[i][j];
		printf("%d\n",mincost[n]);
	}
	return 0;
}
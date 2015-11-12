#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int R,C,i,j,k,m,min[31][301],dis[301][301],a[301];
void init()
{
	for(i=1;i<=C;i++)
		for(j=1;j<=C;j++)
		{
			m=(i+j)/2;dis[i][j]=0;
			for(k=i;k<=j;k++)
                 dis[i][j]+=abs(a[k]-a[m]);		    
		}
}
int solve()
{
	for(i=1;i<=R;i++)
		for(j=1;j<=C;j++)
			min[i][j]=3000000;
	for(i=1;i<=C;i++)
		min[1][i]=dis[1][i];
	for(i=2;i<=R;i++)
		for(j=i;j<=C;j++)
			for(k=i-1;k<j;k++)
				if(min[i][j]>min[i-1][k]+dis[k+1][j])
					min[i][j]=min[i-1][k]+dis[k+1][j];
	return min[R][C];

}
int main()
{
	scanf("%d%d",&C,&R);
    for(i=1;i<=C;i++)
		scanf("%d",&a[i]);
	init();
	printf("%d\n",solve());
	return 0;
}

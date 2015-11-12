#include<stdio.h>
int a[510][510],min[510];
int prim(int n)
{
	int i,j,k,c,max;
	for(i=2;i<=n;i++)
		min[i]=a[1][i];
	min[1]=0;max=0;
	for(i=1;i<n;i++)
	{
		c=70000;
		for(j=2;j<=n;j++)
			if(min[j]>0&&min[j]<c)
			{
				c=min[j];
				k=j;
			}
	    if(c>max)
			max=c;
		min[k]=0;
		for(j=2;j<=n;j++)
           if(a[k][j]>0&&a[k][j]<min[j])
			   min[j]=a[k][j];
	}
	return max;
}
int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		printf("%d\n",prim(n));
	}
    return 0;
}
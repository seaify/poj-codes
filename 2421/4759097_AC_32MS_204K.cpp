#include<stdio.h>
const int maxn=110;
int a[maxn][maxn],min[maxn];
int main()
{
	int n,i,j,k,c,sum;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
          scanf("%d",&a[i][j]);
	scanf("%d",&k);
	while(k--)
	{
	  scanf("%d%d",&i,&j);
	  a[i][j]=0;
          a[j][i]=0;
	}
    for(i=2;i<=n;i++)
		min[i]=a[1][i];
	min[1]=-1;sum=0;
	for(i=1;i<n;i++)
	{
		c=100000;
		for(j=2;j<=n;j++)
			if(min[j]>=0&&min[j]<c)
			{
				c=min[j];
				k=j;
			}
	    sum=sum+c;
		min[k]=-1;
		for(j=2;j<=n;j++)
                  if(a[k][j]<min[j])
			  min[j]=a[k][j]; 
	}
	printf("%d\n",sum);
    return 0;
}




#include<cstdio>
#include<cmath>
const int maxn=1100;
const double INF=100000000.0;
double a[maxn][maxn],min[maxn],x[maxn],y[maxn],c,sum;
int main()
{
	int n,i,j,k;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;++i)
		scanf("%lf %lf",&x[i],&y[i]);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			a[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	while(k--)
	{
	  scanf("%d %d",&i,&j);
	  a[i][j]=0;
      a[j][i]=0;
	}
    for(i=2;i<=n;i++)
		min[i]=a[1][i];
	min[1]=-1;sum=0;
	for(i=1;i<n;i++)
	{
		c=INF;
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
	printf("%.2lf\n",sum);
    return 0;
}





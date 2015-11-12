#include<stdio.h>
int i,j,t,n,k,a[1000];
double min[1000][1000];
double max,c,d,v[1000][1000],b[1000][1000],f[1000][1000];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
      scanf("%d",&n);
	  for(i=1;i<=n;i++)
	  {
		  scanf("%d",&a[i]);//每一个装置的个数
		  for(j=1;j<=a[i];j++)
		  {
			scanf("%lf%lf",&b[i][j],&v[i][j]);			
		  }
	  }
	  for(j=1;j<=a[1];j++)
	  {
		  min[1][j]=b[1][j];
			f[1][j]=v[1][j];
	  }
	  for(i=2;i<=n;i++)
	  {
		  max=0;
		  for(j=1;j<=a[i];j++)
		  {
			  for(k=1;k<=a[i-1];k++)
			  {
				  d=f[i-1][k]+v[i][j];
				  c=min[i-1][k]<b[i][j]?min[i-1][k]:b[i][j];
				  if(c/d>max)
				  {
					f[i][j]=d;
					min[i][j]=c;
					max=c/d;
				  }
			  }
		  }
	}
	 printf("%.3lf\n",max);
	}

	return 0;
}
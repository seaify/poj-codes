#include<stdio.h>
#include<math.h>
double  a[110][110],min[110],x[110],y[110],c,sum;
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	   scanf("%lf%lf",&x[i],&y[i]);
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
          a[i][j]=a[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])); 
    for(i=2;i<=n;i++)
		min[i]=a[1][i];
	min[1]=0;sum=0;
	for(i=1;i<n;i++)
	{
		c=11000000;
		for(j=2;j<=n;j++)
			if(min[j]>0&&min[j]<c)
			{
				c=min[j];
				k=j;
			}
	    sum=sum+c;
		min[k]=0;
		for(j=2;j<=n;j++)
           if(a[k][j]>0&&a[k][j]<min[j])
			   min[j]=a[k][j];
	}
		printf("%.2lf\n",sum);
    return 0;
}


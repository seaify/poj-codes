#include<stdio.h>
#include<math.h>
const int maxn=760;
const double eps=1e-8;
int x[maxn],y[maxn],close[maxn];
double a[maxn][maxn],min[maxn],c;
bool flag[maxn],last;
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	   scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<n;i++)
	   for(j=1;j<=n;j++)
          a[i][j]=a[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])); 
	scanf("%d",&k);
	while(k--)
	{
	  scanf("%d%d",&i,&j);
	  a[i][j]=0;
      a[j][i]=0;
	}
    for(i=2;i<=n;i++)
	{
	  min[i]=a[1][i];
	  close[i]=1;
	  flag[i]=true;
	}
	last=false;
	for(i=1;i<n;i++)
	{
		c=100000;
		for(j=2;j<=n;j++)
			if(flag[j]&&min[j]<c)
			{
				c=min[j];
				k=j;
			}
		if(fabs(c)>eps)
		{
			printf("%d %d\n",close[k],k);
			last=true;
		}
		flag[k]=false;
		for(j=2;j<=n;j++)
            if(flag[j]&&a[k][j]<min[j])
			   min[j]=a[k][j],close[j]=k; 
	}
	if(!last)
	     printf("\n");
    return 0;
}





#include<stdio.h>

#define max(a,b) a>b?a:b;

int n,m;
int a[11000],f[11000][510];

int main()
{
	int i,j;
	while(EOF!=scanf("%d %d",&n,&m))
	{
          for(i=1;i<=n;i++)
			  scanf("%d",&a[i]);
		  for(i=1;i<=n;i++)
			  for(j=0;j<=m;j++)
				  f[i][j]=0;

		  f[1][1]=a[1];
		  for(i=1;i<n;i++)
			  for(j=0;j<=m;j++)
			  {
				  if(j==0)
					  f[i+1][j]=max(f[i+1][j],f[i][j]);
				  if(j!=0)
					  f[i+j][0]=max(f[i+j][0],f[i][j]);
				  f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+a[i+1]);
			  }
          printf("%d\n",f[n][0]);

	}
	return 0;
}
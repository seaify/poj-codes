#include<stdio.h>
#include<string.h>
long a[510][510],b[510][510],c[510][510],x[510],y[510],z[510];
int main()
{
	int n,i,j;
	while(EOF!=scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%ld",&a[i][j]);
    	for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%ld",&b[i][j]);	
	    for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%ld",&c[i][j]);
			memset(x,0,sizeof(x));
			memset(y,0,sizeof(y));
			memset(z,0,sizeof(z));
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					x[i]+=c[j][i]*j;
          for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					y[i]+=a[j][i]*j;
           for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					z[i]+=b[j][i]*y[j];
			for(i=1;i<=n;i++)
				if(z[i]!=x[i])
					break;
				if(i==n+1)
					printf("YES\n");
				else
					printf("NO\n");
	}
	return 0;
}

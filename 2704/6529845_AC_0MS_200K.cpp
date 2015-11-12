#include<stdio.h>

char a[100][100];
long long f[100][100];
int n;

int main()
{
	int i,j,c;
	while(EOF!=scanf("%d",&n))
	{
		if(n==-1)
			break;
		for(i=0;i<n;i++)
			scanf("%s",a+i);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				f[i][j]=0;
		f[0][0]=1;

        for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				c=a[i][j]-'0';
				if(c==0)
					continue;
				if(i+c<n)
				    f[i+c][j]+=f[i][j];
				if(j+c<n)
				    f[i][j+c]+=f[i][j];
			}
		printf("%lld\n",f[n-1][n-1]);
	}
	return 0;
}
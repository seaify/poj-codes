#include<stdio.h>
#include<math.h>

int f[1000005][21];
int n;

void solve()
{
	int i,j;

	for(i=0;i<=n;i++)
		f[i][0]=1;

	for(i=0;i<=20;i++)
		f[0][i]=1;

	for(i=1;i<=n;i++)
	{
		for(j=1;(1<<j)<=n;j++)
		{
			f[i][j]=f[i][j-1];
			if((1<<j)<=i)
				f[i][j]=(f[i][j]+f[i-(1<<j)][j])%1000000000;
		}

		if(i==n)
			printf("%d\n",f[n][j-1]);
	}

	return ;
}

int main()
{
	while(EOF!=scanf("%d",&n))
	{
		solve();
	}
	return 0;
}
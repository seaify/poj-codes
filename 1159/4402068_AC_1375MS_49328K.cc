#include <stdio.h>
#include <string.h>
char x[5002],y[5002];short n,i,j,f[5002][5002];
int main()
{
	scanf("%d%s",&n,x+1);
	strcpy(y+1,x+1);
    for(i=1;i<=n;i++)
		x[i]=y[n+1-i];
	for(i=0;i<=n;i++)
	{
		f[i][0]=0;
		f[0][i]=0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			f[i][j]=0;
			if(x[i]==y[j])
				f[i][j]=f[i-1][j-1]+1;
			if(f[i-1][j]>f[i][j])
				f[i][j]=f[i-1][j];
			if(f[i][j-1]>f[i][j])
				f[i][j]=f[i][j-1];
		}
		printf("%d\n",n-f[n][n]);
	return 0;
}

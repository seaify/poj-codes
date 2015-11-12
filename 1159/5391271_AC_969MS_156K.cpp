#include <stdio.h>
#include <string.h>
char x[5002];short n,i,j,f[2][5002];
int main()
{
	int t=1;
	scanf("%d%s",&n,x+1);
    memset(f,0,sizeof(f[1][1]));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==x[n+1-j])
				f[t][j]=f[1-t][j-1]+1;
			if(f[1-t][j]>f[t][j])
				f[t][j]=f[1-t][j];
			if(f[t][j-1]>f[t][j])
				f[t][j]=f[t][j-1];
		
		}	
		memset(f[1-t],0,n*sizeof(f[1][1]));
			t=1-t;
	}
		printf("%d\n",n-f[1-t][n]);
	return 0;
}


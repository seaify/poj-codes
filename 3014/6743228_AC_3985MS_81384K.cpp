#include<stdio.h>

const int MOD=1000000007;
#define min(a,b) a<b?a:b

int f[4600][4600],n,m;

int dfs(int i,int j)
{
	int tmp;
	if(f[i][j]!=-1)
		return f[i][j];
	if(i==0||j==1)
		return f[i][j]=1;
	tmp=dfs(i,min(i,j-1))+dfs(i-j,min(i-j,j));
	if(tmp>=MOD)
		tmp-=MOD;
	return f[i][j]=tmp;
}

int main()
{
	int i,j;
	for(i=0;i<=4500;i++)
		for(j=0;j<=4500;j++)
			f[i][j]=-1;

	while(EOF!=scanf("%d %d",&m,&n))
	{
		printf("%d\n",dfs(n,min(n,m)));
	}
	return 0;
}
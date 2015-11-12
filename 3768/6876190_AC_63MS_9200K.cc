#include<stdio.h>

int N,K,c[100];
char a[20],ch[10][10],map[3002][3002];

void dfs(int x,int y,int depth)
{
	int i,j;
	if(depth==1)
	{
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				map[x+i][y+j]=ch[i][j];  ///
		return ;
	}
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(ch[i][j]!=' ')
			   dfs(x+i*c[depth-1],y+j*c[depth-1],depth-1);
}

int main()
{
	int i,j;
	for(i=0;i<3001;i++)
		for(j=0;j<3001;j++)
			map[i][j]=' ';
	while(EOF!=scanf("%d",&N)&&N)
	{
		getchar();
		for(i=0;i<N;i++)
		{
			gets(a);
			for(j=0;j<N;j++)
				ch[i][j]=a[j];
		}
		scanf("%d",&K);
		c[0]=1;
		for(i=1;i<=K;i++)
			c[i]=c[i-1]*N;

		dfs(0,0,K);
		for(i=0;i<c[K];i++)
		{
			for(j=0;j<c[K];j++)
			{
				putchar(map[i][j]);
				map[i][j]=' ';
			}
			puts("");
		}
	}
	return 0;
}
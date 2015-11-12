#include<stdio.h>

int N,K,c[1000];
char ch[10][10],map[4000][4000];

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
	while(EOF!=scanf("%d",&N)&&N)
	{
		for(i=0;i<N;i++)
		{
			getchar();
			for(j=0;j<N;j++)
				ch[i][j]=getchar();
		}
		scanf("%d",&K);
		c[0]=1;
		for(i=1;i<=K;i++)
			c[i]=c[i-1]*N;
		for(i=0;i<c[K];i++)
			for(j=0;j<c[K];j++)
				map[i][j]=' ';
		dfs(0,0,K);
		for(i=0;i<c[K];i++)
		{
			for(j=0;j<c[K];j++)
				printf("%c",map[i][j]);
			printf("\n");
		}
	}
	return 0;
}
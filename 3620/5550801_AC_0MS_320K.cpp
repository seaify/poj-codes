#include<cstdio>
#include<cstring>
int N,M,K,ans,c[110][110];

int dfs(int x,int y)
{
	if(c[x][y]==0)
		return 0;
	c[x][y]=0;
	return 1+dfs(x+1,y)+dfs(x-1,y)+dfs(x,y+1)+dfs(x,y-1);
	return 0;
}

int main()
{
	int i,j,x,y,v;
	while(EOF!=scanf("%d %d %d",&N,&M,&K))
	{
		memset(c,0,sizeof(c));
		while(K--)
		{
			scanf("%d %d",&x,&y);
			c[x][y]=1;
		}
		for(i=1;i<=N;++i)
			for(j=1;j<=M;++j)
				if(c[i][j])
				{
					v=dfs(i,j);
			        if(v>ans)
						ans=v;
				}
		printf("%d\n",ans);	
	}			
	return 0;
}
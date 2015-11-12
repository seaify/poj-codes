#include<cstdio>
#include<cstring>
int N,M;
bool c[1100][1100];

void solve()
{
	int i,j,k,sum=0;
	for(i=1;i<=N;++i)
		for(k=1;k<=N;++k)
			if(c[i][k])
			{
				for(j=1;j<=N;++j)
					if(c[k][j])
						c[i][j]=true;
			}
	for(i=1;i<=N;++i)
		for(j=1;j<=N;++j)
			if(c[i][j])
				++sum;
	printf("%d\n",sum);
}

int main()
{
	int i,x,y;
	while(EOF!=scanf("%d %d",&N,&M))  ///有向图..
	{
		memset(c,false,sizeof(c));
		for(i=1;i<=N;++i)
			c[i][i]=true;
		while(M--)
		{
			scanf("%d %d",&x,&y);
			c[x+1][y+1]=true;
		}
		solve();
	}
	return 0;
}

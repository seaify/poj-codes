#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector < int > a[1100];
int in[1100],out[1100];
int N,M,tot,n,answer,T;
bool flag[1100],test[1100][1100];

void dfs(int x)
{
	int i,y;
	flag[x]=false;
	++tot;
	for(i=0;i<a[x].size();++i)
	{
		y=a[x][i];
		if(flag[y])
			dfs(y);
	}
}

int main()
{
	int i,x,y;
	while(EOF!=scanf("%d %d",&N,&M))  ///有向图..
	{
		for(i=1;i<=N;++i)
			a[i].clear();
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(test,true,sizeof(test));
		while(M--)
		{
			scanf("%d %d",&x,&y);
			x++;
			y++;
			if(x!=y&&test[x][y]) ///去掉重边和自环...
			{
			   a[x].push_back(y);
			   test[x][y]=false;
			   in[y]++;
			   out[x]++;
			}
		}
		answer=N;
		for(i=1;i<=N;++i)
		{
			if(out[i]==0)   /////先排除孤立点和无出边的点...
				continue;
			memset(flag,true,sizeof(flag));  //
			tot=-1;
			dfs(i);
			answer+=tot;
		}
        printf("%d\n",answer);
	}
	return 0;
}

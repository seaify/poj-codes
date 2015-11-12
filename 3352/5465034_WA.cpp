#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector < int > e[1100];
int n,m,tot,lab[1100],son[1100],degree[1100];
bool flag[1100][1100];

int minx(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

void dfs(int cur,int p)
{
	int i,y;
    lab[cur]=son[cur]=++tot;
	for(i=0;i<e[cur].size();++i)
	{
		y=e[cur][i];
		if(lab[y]==-1)   ////树边
		{
			dfs(y,cur);
			son[cur]=minx(son[cur],son[y]);
		}
		else if(y!=p)
			son[cur]=minx(son[cur],lab[y]);
	}
}

int main()
{
	int i,j,x,y;
	while(EOF!=scanf("%d %d",&n,&m))
	{
		for(i=1;i<=n;++i)
			e[i].clear();
		memset(flag,true,sizeof(flag));
		while(m--)
		{
			scanf("%d %d",&x,&y);
			if(flag[x][y])
			{
				e[x].push_back(y);
				e[y].push_back(x);
				flag[x][y]=flag[y][x]=false;
			}
		}
		tot=0;
		memset(lab,-1,sizeof(lab));
		memset(son,-1,sizeof(son));
		dfs(1,-1);
	//	for(i=1;i<=n;++i)
	//		printf("%d %d\n",lab[i],son[i]);
		memset(degree,0,sizeof(degree));
		for(i=1;i<=n;++i)
		{
			for(j=0;j<e[i].size();++j)
				if(son[i]!=son[e[i][j]])
					++degree[i];
		}
		tot=0;
		for(i=1;i<=n;++i)
			if(degree[i]==1)
				++tot;
		printf("%d\n",(tot+1)/2);
	}
	return 0;
}
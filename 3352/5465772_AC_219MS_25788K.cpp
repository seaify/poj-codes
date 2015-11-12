#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector < int > e[5100];
int n,m,tot,lab[5100],son[5100],degree[5100];
bool flag[5100][5100];

int inline minx(int a,int b)
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
		if(lab[y]==-1)   ////树边...
		{
			dfs(y,cur);
			son[cur]=minx(son[cur],son[y]);
		}
		else if(y!=p)   ////回边...
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
		memset(lab,-1,(n+1)*sizeof(lab[1]));
		dfs(1,-1);
	//	printf("标号为:\n");
	//	for(i=1;i<=n;++i)
		//	printf("%d %d\n",lab[i],son[i]);
		memset(degree,0,sizeof(degree));
	//	printf("\n");
		for(i=1;i<=n;++i)
		{
			for(j=0;j<e[i].size();++j)
			{
				y=e[i][j];
			//	printf("%d %d\n",son[i],son[y]);
				if(son[i]!=son[e[i][j]])
					++degree[son[i]];
			}
		}
		tot=0;
		for(i=1;i<=n;++i)
			if(degree[i]==1)
				++tot;
		printf("%d\n",(tot+1)/2);
	}
	return 0;
}
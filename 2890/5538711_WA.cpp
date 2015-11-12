#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector < int > a[1100],b[1100],c[1100];
int last[1100],set[1100],sum[1100],ans[1100];
int N,M,tot,n,answer;
bool flag[1100],test[1100][1100];

void DFS_visit(int x)
{
	int i,y;
	flag[x]=false;
	for(i=0;i<a[x].size();++i)
	{
		y=a[x][i];
		if(flag[y])
			DFS_visit(y);
	}
	last[++tot]=x;
}

void dfs(int x)
{
   int y,k;
   flag[x]=false; 
   set[x]=tot;
   for(k=0;k<b[x].size();++k)
   {
	   y=b[x][k];
	   if(flag[y])
		   dfs(y);
   }
}

void DFS()
{
	int i,k,y,t1,t2;
    memset(flag,true,(N+1)*sizeof(bool));
	tot=0;   ////
	for(i=1;i<=N;++i)
		if(flag[i])
			DFS_visit(i);
	memset(flag,true,(N+1)*sizeof(bool));
	tot=0;
	for(i=N;i>=1;i--)
		if(flag[last[i]])
		{
			++tot;
			dfs(last[i]);
		}            
	memset(test,true,sizeof(test));
	for(i=1;i<=tot;++i)
		c[i].clear();
	for(i=1;i<=N;++i)       ////缩点.....
	{
		for(k=0;k<a[i].size();++k)
		{
			y=a[i][k];
			if(set[i]!=set[y]&&test[i][y])
			{
				t1=set[i];
				t2=set[y];
				c[t1].push_back(t2);
				test[t1][t2]=false;
			}
		}
	}
	for(i=1;i<=tot;++i)
		sum[i]=0;
	for(i=1;i<=N;++i)  ///统计每个强连通分量的点的个数..
		sum[set[i]]++;
}

int dfs1(int x)
{
	int k,y;
	flag[x]=false;
	if(a[x].empty())
		return sum[x];
	for(k=0;k<a[x].size();++k)
	{
		y=a[x][k];
		if(flag[y])
			ans[x]+=dfs1(y);
	}
	return ans[x]+sum[x];
}

void solve()
{
   int i;
   n=tot;
  // printf("%d\n",n);
   for(i=1;i<=n;++i)
   {
	   a[i].clear();
	   a[i]=c[i];
   }
   memset(flag,true,(n+1)*sizeof(bool));
   tot=0;
   for(i=1;i<=n;++i)    ///得到拓补序..
	   if(flag[i])
		   DFS_visit(i);
   memset(flag,true,(n+1)*sizeof(bool));
   memset(ans,0,sizeof(ans));
   for(i=n;i>=1;i--)
	   if(flag[last[i]])
	   {
		   dfs1(last[i]);
	   }
   answer=N;   /////单位矩阵....
  // for(i=1;i<=n;++i)
//	   printf("%d %d\n",ans[i],sum[i]);
   for(i=1;i<=n;++i)
	   answer+=ans[i]*sum[i]+sum[i]*(sum[i]-1);
   printf("%d\n",answer);
}

int main()
{
	int i,x,y;
	while(EOF!=scanf("%d %d",&N,&M))  ///有向图..
	{
		for(i=1;i<=N;++i)
		{
			a[i].clear();
			b[i].clear();
		}
		memset(test,true,sizeof(test));
		while(M--)
		{
			scanf("%d %d",&x,&y);
			x++;
			y++;
			if(x!=y&&test[x][y]) ///去掉重边和自环...
			{
			   a[x].push_back(y);
			   b[y].push_back(x);
			   test[x][y]=false;
			}
		}
		DFS();
		solve();
	}
	return 0;
}

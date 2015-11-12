#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,last[2200],d[2200],f[2200],set[2200],tot,cnt,t;
int x[10000],y[10000],x1[10000],y1[10000];
int left,right,mid,T;
bool flag[2200],map[2200][2200],tag;
vector< int > a[2200],b[2200],c[2200];

void DFS_visit(int i)
{
  flag[i]=false;
  ++t;
  d[i]=t;
  for( int k=0;k!=a[i].size();++k)
     if(flag[a[i][k]])
         DFS_visit(a[i][k]);
  ++t;
  f[i]=t;
  last[++tot]=i;
}
void dfs(int i)
{
  flag[i]=false;
   for( int k=0;k!=b[i].size();++k)
     if(flag[b[i][k]])
         dfs(b[i][k]);
  set[i]=tot;
}
int check()
{
  int t1,t2;
  for(i=1;i<=2*n;++i)
	  a[i].clear(),b[i].clear();
  for(i=1;i<=T;++i)
  {
	  t1=x1[i];t2=y1[i];
	  a[t1].push_back(t2+n);
	  b[t2+n].push_back(t1);
	  a[t2].push_back(t1+n);
	  b[t1+n].push_back(t2);
  }
  for(i=1;i<=mid;++i)
  {
	  t1=x[i];t2=y[i];
	  a[t1+n].push_back(t2);
	  b[t2].push_back(t1+n);
	  a[t2+n].push_back(t1);
	  b[t1].push_back(t2+n);
  }
  memset(flag,true,(2*n+1)*sizeof(flag[1]));
  t=0;tot=0;
  for(i=1;i<=2*n;++i)
    if(flag[i])
        DFS_visit(i);
  memset(flag,true,(2*n+1)*sizeof(flag[1]));
  tot=0;
  for(i=2*n;i>=1;--i)
     if(flag[last[i]])
     {
       ++tot;
       dfs(last[i]);
     }
  for(i=1;i<=n;++i)
	  if(set[i]==set[i+n])
		  return 0;
  return 1;
}
int main()
{
	int i;
    while(EOF!=scanf("%d %d",&n,&m))
	{
		if(n==0&&m==0)
			break;
		T=n;n=2*n;
		for(i=1;i<=T;++i)   ////这些边一定构图时一定会被压入。。
		{
			scanf("%d %d",&x1[i],&y1[i]);
			++x1[i];
			++y1[i];
		}
		for(i=1;i<=m;++i)
		{
			scanf("%d %d",&x[i],&y[i]);
			++x[i];
			++y[i];
		}
		left=1;right=m;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(check())
				left=mid+1;
			else
				right=mid-1;
		}
		printf("%d\n",right);
	}
    return 0;
}

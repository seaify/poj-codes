#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,last[11000],d[11000],f[11000],set[11000],sum[11000],tot,cnt,t;
bool flag[11000],map[210][210];
vector< int > a[11000],b[11000];
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
void DFS()
{
  memset(flag,true,(n+1)*sizeof(flag[1]));
  t=0;tot=0;
  for(i=1;i<=n;++i)
    if(flag[i])
        DFS_visit(i);
  memset(flag,true,(n+1)*sizeof(flag[1]));
  tot=0;
  for(i=n;i>=1;--i)
     if(flag[last[i]])
     {
       ++tot;
       dfs(last[i]);
     }       
}
int main()
{
    int k,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
       a[i].clear();
       b[i].clear();
       sum[i]=0;
    }
    for(i=1;i<=n;++i)
    {
      while(EOF!=scanf("%d",&j))
      {
        if(j==0)
         break;
        a[i].push_back(j);
        b[j].push_back(i);
      }
    }
    DFS();
    memset(map,false,sizeof(map));
    for(i=1;i<=n;++i)
        d[i]=0,f[i]=0;//分别代表出度和入度 
    for(i=1;i<=n;++i)
    {
       for(j=0;j<a[i].size();++j)
          if(set[i]!=set[a[i][j]]&&!map[set[i]][set[a[i][j]]]) 
              ++d[set[i]],++f[set[a[i][j]]],map[set[i]][set[a[i][j]]]=true;
    }
    x=0,y=0;
    for(i=1;i<=tot;++i)
    {
      if(d[i]==0)
         ++x;
      if(f[i]==0)
         ++y; 
    }
    printf("%d\n",y);
    x=x>y?x:y;
    printf("%d\n",x);
    return 0;
}


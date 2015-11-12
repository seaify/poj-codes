#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,flag[5100],last[5100],d[5100],f[5100],set[5100],tot,t;
vector< int > a[5100],b[5100];
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
  int k;
  while(EOF!=scanf("%d",&n))
  {
    if(n==0)
        break;
    scanf("%d",&m);
    for(i=1;i<=n;++i)
    {
       a[i].clear();
       b[i].clear();
    }
    while(m--)
    {
      scanf("%d%d",&i,&j);
      a[i].push_back(j);
      b[j].push_back(i);
    }
    DFS();
    memset(flag,true,(n+1)*sizeof(flag[1]));
    for(i=1;i<=n;++i)
    {
       for( k=0;k!=a[i].size();++k)
          if(set[i]!=set[a[i][k]])
             flag[set[i]]=false;
    }
    tot=0;
    for(i=1;i<=n;++i)
       if(flag[set[i]])
          last[++tot]=i;
    for(i=1;i<tot;++i)
       printf("%d ",last[i]); 
    printf("%d\n",last[tot]);
  }
  return 0;
}


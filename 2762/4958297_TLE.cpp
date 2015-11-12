#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,last[1100],d[1100],f[1100],set[1100],tot,cnt,t;
bool flag[1100],map[1100][1100],tag;
vector< int > a[1100],b[1100],c[1100];
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
    int k,T;
    scanf("%d",&T);
    while(T--)
    {
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
       a[i].clear();
       b[i].clear();
       c[i].clear();
    }
    while(m--)
    {
      scanf("%d%d",&i,&j);
      a[i].push_back(j);
      b[j].push_back(i);
    }
    DFS();
    memset(map,false,sizeof(map));
    for(i=1;i<=n;++i)
    {
      for(j=0;j<a[i].size();++j)
           if(set[i]!=set[a[i][j]]&&!map[set[i]][set[a[i][j]]])
           {
             map[set[i]][set[a[i][j]]]=true;
             c[i].push_back(set[a[i][j]]);             
           }
    }
    for(k=1;k<=tot;k++)
        map[k][k]=true;
    for(k=1;k<=tot;++k)
      for(i=1;i<=tot;++i)
        for(j=1;j<=tot;++j)
           map[i][j]=map[i][j]||(map[i][k]&&map[k][j]);
    tag=true;
    for(i=1;i<tot;++i)
      for(j=i+1;j<=tot;++j)
        if(!map[i][j]&&!map[j][i])
           {
             tag=false;
             break;
           }
    if(tag)
       printf("Yes\n");
    else
       printf("No\n");
   }
    return 0;
}

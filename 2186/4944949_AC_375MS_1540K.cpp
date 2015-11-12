#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,last[11000],d[11000],f[11000],set[11000],sum[11000],tot,cnt,t;
bool flag[11000];
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
    int k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
       a[i].clear();
       b[i].clear();
       sum[i]=0;
    }
    while(m--)
    {
      scanf("%d%d",&i,&j);
      a[i].push_back(j);
      b[j].push_back(i);
    }
    DFS();
    for(i=1;i<=n;++i)
        ++sum[set[i]];//计算出每一个堆的个数 
    memset(flag,true,(tot+1)*sizeof(flag[1]));
    for(i=1;i<=n;++i)
    {
       for( k=0;k!=a[i].size();++k)
          if(set[i]!=set[a[i][k]])
             flag[set[i]]=false;
    }
    cnt=0;j=0;
    for(i=1;i<=tot;++i)
       if(flag[i])
       {
         ++j;
         cnt+=sum[i];
       }
    if(j==1)
        printf("%d\n",cnt);
    else
        printf("0\n");
    return 0;
}

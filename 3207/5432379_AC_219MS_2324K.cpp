#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,last[2200],d[2200],f[2200],set[2200],tot,cnt,t;
int x[10000],y[10000];
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
void DFS()
{
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
}
int main()
{
    scanf("%d%d",&n,&m);
	n=m;
    for(i=1;i<=2*m;++i)
    {
        a[i].clear();
        b[i].clear();
    }
    for(i=1;i<=m;++i)
    {
      scanf("%d%d",&x[i],&y[i]); 
      ++x[i],++y[i];
      if(x[i]>y[i])
      {
         j=x[i];
         x[i]=y[i];
         y[i]=j;
      } 
     }
    for(i=1;i<m;++i)
       for(j=i+1;j<=m;++j)
          if((x[i]<x[j]&&x[j]<y[i]&&y[i]<y[j])||(x[j]<x[i]&&x[i]<y[j]&&y[j]<y[i]))
          {
             a[i].push_back(j+m);
             a[i+m].push_back(j);
             a[j].push_back(i+m);
             a[j+m].push_back(i);
             b[j+m].push_back(i);
             b[j].push_back(i+m);
             b[i+m].push_back(j);
             b[i].push_back(j+m);
          }
    DFS();
    tag=true;
    for(i=1;i<=m;++i)
       if(set[i]==set[i+m])
        {
           tag=false;
           break;
        }
    if(tag)
       printf("panda is telling the truth...\n");
    else
       printf("the evil panda is lying again\n");
    return 0;
}



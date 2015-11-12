#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int INF=100000000;
int i,j,n,m,last[1100],d[1100],f[1100],set[1100],tot,cnt,t,dis[1100][1100],v[1100][1100];
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
void solve(int x,int y)
{
   int i,j,k,minv;
   if(set[x]==set[y])
   {
     printf("0\n"); 
     return ;
   }
   x=set[x];y=set[y];
   memset(flag,false,sizeof(flag));
   for(i=1;i<=tot;++i)
       d[i]=dis[x][i];
   d[x]=0;flag[x]=true;
   for(i=1;i<tot;++i)
   {
     minv=INF;k=0;
     for(j=1;j<=tot;++j)
        if(!flag[j]&&d[j]<minv)
            k=j,minv=d[j];
     if(k==0)
        break;
     else
        flag[k]=true;
     if(flag[y])
         break;
     for(j=1;j<=tot;++j)
        if(!flag[j]&&minv+dis[k][j]<d[j])
             d[j]=minv+dis[k][j]; 
   }  
   if(d[y]==INF)
       printf("Nao e possivel entregar a carta\n");
   else
       printf("%d\n",d[y]); 
}
int main()
{
    int k,T,value,x,y,Q;
    while(EOF!=scanf("%d%d",&n,&m))
    {
     if(n==0&&m==0)
        break;
     for(i=1;i<=n;++i)
     {
       a[i].clear();
       b[i].clear();
       c[i].clear();
     }
     while(m--)
     {
      scanf("%d%d%d",&i,&j,&value);
      a[i].push_back(j);
      b[j].push_back(i);
      v[i][j]=value;
     }
     DFS();
     memset(map,false,sizeof(map));
     for(i=1;i<=tot;++i)
         for(j=1;j<=tot;++j)
             if(j!=i)
                dis[i][j]=INF; 
             else
                dis[i][j]=0;
      for(i=1;i<=n;++i)//缩图 ，先写个DJK 
      {
        for(j=0;j<a[i].size();++j)
           if(set[i]!=set[a[i][j]]&&!map[set[i]][set[a[i][j]]])
           {
             map[set[i]][set[a[i][j]]]=true;
             c[set[i]].push_back(set[a[i][j]]);  
             dis[set[i]][set[a[i][j]]]=v[i][a[i][j]];       
           }
      }
      scanf("%d",&Q);
      while(Q--)
      {
        scanf("%d%d",&x,&y);
        solve(x,y);
      } 
      printf("\n");
   }
    return 0;
}


#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,last[10000],d[10000],f[10000],set[10000],tot,cnt,t;
bool flag[10000],map[10000][10000],tag;
vector< int > a[10000],b[10000],c[10000],edge[10000];
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
void color(int x)
{
     d[x]=2;
     for (int i=0;i<a[x].size();i++)
     {
         int y=a[x][i];
         if (d[y]==-1)
         {
             color(y);
         } 
     }          
}
void solve()
{
    int i,j,k,x,sum;
    for(i=1;i<=n;++i)
       if(set[i]==set[i+n])
        {
           printf("bad luck\n");
           return ;
        }
    memset(map,false,sizeof(map));
    for(i=1;i<=2*n;++i)
    {
      for(j=0;j<a[i].size();++j)
           if(set[i]!=set[a[i][j]]&&!map[set[i]][set[a[i][j]]])
           {
             map[set[i]][set[a[i][j]]]=true;
             c[set[i]].push_back(set[a[i][j]]);             
           }
    }
    for(i=1;i<=2*n;++i)
        edge[set[i]].push_back(i);
    for(i=1;i<=2*n;++i)//tot为强连通分量个数 
    {    
      a[i].clear();
      a[i]=c[i];
    }
    memset(flag,true,(2*n+1)*sizeof(flag[1]));
    t=0;k=tot;tot=0;
    for(i=1;i<=k;++i)
       if(flag[i])
           DFS_visit(i);
    for(i=1;i<=tot;++i)
         d[i]=-1;//表示颜色 
    for(i=tot;i>=1;--i)
    {
        if(d[last[i]]==-1)
        {
           x=edge[last[i]][0];
           if(x>n)
              x-=n;
           else
              x+=n;
           d[last[i]]=1;
           if(d[set[x]]==-1)
               color(set[x]);
        }
    }
    k=d[1];sum=0;
    for(i=1;i<=tot;++i)
    {
      if(d[i]==k)
         for(j=0;j<edge[i].size();++j)
             f[++sum]=edge[i][j];
    }
    for(i=2;i<n;++i)
       if(f[i]>n)
          printf("%dh ",f[i]-n);
       else
          printf("%dw ",f[i]);
   if(f[n]>n)
          printf("%dh\n",f[n]-n);
       else
          printf("%dw\n",f[n]);
}
int main()
{
    int k,T,value;char ch1[5],ch2[5];
    while(EOF!=scanf("%d%d",&n,&m))
    {
      if(n==0&&m==0)
            break;
      for(i=1;i<=2*n;++i)
      {
        a[i].clear();
        b[i].clear();
        c[i].clear();
      }
     while(m--)
     {
       scanf("%s%s",ch1,ch2);
       i=ch1[0]-'0';
       j=ch2[0]-'0';
       ++i;++j;
       if(ch1[1]=='h')
           i+=n;
       if(ch2[1]=='h')
           j+=n;
       if(j>n)
       {
          a[i].push_back(j-n);
          b[j-n].push_back(i);
       }
       else
       {
          a[i].push_back(j+n);
          b[j+n].push_back(i);
       }
       if(i>n)
       {
           a[j].push_back(i-n);
           b[i-n].push_back(j);
       }
       else
       {
           a[j].push_back(i+n);
           b[i+n].push_back(j);
       }        
     }
    DFS();
    solve();
   }
   return 0;
}



#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int c[2100][2100],lx[2100],ly[2100],q[2100];
int i,j,n,m,last[11000],d[11000],f[11000],set[11000],sum[11000],tot,cnt,t;
bool flag[11000];
vector< int > a[11000],b[11000];

void DFS_visit(int i)
{
  flag[i]=false;
  for( int k=0;k!=a[i].size();++k)
     if(flag[a[i][k]])
         DFS_visit(a[i][k]);
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
  tot=0;
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
    int i,k,x,cnt;
    while(EOF!=scanf("%d",&n))
    {
       for(i=1;i<=2*n;++i)
       {
         a[i].clear();
         b[i].clear();
         for(j=1;i<=n&&j<=n;j++)
                c[i][j]=0;
       }
       
       for(i=1;i<=n;i++)
       {
           lx[i]=0;
           ly[i]=0;
           scanf("%d",&k);
           while(k--)
           {
                scanf("%d",&x);
                c[i][x]=1;
           }
          
       }
       
       for(i=1;i<=n;i++)
       {
           scanf("%d",&x);
           c[i][x]=2;
           lx[i]=x+n;
           ly[x]=i;
       }
       
       for(i=1;i<=n;i++)
       {
           for(j=1;j<=n;j++)
               if(c[i][j]==1)
               {
                   a[i].push_back(j+n);
                   b[j+n].push_back(i);
               }
               else if(c[i][j]==2)
               {
                    a[j+n].push_back(i);
                    b[i].push_back(j+n);
               }
       }
    
       DFS();
       
       for(i=1;i<=n;i++)
       {
           cnt=0;
           for(j=1;j<=n;j++)
               if(c[i][j])
               {
                    if(c[i][j]==2||set[lx[i]]==set[ly[j]])
                        q[++cnt]=j;
               }
           printf("%d ",cnt);   
           for(j=1;j<cnt;j++)
                 printf("%d ",q[j]);
           printf("%d\n",q[cnt]);
       }
       
    }
    return 0;
}


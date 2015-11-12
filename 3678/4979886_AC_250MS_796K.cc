#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,last[2200],d[2200],f[2200],set[2200],tot,cnt,t;
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
void add(int i,int j,int value,char ch[])
{
    if(ch[0]=='A')
    {
       if(value==1)
       {
          a[i+n].push_back(i);
          a[j+n].push_back(j);
          b[i].push_back(i+n);
          b[j].push_back(j+n);
       }
       else
       {
          a[i].push_back(j+n);
          a[j].push_back(i+n);
          b[j+n].push_back(i);
          b[i+n].push_back(j);
       }
    }
    else if(ch[0]=='O')
    {
       if(value==1)
       {
          a[i+n].push_back(j);
          a[j+n].push_back(i);
          b[j].push_back(i+n);
          b[i].push_back(j+n);
       }
       else
       {
          a[i].push_back(i+n);
          a[j].push_back(j+n);
          b[i+n].push_back(i);
          b[j+n].push_back(j);
       }
    }
    else
    {
        if(value==1)
        {
          a[i+n].push_back(j);
          a[j].push_back(i+n);
          a[i].push_back(j+n);
          a[j+n].push_back(i);
          b[j].push_back(i+n);
          b[i+n].push_back(j);
          b[j+n].push_back(i);
          b[i].push_back(j+n);
        }
        else
        {
          a[i].push_back(j);   
          a[j].push_back(i);   
          a[i+n].push_back(j+n);   
          a[j+n].push_back(i+n);   
          b[j].push_back(i);   
          b[i].push_back(j);  
          b[j+n].push_back(i+n);  
          b[i+n].push_back(j+n);  
        }
    }
}
int main()
{
    int k,T,value;char ch[5];
    scanf("%d%d",&n,&m);
    
      for(i=1;i<=2*n;++i)
      {
        a[i].clear();
        b[i].clear();
        c[i].clear();
      }
     while(m--)
     {
       scanf("%d%d%d%s",&i,&j,&value,ch);
       ++i;++j;
       add(i,j,value,ch);
     }
    DFS();
    tag=true;
    for(i=1;i<=n;++i)
       if(set[i]==set[i+n])
        {
           tag=false;
           break;
        }
    if(tag)
       printf("YES\n");
    else
       printf("NO\n");
  
    return 0;
}


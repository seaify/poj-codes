#include<stdio.h>
const int maxn=5100;
int n,m,i,j,d[maxn],f[maxn],time,last[maxn],set[maxn],tot;
bool flag[maxn];
struct Edge
{
  int adj;
  Edge *next;
};
Edge *a=new Edge[maxn],*b=new Edge[maxn];
Edge *p;
void DFS_visit(int i)
{
  Edge *p;//p一定要是局部的 
  flag[i]=false;
  ++time;
  d[i]=time;
  p=a[i].next;
  while(p!=NULL)
  {
    if(flag[p->adj])
        DFS_visit(p->adj);
    p=p->next;
  }
  ++time;
  f[i]=time;
  last[++tot]=i;
}
void dfs(int i)
{
  Edge *p;
  flag[i]=false;
  p=b[i].next;
  while(p!=NULL)
  {
    if(flag[p->adj])
        dfs(p->adj);
    p=p->next;
  }
  set[i]=tot;
}
void DFS()
{
  int i;
  for(i=1;i<=n;++i)
      flag[i]=true;
  time=0;tot=0;
  for(i=1;i<=n;++i)
     if(flag[i])
     {
       DFS_visit(i); 
     }
  for(i=1;i<=n;++i)
     flag[i]=true;
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
  while(EOF!=scanf("%d",&n))
  {
    if(n==0)
        break;
    for(i=1;i<=n;++i)
    {
      a[i].next=NULL;
      b[i].next=NULL;
    }
    scanf("%d",&m);
    while(m--)
    {
      scanf("%d%d",&i,&j);
      p=new Edge;
      p->adj=j;
      p->next=a[i].next;
      a[i].next=p;
      p=new Edge;
      p->adj=i;
      p->next=b[j].next;
      b[j].next=p;
    }
    DFS();
//    for(i=1;i<=n;++i)
//       printf("%d %d\n",d[i],f[i]); 
//    for(i=1;i<=n;++i) 
//       printf("%d\n",last[i]); 
  //  for(i=1;i<=n;++i)
//       printf("%d\n",set[i]); 
//    printf("%d\n",tot);
    for(i=1;i<=tot;++i)
       flag[i]=true; 
    for(i=1;i<=n;++i)
    {
      p=a[i].next;
      while(p!=NULL)
      {
         if(set[i]!=set[p->adj])
            flag[set[i]]=false;
         p=p->next;
      }
    }        
    tot=0;
    for(i=1;i<=n;++i)
       if(flag[set[i]])
          last[++tot]=i;
  //  printf("%d\n",tot);
    for(i=1;i<tot;++i)
       printf("%d ",last[i]); 
    printf("%d\n",last[tot]);

//    for(i=1;i<=n;++i)
//    {
//      p=b[i].next;
//      while(p!=NULL)
//      {
//         printf("%d %d\n",i,p->adj);
//         p=p->next;
//      }
//    }
  }
  return 0;
}

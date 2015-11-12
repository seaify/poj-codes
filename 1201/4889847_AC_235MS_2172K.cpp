#include<stdio.h>
const int INF=51000;
int N,beg,end,i,j,m,c,flag,d[51000];
struct node
{
  int x,y,value;
};
node edge[200002];
int main()
{
  scanf("%d",&N);
  m=0;beg=51000;end=-1;
  while(N--)//构图 
  {
    scanf("%d%d%d",&i,&j,&c);
    edge[++m].x=j+1;
    edge[m].y=i;
    edge[m].value=-c;
    if(i<beg)
        beg=i;
    if(j+1>end)
        end=j+1;
  }
  for(i=end-1;i>=beg;--i)
  {
    edge[++m].x=i+1;
    edge[m].y=i;
    edge[m].value=0;
  }
  for(i=beg;i<end;++i)
  {
    edge[++m].x=i;
    edge[m].y=i+1;
    edge[m].value=1;
  } 
  for(i=beg;i<=end;++i)
     d[i]=INF;
  d[end]=0;flag=1;
  for(i=beg;i<end&&flag;++i)
  {
     flag=0;
     for(j=1;j<=m;++j)
         if(d[edge[j].y]>d[edge[j].x]+edge[j].value)
             d[edge[j].y]=d[edge[j].x]+edge[j].value,flag=1;
  }
  printf("%d\n",-d[beg]);
  return 0;
}

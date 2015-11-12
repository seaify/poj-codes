#include<stdio.h>
const int INF=1000000010;
int i,j,c,m,flag,ML,MD,N,d[1100];
struct node
{
  int x,y,value;
};
node edge[50000];
int main()
{
  scanf("%d%d%d",&N,&ML,&MD);
  m=0;
  while(ML--)
  {
    scanf("%d%d%d",&i,&j,&c);
    edge[++m].x=i;
    edge[m].y=j;
    edge[m].value=c;
  }
  while(MD--)
  {
    scanf("%d%d%d",&i,&j,&c);
    edge[++m].x=j;
    edge[m].y=i;
    edge[m].value=-c;
  }
  for(i=1;i<N;++i)
  {
    edge[++m].x=i+1;
    edge[m].y=i;
    edge[m].value=0;
  }
  for(i=1;i<=N;++i)
      d[i]=INF;
  d[1]=0;flag=1;
  for(i=1;i<N&&flag;++i)
  {
    flag=0;
    for(j=1;j<=m;++j)
        if(d[edge[j].y]>d[edge[j].x]+edge[j].value)
            d[edge[j].y]=d[edge[j].x]+edge[j].value,flag=1;
  }
  flag=1;
  for(j=1;j<=m;++j)
        if(d[edge[j].y]>d[edge[j].x]+edge[j].value)
        {
          flag=0;
          break;
        }
  if(!flag)
       printf("-1\n");
  else if(d[N]==INF)
       printf("-2\n");
  else
       printf("%d\n",d[N]);
}

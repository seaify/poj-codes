#include<stdio.h>
#include<string.h>
int dir[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
int p,q,T,tag;
bool flag[100][100];
struct node
{
  int x,y;
};
node edge[100];
void dfs(int x,int y,int tot)
{
   int i,c,d;
   if(tot==p*q)
   {
      tag=1;
      return ;
   }
   for(i=0;i<=7;++i)
   {
      c=x+dir[i][0];
      d=y+dir[i][1];
      if(tag==1)
          return ;
      if(c<1||c>p||d<1||d>q||flag[c][d])
          continue;
      flag[c][d]=true;
      edge[tot+1].x=c;
      edge[tot+1].y=d;
      dfs(c,d,tot+1);
      flag[c][d]=false;
   } 
}
int main()
{
  int i,j,t;
  scanf("%d",&T);
  t=0;
  while(T--)
  {
    scanf("%d%d",&p,&q);
    tag=0;
    for(j=1;j<=q;++j)
    {
      for(i=1;i<=p;++i)
      {
         memset(flag,false,sizeof(flag));
         flag[i][j]=true;edge[1].x=i;edge[1].y=j;
         dfs(i,j,1);
       //  printf("%d ",tag);
         if(tag)
             break;
      }
      if(tag)
          break;
    }
    printf("Scenario #%d:\n",++t);
    if(tag)
    {
       for(i=1;i<=p*q;++i)
          printf("%c%d",'A'+edge[i].y-1,edge[i].x);
       printf("\n");
    }
    else
      printf("impossible\n"); 
    if(T>0)
        printf("\n");
  }
  return 0;
}

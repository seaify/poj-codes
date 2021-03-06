#include <stdio.h>
#include <string.h>
int link[600],first[600];//link[M],first[N]
bool flag[600],map[600][600];//flag[M]
int N,M,tot;
struct node
{
  int x,y,next;
};
node g[251000];
int dfs(int p)
{
  int temp;
  temp=first[p];
  while(temp!=-1)
  {
	if(!flag[g[temp].y])
	{
	  flag[g[temp].y]=true;
	  if(link[g[temp].y]==-1||dfs(link[g[temp].y]))
	  {
		  link[g[temp].y]=p;
		  return 1;
	  }
	} 
	temp=g[temp].next;
  }
return 0;
}
void add(int x,int y)//加入
{
   ++tot;
   g[tot].x=x;
   g[tot].y=y;
   g[tot].next=first[x];
   first[x]=tot;
}
int solve()
{
  int i,res=0;
  for(i=1;i<=M;i++)
      link[i]=-1;
  for(i=1;i<=N;i++)
  {
   memset(flag,false,sizeof(flag));
   if(dfs(i))
      res++;
  }
  return res;
}
int main()
{
 int i,j,k;
 while(EOF!=scanf("%d%d",&N,&k))
 {
  if(N==0&&k==0)
	  break;
  M=N;
  tot=0;
  for(i=1;i<=N;i++)
	  first[i]=-1;
  memset(map,false,sizeof(map));
  while(k--)
  {
	  scanf("%d%d",&i,&j);
      map[i][j]=true;
	  add(i,j);
  }
  for(k=1;k<=N;k++)
	for(i=1;i<=N;i++)
      for(j=1;j<=N;j++)
		  if(!map[i][j]&&map[i][k]&&map[k][j])
		  {
			  map[i][j]=true;
			  add(i,j);
		  }
  printf("%d\n",N-solve());
 }
 return 0;
}



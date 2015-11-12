#include <stdio.h>
#include <string.h>
int link[502],first[500];//link[M],first[N]
bool flag[502];//flag[M]
int N,M,tot,t;
struct node
{
  int x,y,next;
};
node g[50000];
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
 while(EOF!=scanf("%d%d",&N,&M))
 {
  tot=0;
  for(i=1;i<=N;i++)
	  first[i]=-1;
  for(i=1;i<=N;i++)
  {
    scanf("%d",&k);
	while(k--)
	{
	  scanf("%d",&j);
      add(i,j);
	}
  }
  printf("%d\n",solve());
 }
 return 0;
}


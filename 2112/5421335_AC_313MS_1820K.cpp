#include <stdio.h>
#include <string.h>
const int INF=100000000;
int link[100000],first[100000],map[1000][1000];//link[M],first[N]
bool flag[100000];//flag[M]
int N,M,tot,m,C,K,mid,left,right;
struct node
{
  int x,y,next;
};
node g[100000];
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

int init()
{
  int i,j,top,k;
  tot=0;
  for(i=1;i<=N;i++)
	  first[i]=-1;
  top=0;
  for(i=1;i<=K;i++)
    for(k=1;k<=m;++k)
	{ 
	   ++top;
	   for(j=1;j<=C;++j)
		{
		  if(map[i][j+K]<=mid)
               add(top,j);
		}
	}
  if(solve()>=C)
	  return 1;
  return 0;
}

int main()
{
 int i,j,k;
 while(EOF!=scanf("%d %d %d",&K,&C,&m))   //// N个点对应M个点。。。
 {
	for(i=1;i<=K+C;++i)
		 for(j=1;j<=K+C;++j)
		 {
			 scanf("%d",&map[i][j]);   ////
			 if(i!=j&&map[i][j]==0)
				 map[i][j]=INF;
		 }
	for(k=1;k<=K+C;++k)
		for(i=1;i<=K+C;++i)
			for(j=1;j<=K+C;++j)
				if(map[i][k]+map[k][j]<map[i][j])
					map[i][j]=map[i][k]+map[k][j];  ////拆点后构图。。。
   right=0;left=INF;
   for(i=1;i<=K;++i)
	   for(j=K+1;j<=K+C;++j)
		   if(map[i][j]!=INF&&map[i][j]!=0)
		   {
			   if(map[i][j]>right)
				   right=map[i][j];
			   if(map[i][j]<left)
				   left=map[i][j];
		   }
   N=K*m;M=C;
   while(left<=right)
   {
	   mid=(left+right)/2;
	   if(init())
		   right=mid-1;
	   else
		   left=mid+1;
   }
   printf("%d\n",left);
  }
 return 0;
}



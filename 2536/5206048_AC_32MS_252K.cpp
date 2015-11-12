#include <stdio.h>
#include <string.h>
const double eps=1e-6;
int link[502],first[500];//link[M],first[N]
double x1[400],y1[400];
int N,M,tot;
bool flag[502];//flag[M]
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
 int i,j;
 double s,v;
 while(EOF!=scanf("%d %d %lf %lf",&N,&M,&s,&v))
 {
   for(i=1;i<=N+M;++i)
	   scanf("%lf %lf",&x1[i],&y1[i]);
   for(i=1;i<=N;i++)
	  first[i]=-1;
   tot=0;s=s*s*v*v;
   for(i=1;i<=N;i++)
   {
      for(j=N+1;j<=N+M;++j)
		  if((x1[i]-x1[j])*(x1[i]-x1[j])+(y1[i]-y1[j])*(y1[i]-y1[j])-s<eps)
		  {
	         add(i,j-N);  
		  }
   }
  printf("%d\n",N-solve());
 }
 return 0;
}



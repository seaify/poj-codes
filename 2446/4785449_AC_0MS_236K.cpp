#include<stdio.h>
#include<string.h>
const int maxn=50;
int map[maxn][maxn],m,n,k,i,j,res;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool flag[maxn][maxn];
struct node
{
  int x,y;
};
node link[maxn][maxn];
int find(int x,int y)
{
  int i,x1,y1;
  for(i=0;i<4;i++)
  {
	 x1=x+dir[i][0];
	 y1=y+dir[i][1];
	 if(x1>=1&&x1<=m&&y1>=1&&y1<=n&&map[x1][y1]&&!flag[x1][y1])
     {
		flag[x1][y1]=true;
		if(link[x1][y1].x==-1||find(link[x1][y1].x,link[x1][y1].y))
		{
		   link[x1][y1].x=x;
		   link[x1][y1].y=y;
		   return 1;
		}
	 }
  }
  return 0;
}
int main()
{
 scanf("%d%d%d",&m,&n,&k);
 memset(map,true,sizeof(map));
 memset(link,-1,sizeof(link));
 res=m*n-k;
 while(k--)
 {
   scanf("%d%d",&i,&j);
   map[j][i]=false;
 }
 if(res%2!=0)
   printf("NO\n");
 else
 {
 res=res/2;
 for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
		if(map[i][j])
		{
		  if((n%2==1&&((i-1)*n+j)%2==1)||(n%2==0&&((i%2)==(j%2))))
		  {
			memset(flag,false,sizeof(flag));
			if(find(i,j))
				res--;
		  }
		}
  if(res==0)
	  printf("YES\n");
  else
	  printf("NO\n");
 }
 return 0;
}
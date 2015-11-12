#include<stdio.h>
#include<string.h>
const int maxn=50;
int map[maxn][maxn],m,n,k,i,j,res,T,sum;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool flag[maxn][maxn];
char a[maxn][maxn];
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
  scanf("%d",&T);
  while(T--)
  {
   scanf("%d%d",&m,&n);
   for(i=1;i<=m;++i)
      scanf("%s",&a[i][1]);
   memset(map,true,sizeof(map));
   memset(link,-1,sizeof(link));
   sum=0;
   for(i=1;i<=m;++i)
     for(j=1;j<=n;++j)
        if(a[i][j]=='o')
             map[i][j]=false; 
        else
            ++sum;
   res=0;
   for(i=1;i<=m;i++)
     for(j=1;j<=n;j++)
      if(map[i][j])
     {
      if((n%2==1&&((i-1)*n+j)%2==1)||(n%2==0&&((i%2)==(j%2))))
      {
       memset(flag,false,sizeof(flag));
       if(find(i,j))
          ++res;
    }
   }
   res=sum-res;
   printf("%d\n",res);
  }
  return 0;
}

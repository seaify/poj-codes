#include<stdio.h>
#include<string.h>
int dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,-1},{-1,1},{1,1}};
char map[200][200];
int m,n,maxw,sum;
bool flag[11000];
void dfs(int x,int y)
{
   int i,j,k;
   map[x][y]='.';
   for(k=0;k<=7;++k)
   {
       i=x+dir[k][0];
	   j=y+dir[k][1];
	   if(i>=1&&i<=m&&j>=1&&j<=n&&map[i][j]=='W')
		   dfs(i,j);  
   }
}
int main()
{
   int i,j;
   while(EOF!=scanf("%d %d",&m,&n))
   {
	  for(i=1;i<=m;++i)
		  scanf("%s",&map[i][1]);
	  memset(flag,false,sizeof(flag));
	  sum=0;
	  for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			if(map[i][j]=='W')
			{
				dfs(i,j);
			    ++sum;
			}
	  printf("%d\n",sum);
   }
   return 0;
}

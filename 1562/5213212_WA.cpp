#include<stdio.h>
#include<string.h>
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char map[200][200];
int m,n,maxw,sum;
bool flag[11000];
int dfs(int x,int y)
{
   int cur=1,i,j,k;
   map[x][y]='*';
   for(k=0;k<=3;++k)
   {
       i=x+dir[k][0];
	   j=y+dir[k][1];
	   if(i>=1&&i<=m&&j>=1&&j<=n&&map[i][j]=='@')
	   {
		   cur=cur+dfs(i,j);
	   }
   }
   return cur;
}
int main()
{
   int i,j,cnt;
   while(EOF!=scanf("%d %d",&m,&n))
   {
	  if(m==0&&n==0)
		  break;
	  for(i=1;i<=m;++i)
		  scanf("%s",&map[i][1]);
	  memset(flag,false,sizeof(flag));
	  sum=0;
	  for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			if(map[i][j]=='@')
			{
			    cnt=dfs(i,j);
				if(!flag[cnt])
				{
				   ++sum;
				   flag[cnt]=true;
				}
			}
	  printf("%d\n",sum);
   }
   return 0;
}

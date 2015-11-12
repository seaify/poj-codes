#include<stdio.h>
int n,c[1100][1100];
int index(int x)
{
return x&(-x);
} 
int up(int x,int y)//统计a[x][y]的旋转次数
{
int i,j,s;
s=0;
for(i=x;i<=n;i=i+index(i))
   for(j=y;j<=n;j=j+index(j))
         s=s+c[i][j];
s=s&1;
return s;
}
int down(int x,int y,int k)//求以(1,1)，(x,y)分别为左上顶点，右下顶点的矩形区域内的和
{
int i,j;
for(i=x;i>0;i=i-index(i))
  for(j=y;j>0;j=j-index(j))
      c[i][j]=c[i][j]+k;
return 0;
}
int search(int x0,int y0,int x1,int y1)//计算以(x0,y0),(x1,y1)分别为左上顶点，右下顶点的矩形区域内的和
{
  down(x1,y1,1);
  down(x0-1,y1,-1);
  down(x1,y0-1,-1);
  down(x0-1,y0-1,1);
  return 0;
}
int main()
{
int t,x0,y0,x1,y1,m,i,j;char ch[3];
scanf("%d",&t);
while(t--)
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			c[i][j]=0;
	while(m--)
	{
		scanf("%s",ch);
		if(ch[0]=='C')
		{
			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
			search(x0,y0,x1,y1);
		}
		else
		{
			scanf("%d%d",&x0,&y0);
			printf("%d\n",up(x0,y0));
		}
	}
}
return 0;
}


#include<stdio.h>
int n,c[1100][1100];
int index(int x)
{
return x&(-x);
} 
int add(int x,int y,int k)//a[x][y]+k
{
int i,j;
for(i=x;i<=n;i=i+index(i))
   for(j=y;j<=n;j=j+index(j))
    c[i][j]+=k;
return 0;
}
int sum(int x,int y)//求以(1,1)，(x,y)分别为左上顶点，右下顶点的矩形区域内的和
{
int i,j,s=0;
for(i=x;i>0;i=i-index(i))
   for(j=y;j>0;j=j-index(j))
            s+=c[i][j];
    return s;
}
int search(int x0,int y0,int x1,int y1)//计算以(x0,y0),(x1,y1)分别为左上顶点，右下顶点的矩形区域内的和
{
return sum(x1,y1)-sum(x0-1,y1)-sum(x1,y0-1)+sum(x0-1,y0-1);
}
int main()
{
int t,i,j,x0,y0,x1,y1,k;
while(EOF!=scanf("%d",&t))
{
	if(t==0)
	{
	  scanf("%d",&n);
	  for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
			c[i][j]=0;
	}
	else if(t==1)
	{
		scanf("%d%d%d",&x0,&y0,&k);
		add(x0+1,y0+1,k);
	}
	else if(t==2)
	{
		scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
		printf("%d\n",search(x0+1,y0+1,x1+1,y1+1));
	}	
	if(t==3)
		break;
}
return 0;
}


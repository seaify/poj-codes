#include<stdio.h>

const int INF=100000;

int m,n,K;
int map[2000][2000],q[4100000][2];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int solve()
{
    int i,j,x,y,x1,y1,beg,end,tmp,step;
    beg=1;
    end=1;
	q[1][0]=500,q[1][1]=500;
    for(step=1;;step++)
    {
		  tmp=end;
          for(;beg<=tmp;beg++)
		  {
				  x=q[beg][0];
				  y=q[beg][1];
				  for(i=0;i<4;i++)
				  {
					  x1=x+dir[i][0];
					  y1=y+dir[i][1];
					  if(x1==m&&y1==n)
						  return step;
					  if(x1>=0&&x1<=1000&&y1>=0&&y1<=1000&&map[x1][y1]==INF)
					  {
						  ++end;
						  q[end][0]=x1;
						  q[end][1]=y1;
						  map[x1][y1]=step;
						 // printf("%d %d %d\n",x1,y1,step); 
					  }
				  }
		  }
	}
	return 0;
}

int main()
{
	int i,j,x,y;
	while(EOF!=scanf("%d %d %d",&m,&n,&K))
	{
		  m+=500,n+=500;
		  for(i=0;i<=1000;i++)
			  for(j=0;j<=1000;j++)
				  map[i][j]=INF; //
		
          while(K--)
		  {
			  scanf("%d %d",&x,&y);
			  map[x+500][y+500]=-1;
		  }
		  printf("%d\n",solve());
		  
	}
	return 0;
}
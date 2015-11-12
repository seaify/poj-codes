#include<cstdio>


bool map[310][310];
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int N,d[310][310],x0,y0,x1,y1;

struct node
{
	int x,y;
};
node q[9000000];

void bfs()
{
	int i,j,time,beg,right,end,x,y;
	if(x0==x1&&y0==y1)
	{
		printf("0\n");
		return ;
	}
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			map[i][j]=true;
	map[x0][y0]=false;
	q[1].x=x0;
	q[1].y=y0;
	beg=1;
	end=1;
	time=0;
	while(beg<=end)
	{
		time++;
		right=end;
		for( ;beg<=right;++beg)
		{
			for(j=0;j<8;++j)
			{
				x=q[beg].x+dir[j][0];
				y=q[beg].y+dir[j][1];
				if(x<0||x>=N||y<0||y>=N||!map[x][y])
					continue;
				if(x==x1&&y==y1)
				{
					printf("%d\n",time);
					return ;
				}
				q[++end].x=x;
				q[end].y=y;
				map[x][y]=false;  ///每次进入队列..
			}
		}
	}
}

int  main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
       scanf("%d",&N);
	   scanf("%d %d",&x0,&y0);
	   scanf("%d %d",&x1,&y1);
       bfs();
	}
	return 0;
}
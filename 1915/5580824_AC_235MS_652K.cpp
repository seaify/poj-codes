#include<cstdio>
#include<queue>
using namespace std;

bool map[310][310];
int dir[8][2]={2,1,1,2,-1,2,-2,1,-2,-1,-1,-2,1,-2,2,-1};
int N,d[310][310];

struct node
{
	int x,y;
	friend bool operator < (node a,node b)
	{
          return d[a.x][a.y]>d[b.x][b.y];   ////表示距离...
	}
};

node S,T,D;

void bfs()
{
	int i,j,time;
    priority_queue< node,vector < node > > q[2];
	if(S.x==T.x&&S.y==T.y)
	{
		printf("0\n");
		return ;
	}
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			map[i][j]=true;
	map[S.x][S.y]=false;
	q[1].push(S);
	for(time=1; ;time++)
	{
		while(!q[time&1].empty())
		{
             S=q[time&1].top();
			 q[time&1].pop();
			 for(i=0;i<8;++i)
			 {
				 D.x=S.x+dir[i][0];
				 D.y=S.y+dir[i][1];
				 if(D.x<0||D.x>=N||D.y<0||D.y>=N||!map[D.x][D.y])
					 continue;
				 map[D.x][D.y]=false;
				 if(!map[T.x][T.y])
				 {
					 printf("%d\n",time);
					 return ;
				 }
				 q[(time+1)&1].push(D);
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
	   scanf("%d %d",&S.x,&S.y);
	   scanf("%d %d",&T.x,&T.y);
       bfs();
	}
	return 0;
}
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int INF=100000000;
int money,N,M;
int dis[110][11000];
typedef struct node
{
    int y,l,c;
	friend bool operator < (node a,node b)
	{
		if(a.l>b.l)
			return 1;
		return 0;
	}
}node;
node tmp,v;
vector < node > e[110];
priority_queue< node,vector < node > > q;

void SPFA()
{
	int i,j,y,cost,len,min=INF;
	for(i=0;i<N;++i)
		for(j=0;j<100*N;++j)
			dis[i][j]=INF;
	dis[0][0]=0;
	tmp.y=0;tmp.l=0;tmp.c=0;
	q.push(tmp);
	while(!q.empty())
	{
		tmp=q.top();
		q.pop();
		if(tmp.y==N-1)
		{
			min=tmp.l;
			break;
		}
		for(i=0;i<e[tmp.y].size();++i)
		{
             y=e[tmp.y][i].y;
			 cost=tmp.c+e[tmp.y][i].c;
			 len=tmp.l+e[tmp.y][i].l;
			 if(cost<=money&&dis[y][cost]>len)
			 {
                 v.y=y;
				 v.c=cost;
				 v.l=len;
				 dis[y][cost]=len;
				 q.push(v);
			 }
		}
	}
	if(min!=INF)
		printf("%d\n",min);
	else
		printf("-1\n");
}

int main()
{
	int i,x,y,L,C;
	while(EOF!=scanf("%d %d %d",&money,&N,&M))
	{
		for(i=0;i<N;++i)
			e[i].clear();
		while(M--)
		{
			scanf("%d %d %d %d",&x,&y,&L,&C);
			x--;y--;
			tmp.y=y;
			tmp.l=L;
			tmp.c=C;
			e[x].push_back(tmp);
		}
		SPFA();
	}
	return 0;
}
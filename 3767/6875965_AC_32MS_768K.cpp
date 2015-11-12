#include<stdio.h>

const int INF=500000000;

int N,M;
int map[800][800],d[800],ID[800],flag[800];

void Dijkstra(int x)
{
	int i,j,y,v;
    d[x]=0;
	for(i=1;i<=N;i++)
		if(ID[i]==x)
		    flag[i]=1;
	    else
			flag[i]=0;
	for(i=1;i<=N;i++)
	{
        v=INF,y=-1;
		for(j=1;j<=N;j++)
			if(flag[j]&&d[j]<v)
				v=d[j],y=j;
		if(y==-1)
			return ;
		flag[y]=0;
        for(j=1;j<=N;j++)
			if(flag[j]&&d[y]+map[y][j]<d[j])
				d[j]=d[y]+map[y][j];
	}
}

int main()
{
	int i,j,x,y,v,result;
	while(EOF!=scanf("%d",&N)&&N)
	{
		for(i=1;i<=N;i++)
         {
			for(j=1;j<=N;j++)
				map[i][j]=INF;
			map[i][i]=0;
			d[i]=INF;
		}
		scanf("%d",&M);
		while(M--)
		{
			scanf("%d %d %d",&x,&y,&v);
			map[x][y]=map[y][x]=v;
		}
		for(i=1;i<=N;i++)
			scanf("%d",&ID[i]);
		Dijkstra(1);
		Dijkstra(2);
		result=INF;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				if(ID[i]!=ID[j]&&map[i][j]!=INF&&d[i]+d[j]+map[i][j]<result)
					result=d[i]+d[j]+map[i][j];
		if(result==INF)
			printf("-1\n");
		else
			printf("%d\n",result);
	}
	return 0;
}
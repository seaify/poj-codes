#include<cstdio>
#include<cstring>
const int INF=1000000000;
int map[1100][1100],link[1100],d[1100],tree[1100][1100],dis[1100][1100],N,M,Q,v;
int q[1100];
bool flag[1100];

struct node
{
	int x,y,v;
};
node e[110000];

void prime()
{
	int i,j,temp,x;
	memset(flag,true,(N+1)*sizeof(bool));
	for(i=1;i<=N;++i)
		link[i]=1;    
	flag[1]=false;      ////根的父结点是它自己。。。
	for(i=1;i<N;++i)   ////link[i]指示其父结点。。
	{
		temp=INF;x=-1;
		for(j=2;j<=N;++j)
			if(flag[j]&&map[link[j]][j]<temp)
				 temp=map[link[j]][j],x=j;
		if(x==-1)   ////在树完整时,不会出现。
			return ;
		flag[x]=false;  ////更新link数组。。
		for(j=2;j<=N;++j)
			if(flag[j]&&map[x][j]<map[link[j]][j])
				link[j]=x;
	}
	memset(tree,0,sizeof(tree));
	for(i=2;i<=N;++i)    ////
	{
		tree[link[i]][++tree[link[i]][0]]=i;  ///link[i]->i ,
	}
}

void BFS()
{
	int i,j,k,father,top,ls,rs,y,x;
	for(i=1;i<=N;++i)
		dis[i][i]=0;
    q[1]=1;top=1;ls=1;rs=1;
	while(ls<=rs)
	{
		for(i=ls;i<=rs;++i)
		{
			v=q[i];
			for(j=1;j<=tree[v][0];++j)
			{
				q[++top]=y=tree[v][j];
				for(k=1;k<top;++k)
				{
					x=q[k];
					father=link[y];
					if(dis[x][father]>map[y][father])
						dis[y][x]=dis[x][y]=dis[x][father];
					else
						dis[y][x]=dis[x][y]=map[y][father];
				}
			}
		}
		ls=rs+1;
		rs=top;
	}
}

int main()
{
	int i,j,k;
	while(EOF!=scanf("%d %d %d",&N,&M,&Q))
	{
		for(i=1;i<=N;++i)
		{
			for(j=1;j<=N;++j)
				map[i][j]=INF;
			map[i][i]=0;
		}
		for(k=1;k<=M;++k)    ////注意处理重边。。。
		{
			scanf("%d %d %d",&i,&j,&v);
			e[k].x=i,e[k].y=j,e[k].v=v;
			if(v<map[i][j])
				map[i][j]=map[j][i]=v;
		}
		prime();
		BFS();
		/*for(i=1;i<=N;++i)
		{
			for(j=1;j<=N;++j)
				printf("%d ",dis[i][j]);
	  	   printf("\n");
		}*/
		while(Q--)
		{
			scanf("%d %d",&k,&v);
			if(dis[e[k].x][e[k].y]>=v)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}
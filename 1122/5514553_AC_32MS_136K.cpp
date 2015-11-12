#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000000000
#define len 25


int n,map[len][len],dis[len],s,adj[len],path[len],visit[len];
bool finish;

struct node
{
	int dis,num;
}place[len];

void init()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(i==j)map[i][j]=0;
			else map[i][j]=max;
		}
}

int cmp(const void * a,const void * b)
{
	return (*(node *)a).dis > (*(node *)b).dis ? 1:-1;
}

void Dijkastra(int s)//s为源点
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		dis[i]=map[s][i];
		visit[i]=0;
		if(i!=s&&dis[i]<max)path[i]=s;
		else path[i]=-1;
	}

	visit[s]=1;

	for(i=1;i<n;i++)
	{
		int min=max,u;
		for(j=1;j<=n;j++)
			if(visit[j]==0&&dis[j]<min)
			{
				u=j;
				min=dis[j];
			}

			if(min==max)return;//此语句对于非连通图是必须的，表示当前已经不存在路径了

			visit[u]=1;
			for(j=1;j<=n;j++)
				if(visit[j]==0&&map[u][j]<max&&dis[u]+map[u][j]<dis[j])
				{
					dis[j]=dis[u]+map[u][j];
					path[j]=u;
				}
	}
}



int main()
{
	int i,j,pos;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		finish=false;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				int l;
				scanf("%d",&l);
				if(l!=-1)map[j][i]=l;
			}
			scanf("%d",&s);
			pos=0;
			char ch;
			memset(adj,0,sizeof(adj));

			printf("Org\tDest\tTime\tPath\n");
			while(1)
			{
				ch=getchar();
				if(ch==10)break;
				while(!(ch>='0'&&ch<='9'))ch=getchar();
				
				while(ch>='0'&&ch<='9')
				{
					adj[pos]*=10;
					adj[pos]+=ch-'0';
					ch=getchar();
				}
				

		        if(adj[pos]==s)
				{
					printf("%d\t%d\t%d\t%d\n",s,s,0,s);
					adj[pos]=0;
				}
				else pos++;
				if(ch==10)break;
			}
			
			
		
			
				Dijkastra(s);
				for(i=0;i<pos;i++)
				{
					place[i].dis=dis[adj[i]];
					place[i].num=adj[i];
				}
				qsort(place,pos,sizeof(place[0]),cmp);
				
				
				for(i=0;i<pos;i++)
				{
					printf("%d\t%d\t%d\t%d\t",place[i].num,s,place[i].dis,place[i].num);
					int kk=path[place[i].num];
					while(1)
					{
						printf("%d",kk);
						if(kk==s)break;
						else printf("\t");
						kk=path[kk];
					}
					printf("\n");
				}
			
	}
	return 0;			
}
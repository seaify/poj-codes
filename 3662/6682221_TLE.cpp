#include<stdio.h>

const int INF=2000000000;
#define min(a,b) a<b?a:b;

int N,M,K;
int d[1100],flag[1100],c[1100][1100],map[1100][1100];

int Dijkstra(int mid)
{
	int i,j,x,minv;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
			if(map[i][j]==INF)
				c[i][j]=INF;
	        else if(map[i][j]<=mid)
				c[i][j]=0;
	        else
				c[i][j]=1;
   
	for(i=1;i<=N;i++)
		d[i]=INF,flag[i]=1;
	d[1]=0;
	for(i=1;i<=N;i++)
	{
		minv=INF;x=-1;
		for(j=1;j<=N;j++)
			if(flag[j]&&d[j]<minv)
				x=j,minv=d[j];
		if(x==-1)
			return 0;
		if(x==N)
			return d[x]<=K;
		flag[x]=0;
		for(j=1;j<=N;j++)
			if(flag[j]&&d[x]+c[x][j]<d[j])
				d[j]=d[x]+c[x][j];

	}
}

int main()
{
	int i,j,c,x,y,left,mid,right;
	while(EOF!=scanf("%d %d %d",&N,&M,&K))
	{
          for(i=1;i<=N;i++)
		  {
			  for(j=1;j<=N;j++)
				  map[i][j]=INF;
			  map[i][i]=0;
		  }
		  while(M--)
		  {
			  scanf("%d %d %d",&x,&y,&c);
			  map[x][y]=map[y][x]=min(map[x][y],c);
		  }
		  left=1;
		  right=1000000;
		  while(left<=right)
		  {
			  mid=(left+right)/2;
			  if(Dijkstra(mid))
				  right=mid-1;
			  else
				  left=mid+1;
		  }
		  if(left>1000000)
			  printf("-1\n");
		  else
              printf("%d\n",left);
	}
}
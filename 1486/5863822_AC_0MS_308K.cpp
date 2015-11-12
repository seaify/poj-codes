#include<stdio.h>
int x0[5000],y0[5000],x1[5000],y1[5000];
int x[5000],y[5000],link[5000],e[5000][5000];
bool flag[5000];
int n,ans;

int dfs(int x)
{
	int i;
	for(i=1;i<=n;i++)
		if(e[x][i])
		{
           if(!flag[i])
		   {
			   flag[i]=true;
			   if(link[i]==-1||dfs(link[i]))
			   {
				   link[i]=x;
				   return 1;
			   }
		   }
		}
    return 0;
}

int main()
{
	int i,j,t,yes,T=0;
	while(EOF!=scanf("%d",&n))
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%d %d %d %d",&x0[i],&x1[i],&y0[i],&y1[i]);
		for(i=1;i<=n;i++)
			scanf("%d %d",&x[i],&y[i]);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(x0[j]<=x[i]&&x[i]<=x1[j]&&y0[j]<=y[i]&&y[i]<=y1[j])
					e[i][j]=1;
				else
					e[i][j]=0;
		for(i=1;i<=n;i++)
			link[i]=-1;
		for(i=1;i<=n;i++)
		{
            for(j=1;j<=n;j++)
				flag[j]=false;
			dfs(i);
		}
		printf("Heap %d\n",++T);
		yes=0;
		for(i=1;i<=n;i++)
		{
			t=link[i];
			link[i]=-1;
			e[t][i]=0;
			for(j=1;j<=n;j++)
				flag[j]=false;
			if(!dfs(t))
			{
				link[i]=t;
				yes++;
				if(yes>1)
					printf(" ");
				printf("(%c,%d)",'A'+i-1,t);
			}
			e[t][i]=1;
		}
		if(!yes)
			printf("none");
		printf("\n\n");
	}
	return 0;
}
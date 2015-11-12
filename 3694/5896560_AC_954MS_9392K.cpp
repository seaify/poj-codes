#include<stdio.h>
int n,m,tot,cnt,ans,Q;
int first[110000],pre[110000],dep[110000];
int low[110000],ord[110000],c[110000];

struct node
{
	int x,y,next;
};
node e[500000];

void add(int x,int y)
{
	e[++tot].x=x;
	e[tot].y=y;
	e[tot].next=first[x];
	first[x]=tot;
}

void dfs(int p,int x,int depth)
{
	int tmp,y,count=0;
    pre[x]=p;
	dep[x]=depth;
	ord[x]=++cnt;
	low[x]=ord[x];
	tmp=first[x];
	while(tmp!=-1)
	{
		y=e[tmp].y;
		if(y==p)
			count++;
		if(ord[y]==-1)
		{
			dfs(x,y,depth+1);
			if(low[x]>low[y])
				low[x]=low[y];
			if(low[y]==ord[y])
				c[y]=1,ans++;
		}
		else if(y!=p||count>1)
			if(low[x]>low[y])
				low[x]=low[y];
		tmp=e[tmp].next;
	}
}

int LCA(int x,int y)
{
    while(dep[x]>dep[y])
	{
        if(c[x])
		{
			c[x]=0;
			ans--;
		}
		x=pre[x];
	}
	while(dep[y]>dep[x])
	{
		if(c[y])
		{
			c[y]=0;
			ans--;
		}
		y=pre[y];
	}
	while(x!=y)
	{
		if(c[x])
		{
			c[x]=0;
			ans--;
		}
		if(c[y])
		{
			c[y]=0;
			ans--;
		}
		x=pre[x];
		y=pre[y];
	}
	return ans;
}

int main()
{
	int i,x,y,T=0;
	while(EOF!=scanf("%d %d",&n,&m))
	{
        if(n==0&&m==0)
			break;
		for(i=1;i<=n;i++)
			first[i]=-1,ord[i]=-1,c[i]=0;
		tot=0;
		
		while(m--)
		{
			scanf("%d %d",&x,&y);
			add(x,y);
			add(y,x);
		}

		ans=0;
		cnt=0;	

		dfs(-1,1,0);
		
		scanf("%d",&Q);
		printf("Case %d:\n",++T);
		while(Q--)
		{
			scanf("%d %d",&x,&y);
			if(ans==0)
				printf("0\n");
			else
			    printf("%d\n",LCA(x,y));
		}
		printf("\n");
	}
	return 0;
}
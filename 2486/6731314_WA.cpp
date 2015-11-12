#include<stdio.h>
#include<string.h>

#define max(a,b) a>b?a:b;

int N,K,tot,HH;
int a[300],f[300][300],g[300][300],c[300],first[300];

struct node
{
	int x,y,next;
};
node e[1000];

void add(int x,int y)
{
	++tot;
	e[tot].x=x;
	e[tot].y=y;
	e[tot].next=first[x];
	first[x]=tot;
}

void dfs(int x,int p)
{
	int i,j,y,v,tmp;
    for(j=1;j<=K;j++)
		f[x][j]=g[x][j]=0;
	f[x][0]=g[x][0]=a[x];
    tmp=first[x];
	while(tmp!=-1)
	{
		y=e[tmp].y;
        if(y==p)
		{
			tmp=e[tmp].next;
			continue;
		}
		dfs(y,x);
       
		for(i=0;i<=K;i++)
			c[i]=f[x][i];

		for(i=0;i<=K;i++)
			  for(j=0;j+i+1<=K;j++)
				  {
					 v=max(f[x][i]+g[y][j],g[x][i]+f[y][j]);
                     c[j+i+1]=max(c[j+i+1],v);
		          }

		for(i=0;i<=K;i++)
			f[x][i]=c[i];

		for(i=0;i<=K;i++)
			c[i]=g[x][i];

        for(i=0;i<=K;i+=2)
			for(j=0;j+i+2<=K;j+=2)			
				    c[j+i+2]=max(c[j+i+2],g[x][i]+g[y][j]);
		
		for(i=0;i<=K;i++)
			g[x][i]=c[i];

		tmp=e[tmp].next;
	}
}

int main()
{
	int i,x,y,result;
	while(EOF!=scanf("%d %d",&N,&K))
	{
		tot=0;
		for(i=1;i<=N;i++)
		{
			scanf("%d",&a[i]);
			first[i]=-1;
		}
		for(i=1;i<N;i++)
		{
			scanf("%d %d",&x,&y);
			add(x,y);
			add(y,x);
		}
		if(K&1)
			HH=K-1;
		else
			HH=K;
		dfs(1,-1);
		result=f[1][0];
		for(i=1;i<=K;i++)
			result=max(result,f[1][i]);
		printf("%d\n",result);
	}
	return 0;
}
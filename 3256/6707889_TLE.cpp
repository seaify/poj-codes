#include<stdio.h>

int K,N,M,num,tot;
int a[20000],flag[20000],first[20000],v[20000];

struct node
{
	int x,y,next;
};
node e[20000];

void add(int x,int y)
{
	++tot;
	e[tot].x=x;
	e[tot].y=y;
	e[tot].next=first[x];
	first[x]=tot;
}

void dfs(int x)
{
    int y,tmp;
	if(flag[x])
	{
		num=K;
		return ;
	}
	num+=a[x];
	v[x]=0;

	for(tmp=first[x];num<K&&tmp!=-1;tmp=e[tmp].next)
	{
		y=e[tmp].y;
		if(v[y])
			dfs(y);
	}
}

int main()
{
	int i,j,x,y,sum;
	while(EOF!=scanf("%d %d %d",&K,&N,&M))
	{
		for(i=1;i<=N;i++)
			a[i]=0;
		for(i=1;i<=K;i++)
		{
			scanf("%d",&x);
			a[x]++;
			first[i]=-1;
			flag[i]=0;
		}
		tot=0;
		while(M--)
		{
			scanf("%d %d",&x,&y);
			add(y,x);
		}
		sum=0;

		for(i=1;i<=N;i++)
		{
			num=0;
			for(j=1;j<=N;j++)
				v[j]=1;
			dfs(i);
			if(num>=K)
			{
				flag[i]=1;
				++sum;
			}
		}
		printf("%d\n",sum);
	}
}
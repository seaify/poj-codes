#include <stdio.h>

int p[100010];
int e[100010];

void makeSet(int x)
{
	p[x]=-1;
	e[x]=-1;
}

int Find(int x)
{
	int r=x;
	while(p[r]!=-1)r=p[r];
	while(x!=r)
	{
		int q=p[x];
        p[x]=r;
        x=q;
	}
	return r;
}

void Union(int a,int b)
{
    int t1,t2;
    //t1=Find(a);
   // t2=Find(b);
    if(e[a]==-1)e[a]=b;//第一次a，初始化敌人
	if(e[b]==-1)e[b]=a;
	t1=Find(e[a]);//找到根节点
	t2=Find(e[b]);
	if(Find(b)!=t1)p[Find(b)]=t1;//敌人不是自己则设为父节点
	if(Find(a)!=t2)p[Find(a)]=t2;
}

void is(int a,int b)
{
	if(Find(a)==Find(b))//假如根节点相等，输出相同
	{
		printf("In the same gang.\n");
		return;
	}
	 if(e[a]==-1||e[b]==-1)//其中存在没有初始化的，肯定无法确定关系
	{
		printf("Not sure yet.\n");
		return;
	}
	if(Find(e[a])==Find(b))//对方的根节点与敌人根节点相等，确定不同
	{
		printf("In different gangs.\n");
		return;
	}
	printf("Not sure yet.\n");
}

int main()
{
	int m,n,action,i,a,b;
	char ch;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d",&n,&action);
		for(i=1;i<=n;i++)makeSet(i);
		while(action--)
		{
			getchar();
		scanf("%c %d %d",&ch,&a,&b);
		if(ch=='D') 
		{
			Union(a,b);
		}
		else is(a,b);
			
		}
	}
	return 0;
}
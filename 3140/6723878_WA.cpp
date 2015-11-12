#include<stdio.h>

#define min(a,b) a<b?a:b;

long long n,m,tot,sum;
long long a[200000],c[200000],first[200000],flag[200000];

struct node
{
	long long x,y,v,next;
};
node e[420000];

void add(long long x,long long y)
{
	++tot;
	e[tot].x=x;
	e[tot].y=y;
	e[tot].next=first[x];
	first[x]=tot;
}

void dfs(long long x)
{
    long long y,tmp;
	flag[x]=0;
	c[x]=a[x];
	tmp=first[x];
	while(tmp!=-1)
	{
		y=e[tmp].y;
		if(flag[y])
		{
			dfs(y);
			c[x]+=c[y];
		}
		tmp=e[tmp].next;
	}
}

long long check(long long a)
{
	long long t=2*a-sum;
	if(t>=0)
		return t;
	return -t;
}

int main()
{
	long long i,x,y,T=0,result;
	while(EOF!=scanf("%lld %lld",&n,&m))
	{
		if(n==0&&m==0)
			break;
		sum=0;tot=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
			first[i]=-1;
			flag[i]=1;
		}
		while(m--)
		{
			scanf("%lld %lld",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1);
		result=check(2*c[1]-sum);
		for(i=2;i<=n;i++)
			result=min(result,check(2*c[i]-sum));
		printf("Case %lld: %lld\n",++T,result);
	}
	return 0;
}
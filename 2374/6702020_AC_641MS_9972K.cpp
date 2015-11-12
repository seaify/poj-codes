#include<stdio.h>
#include<stdlib.h>

const int maxn=210000;
const long long INF=20000000000LL;
#define min(a,b) a<b?a:b;

int N,S,tot;
int x[60000],y[60000],left[60000],right[60000];
long long f[60000][2];

struct node
{
	int ls,rs,c,a,b;
};
node tree[3*maxn];

int init(int a,int b)
{
    int cur=tot,mid;
	tree[cur].a=a;
	tree[cur].b=b;
	tree[cur].c=0; //颜色
	if(a==b)
	{
		tree[cur].ls=tree[cur].rs=-1;
		return cur;
	}
	mid=(a+b)/2;
	++tot;
	tree[cur].ls=init(a,mid);
	++tot;
	tree[cur].rs=init(mid+1,b);
	return cur;
}

int find(int x,int v) ///v在该区间内..
{
	int mid;
    if(tree[x].c>=0)
		return tree[x].c;
	mid=(tree[x].a+tree[x].b)/2;
	if(v<=mid)
		return find(tree[x].ls,v);
	else
		return find(tree[x].rs,v);
}

void update(int x,int c,int a,int b)
{
    int mid,ls,rs;
	if(x==-1)
		return ;
	if(tree[x].a>b||a>tree[x].b) //不相交.
		return ;
	if(a<=tree[x].a&&b>=tree[x].b)
	{
		tree[x].c=c;
		return ;
	}
	ls=tree[x].ls,rs=tree[x].rs;
	if(tree[x].c>=0)
	{
		tree[ls].c=tree[rs].c=tree[x].c;
		tree[x].c=-1;
	}
	mid=(tree[x].a+tree[x].b)/2;
    if(b<=mid)
		update(ls,c,a,b);
	else if(a>mid)
		update(rs,c,a,b);
	else
	{
		update(ls,c,a,b);
		update(rs,c,a,b);
	}

	if(tree[ls].c>=0&&tree[ls].c==tree[rs].c)
		tree[x].c=tree[ls].c;
}

int main()
{
	int i;
	while(EOF!=scanf("%d %d",&N,&S))
	{
		tot=1;
		init(1,maxn);
		S+=100001;
		for(i=1;i<=N;i++)
		{
			scanf("%d %d",&x[i],&y[i]);
			x[i]+=100001;
			y[i]+=100001;
		}

		x[0]=y[0]=100001;
		for(i=1;i<=N;i++)
		{
			left[i]=find(1,x[i]);
			right[i]=find(1,y[i]);
			update(1,i,x[i],y[i]);
		}

		for(i=0;i<N;i++)
			f[i][0]=f[i][1]=INF;
		f[N][0]=abs(x[N]-S);
		f[N][1]=abs(y[N]-S);
        for(i=N;i>=1;i--)
		{
			f[left[i]][0]=min(f[left[i]][0],f[i][0]+abs(x[i]-x[left[i]]));
			f[left[i]][1]=min(f[left[i]][1],f[i][0]+abs(x[i]-y[left[i]]));
			f[right[i]][0]=min(f[right[i]][0],f[i][1]+abs(y[i]-x[right[i]]));
			f[right[i]][1]=min(f[right[i]][1],f[i][1]+abs(y[i]-y[right[i]]));
		}
		printf("%lld\n",f[0][0]);
	}
	return 0;
}
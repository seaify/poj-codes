#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;

const int maxn=1100000;
#define min(a,b) a<b?a:b;

map<int ,int> H;
int n,m,tot,a[maxn];

struct node
{
	int a,b,ls,rs,min;
};
node tree[3*maxn];

int init(int a,int b)
{
	int cur=tot,mid;
	tree[cur].a=a;
	tree[cur].b=b;
	tree[cur].min=0;
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

void update(int root,int x,int v)
{
    int mid,ls,rs;
	if(tree[root].a==tree[root].b)
	{
		tree[root].min=v;
		return ;
	}
	mid=(tree[root].a+tree[root].b)/2;
	ls=tree[root].ls;
	rs=tree[root].rs;
	if(x<=mid)
		update(ls,x,v);
	else 
		update(rs,x,v);
	tree[root].min=min(tree[ls].min,tree[rs].min);
}

int main()
{
	int i,x,result;
	while(EOF!=scanf("%d",&m))
	{
		H.clear();
		n=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			if(H.count(a[i])==0)
				H[a[i]]=++n;
		}
		tot=1;
		init(1,n);
		result=m;
		for(i=1;i<=m;i++)
		{
			x=H[a[i]];
			update(1,x,i);
			
		//	printf("%d %d\n",tree[1].min,i-tree[1].min+1);
			if(tree[1].min>0&&i-tree[1].min+1<result)
				result=i-tree[1].min+1;
		}
		printf("%d\n",result);
	}
	return 0;
}
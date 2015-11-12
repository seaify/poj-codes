#include<stdio.h>

const int maxn=110000;
#define max(a,b) (a>b)?a:b;
#define min(a,b) (a<b)?a:b;

int a[maxn];
int m,n,tot;

struct node
{
	int a,b,sum,lmax,rmax,lmin,rmin,ls,rs,minv,maxv;
};
node tree[3*maxn];

int init(int a,int b)
{
    int mid,cur;
	cur=tot;
	tree[cur].lmax=tree[cur].rmax=tree[cur].lmin=tree[cur].rmin=0;
	tree[cur].minv=tree[cur].maxv=tree[cur].sum=0;
	tree[cur].a=a,tree[cur].b=b;
	if(a==b)
	{
		tree[cur].ls=tree[cur].rs=-1;
		return cur ;
	}
	mid=(a+b)/2;
	++tot;
	tree[cur].ls=init(a,mid);
	++tot;
    tree[cur].rs=init(mid+1,b);
	return cur;
}

void modify(int root)
{
	int ls,rs,tmp;
	if(root==-1)
		return ;
	ls=tree[root].ls,rs=tree[root].rs;
	tree[root].sum=tree[ls].sum+tree[rs].sum;
	tree[root].lmax=max(tree[ls].lmax,tree[ls].sum+tree[rs].lmax);
	tree[root].lmin=min(tree[ls].lmin,tree[ls].sum+tree[rs].lmin);
	tree[root].rmax=max(tree[rs].rmax,tree[rs].sum+tree[ls].rmax);
	tree[root].rmin=min(tree[rs].rmin,tree[rs].sum+tree[ls].rmin);
	tmp=max(tree[ls].maxv,tree[rs].maxv);
	tree[root].maxv=max(tmp,tree[ls].rmax+tree[rs].lmax);
	tmp=min(tree[ls].minv,tree[rs].minv);
	tree[root].minv=min(tmp,tree[ls].rmin+tree[rs].lmin);
}

void update(int root,int x)
{
	int mid;
	if(root==-1)
		return ;
    if(tree[root].a==x&&tree[root].b==x)
	{
		tree[root].sum=a[x];
		tree[root].lmax=tree[root].rmax=a[x];
		tree[root].lmin=tree[root].rmin=a[x];
		tree[root].maxv=tree[root].minv=a[x];
		return ;
	}
	mid=(tree[root].a+tree[root].b)/2;
	if(x<=mid)
		 update(tree[root].ls,x);
	else
		 update(tree[root].rs,x);
	modify(root);
}

int main()
{
	int i,x,y,result;
	while(EOF!=scanf("%d",&n))
	{
		tot=1;
		init(1,n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			update(1,i);
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d %d",&x,&y);
            a[x]=y;
			update(1,x);
			if(tree[1].maxv==tree[1].sum)
				result=tree[1].sum-tree[1].minv;
			else
				result=max(tree[1].maxv,tree[1].sum-tree[1].minv);
			printf("%d\n",result);
		}
	}
	return 0;
}
#include<stdio.h>

#define max(a,b) a>b?a:b;

int N,M,P,tot;

struct node
{
	int a,b,ls,rs,lmax,rmax,max,flag;
};
node tree[3*20000];


int init(int a,int b)
{
	int cur=tot,mid;
    tree[cur].a=a;
	tree[cur].b=b;
	tree[cur].flag=1;//空
	tree[cur].lmax=tree[cur].rmax=tree[cur].max=b-a+1;
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

void update(int root,int x,int y,int c)
{
	int ls,rs,mid,tmp;
	if(x<=tree[root].a&&tree[root].b<=y)
	{
		tree[root].flag=c;
		tree[root].lmax=tree[root].rmax=tree[root].max=c*(tree[root].b-tree[root].a+1);
		return ;
	}
    mid=(tree[root].a+tree[root].b)/2;
	ls=tree[root].ls;
	rs=tree[root].rs;
	if(tree[root].flag!=-1)
	{
		tree[ls].flag=tree[rs].flag=tree[root].flag;
		tree[ls].lmax=tree[ls].rmax=tree[ls].max=tree[ls].flag*(tree[ls].b-tree[ls].a+1);
		tree[rs].lmax=tree[rs].rmax=tree[rs].max=tree[rs].flag*(tree[rs].b-tree[rs].a+1);
		tree[root].flag=-1;
	}
	if(y<=mid)
		update(ls,x,y,c);
	else if(x>mid)
		update(rs,x,y,c);
	else
	{
		update(ls,x,y,c);
		update(rs,x,y,c);
	}
	tmp=max(tree[ls].max,tree[rs].max);
    tree[root].max=max(tmp,tree[ls].rmax+tree[rs].lmax);
    if(tree[ls].flag==1)
		tree[root].lmax=tree[ls].lmax+tree[rs].lmax;
	else
		tree[root].lmax=tree[ls].lmax;
	if(tree[rs].flag==1)
		tree[root].rmax=tree[rs].rmax+tree[ls].rmax;
	else
		tree[root].rmax=tree[rs].rmax;
	if(tree[ls].flag!=-1&&tree[ls].flag==tree[rs].flag)
		tree[root].flag=tree[ls].flag;
}

int main()
{
	int op,x,size;
	while(EOF!=scanf("%d %d",&N,&P))
	{
		tot=1;
		init(1,N);
		while(P--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d %d",&x,&size);
				update(1,x,x+size-1,0);  ////占据
			}
			else if(op==2)
			{
				scanf("%d %d",&x,&size);
				update(1,x,x+size-1,1); //清空
			}
			else
				printf("%d\n",tree[1].max);
		}
	}
	return 0;
}
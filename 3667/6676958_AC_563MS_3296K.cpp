#include<stdio.h>

const int maxn=51000;
#define max(a,b) a>b?a:b;

int n,m,tot;

struct node
{
	int a,b,ls,rs,lmax,rmax,max,tag; //
};
node tree[3*maxn];

int init(int a,int b)
{
    int mid,cur;
	cur=tot;
	tree[cur].a=a,tree[cur].b=b;tree[cur].tag=1; //  表示整段为空
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

void debug()
{
	int i;
	for(i=1;i<=tot;i++)
		printf("%d %d %d %d\n",tree[i].lmax,tree[i].rmax,tree[i].max,tree[i].tag);
	printf("\n");
}

int dfs(int root,int size)
{
	int ls,rs,k;
	if(root==-1) 
		return 0;
	if(tree[root].max<size)
		return 0;
	if(tree[root].a==tree[root].b)
		return tree[root].a;

	ls=tree[root].ls;
	rs=tree[root].rs;

	if(tree[root].tag!=-1)
	{
		tree[ls].tag=tree[rs].tag=tree[root].tag;
		tree[ls].lmax=tree[ls].rmax=tree[ls].max=tree[ls].tag*(tree[ls].b-tree[ls].a+1);
		tree[rs].lmax=tree[rs].rmax=tree[rs].max=tree[rs].tag*(tree[rs].b-tree[rs].a+1);
	}

	if(tree[ls].max>=size)
        return dfs(ls,size);
	else if(tree[ls].rmax+tree[rs].lmax>=size)
		return tree[ls].b+1-tree[ls].rmax;
	else
		return dfs(rs,size);
}

void update(int root,int x,int y,int k)
{
	int ls,rs,mid,tmp;
	if(root==-1)
		return ;
	if(tree[root].b<x||tree[root].a>y)
		return ;
	if(tree[root].a>=x&&tree[root].b<=y)
	{
		tree[root].tag=k; //k为0时表示满，1表示空.
		tree[root].lmax=tree[root].rmax=tree[root].max=k*(tree[root].b-tree[root].a+1);
		return ;
	}
	
	ls=tree[root].ls;
	rs=tree[root].rs;

    if(tree[root].tag!=-1)
	{
		tree[ls].tag=tree[rs].tag=tree[root].tag;
		tree[ls].lmax=tree[ls].rmax=tree[ls].max=tree[ls].tag*(tree[ls].b-tree[ls].a+1);
		tree[rs].lmax=tree[rs].rmax=tree[rs].max=tree[rs].tag*(tree[rs].b-tree[rs].a+1);
		tree[root].tag=-1;
	}

    mid=(tree[root].a+tree[root].b)/2;
	if(y<=mid)
		update(ls,x,y,k);
	else if(x>mid)
		update(rs,x,y,k);
	else
	{
		update(ls,x,y,k);
		update(rs,x,y,k);
	}
    tmp=max(tree[ls].max,tree[rs].max);
	tree[root].max=max(tmp,tree[ls].rmax+tree[rs].lmax);
	tree[root].lmax=tree[ls].lmax;
	if(tree[ls].tag==1)
		tree[root].lmax+=tree[rs].lmax;

	tree[root].rmax=tree[rs].rmax;
	if(tree[rs].tag==1)
		tree[root].rmax+=tree[ls].rmax;

	if(tree[ls].tag!=-1&&tree[ls].tag==tree[rs].tag)
		    tree[root].tag=tree[ls].tag;
    ////           成段更新,添加标记
}


int main()
{
	int op,x,y,result;
	//freopen("hotel.3.in","r",stdin);
	//freopen("check.txt","w",stdout);
	while(EOF!=scanf("%d %d",&n,&m))
	{
		tot=1;
		init(1,n);
		while(m--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d",&x);
                result=dfs(1,x);
			//	debug();
				if(result)
				    update(1,result,result+x-1,0);
				printf("%d\n",result);
			}
			else
			{
				scanf("%d %d",&x,&y);
                update(1,x,x+y-1,1);
			}
		//	debug();
		}
	}
	return 0;
}
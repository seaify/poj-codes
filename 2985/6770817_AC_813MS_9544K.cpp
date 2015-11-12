#include<stdio.h>

int N,M,K,tot;
int p[210000],size[210000];

struct node
{
    int a,b,ls,rs,sum;
};
node tree[3*210000];

int make(int a,int b)
{
    int cur=tot,mid;
    tree[cur].a=a;
    tree[cur].b=b;
	if(a==1)
        tree[cur].sum=N;
	else
		tree[cur].sum=0;
    if(tree[cur].a==tree[cur].b)
    {
		tree[cur].ls=tree[cur].rs=-1;
		return cur;
    }
    mid=(a+b)/2;
    ++tot;
    tree[cur].ls=make(a,mid);
    ++tot;
    tree[cur].rs=make(mid+1,b);
    return cur;
}

void init()
{
    int i;
    for(i=1;i<=N;i++)
		p[i]=-1,size[i]=1;
}

int Find(int x)
{
    int r=x,tmp;
    while(p[r]!=-1)
		r=p[r];
    while(x!=r)
    {
		tmp=p[x];
		p[x]=r;
		x=tmp;
    }
    return r;
}

void Union(int t1,int t2)
{
    if(size[t1]<=size[t2])
    {
		p[t1]=t2;
		size[t2]+=size[t1];
    }
    else
    {
		p[t2]=t1;
		size[t1]+=size[t2];
    }
}

void update(int root,int v,int c)
{
    int mid;
    tree[root].sum+=c;
    if(tree[root].a==tree[root].b)
	  		return ;
    mid=(tree[root].a+tree[root].b)/2;
    if(v<=mid)
		update(tree[root].ls,v,c);
    else
		update(tree[root].rs,v,c);
}

void dfs(int root,int rank)
{
    int ls,rs;
    if(tree[root].a==tree[root].b)
    {
		printf("%d\n",tree[root].a);
		return ;
    }
    ls=tree[root].ls;
    rs=tree[root].rs;
    if(tree[ls].sum>=rank)
		dfs(ls,rank);
    else
		dfs(rs,rank-tree[ls].sum);
}

int main()
{
    int op,x,y,t1,t2;
    while(EOF!=scanf("%d %d",&N,&M))
    {
		tot=1;
		init();
		make(1,N);
		while(M--)
		{
	  	  scanf("%d",&op);
		  if(op==0)
		  {
			scanf("%d %d",&x,&y);
			t1=Find(x);
			t2=Find(y);
			if(t1==t2)
			    continue;
            update(1,size[t1],-1);
			update(1,size[t2],-1);
			update(1,size[t1]+size[t2],1);
			Union(t1,t2);
	    }
	    else
	    {
			scanf("%d",&K);
            dfs(1,tree[1].sum+1-K);
	    }
	}
    }
    return 0;
}
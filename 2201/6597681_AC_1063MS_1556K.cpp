#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn=210000;

int h[maxn],st[maxn],n;

struct node
{
	int ls,rs,no;
};
node tree[maxn],a[maxn];

int cmp(node a,node b)
{
	return a.ls<b.ls;
}

int check(int x)
{
	return a[x].no;
}

int calc()
{
	int i,k,tmp,top=0;
	for(i=1;i<=n;i++)
	{
		tmp=a[i].no;
		tree[tmp].ls=tree[tmp].rs=tree[tmp].no=0;
		k=top;
		while(k>=1&&a[st[k]].rs>a[i].rs)
			  k--;
		if(k!=0)
			tree[check(st[k])].rs=tmp,tree[tmp].no=check(st[k]);
		if(k<top)
			tree[tmp].ls=check(st[k+1]),tree[check(st[k+1])].no=tmp;
        
		st[++k]=i;
		top=k;
	}
	return st[1];
}

int main()
{
	int i,j,root;
	
	while(EOF!=scanf("%d",&n))
	{

		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a[i].ls,&a[i].rs);
			a[i].no=i;
		}

		sort(a+1,a+n+1,cmp);

        calc();

		printf("YES\n");
		for(i=1;i<=n;i++)
			printf("%d %d %d\n",tree[i].no,tree[i].ls,tree[i].rs);

	}
		
}
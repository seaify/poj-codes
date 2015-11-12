#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,flag;

struct node
{
	char a[12];
	int len;
};

node e[11000];

struct tree
{
	int tag;
	tree *node[10];
	tree()
	{
		int i;
		for(i=0;i<10;i++)
			node[i]=NULL;
	}
}*root;

int cmp(node a,node b)
{
	return a.len>b.len;
}

void insert(tree *p,char *s)
{
	int c=(*s)-'0',tag=0;
	if(p->node[c])
		p=p->node[c];
	else
	{
		p->node[c]=new tree;
		p=p->node[c];
		tag=1;
	}

	if(s[1])
		insert(p,s+1);
	else
        flag=tag; 
}

int main()
{
	int i,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",e[i].a);
			e[i].len=strlen(e[i].a);
		}
		sort(e,e+n,cmp);

		root=new tree();
        
		flag=1;
		for(i=1;i<=n&&flag;i++)
			insert(root,e[i].a);

		if(flag)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
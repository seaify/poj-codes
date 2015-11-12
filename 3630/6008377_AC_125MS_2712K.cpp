#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,tot,flag,root;

struct node
{
	char a[12];
	int len;
};

node e[11000];

struct tree
{
	int tag;
	int node[10];
};
tree q[1000000];

int cmp(node a,node b)
{
	return a.len>b.len;
}

void init()
{
	int i;
	++tot;
    for(i=0;i<10;i++)
		q[tot].node[i]=0;
}

void insert(int p,char *s)
{
	int c=(*s)-'0',tag=0;
	if(q[p].node[c])
		p=q[p].node[c];
	else
	{
		init();
		q[p].node[c]=tot;
		p=tot;
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

		tot=0;
		init();
		
        
		flag=1;
		for(i=0;i<n&&flag;i++)
			insert(1,e[i].a);

		if(flag)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
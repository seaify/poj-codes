#include<stdio.h>
#include<string.h>
#include<math.h>
int x,n,block,size,rank;
char c[110000],ch[2];

struct node
{
	int count;
	char a[4002];
};

node e[2100];

void query()
{
    for(x=1;x<=size;x++)
	{
		if(rank>e[x].count)
			rank-=e[x].count;
		else
			return ;
	}
}

void insert()
{
	int i;
    if(rank>n)
	    e[size].a[++e[size].count]=ch[0];
	else
	{
	  query();
	  for(i=e[x].count;i>=rank;i--)  ///移位..
		e[x].a[i+1]=e[x].a[i];
 	  e[x].a[rank]=ch[0];
	  e[x].count++;
	}
	n++;
}

int main()
{
	int i,j,m,begin,end;
 
	scanf("%s",c+1);///未涉及到删除操作...,只会分离
	n=strlen(c+1);
	block=int(sqrt(n*1.0));
	block++;
	if(n%block)
			size=n/block+1;
	else
			size=n/block;

	for(i=1;i<=size;i++)
	{
			begin=(i-1)*block+1;
			end=i*block<n?i*block:n;
			e[i].count=end-begin+1;
			for(j=begin;j<=end;j++)
				e[i].a[j-begin+1]=c[j];
	}

	scanf("%d",&m);
	while(m--)
		{
			scanf("%s",ch);
			if(ch[0]=='Q')
			{
				scanf("%d",&rank);
				query();
				printf("%c\n",e[x].a[rank]);
			}
			else
			{
				scanf("%s %d",ch,&rank);
				insert();
			}
		}
	
	return 0;
}


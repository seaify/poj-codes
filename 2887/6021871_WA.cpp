#include<stdio.h>
#include<string.h>
#include<math.h>
int x,n,block,size,rank,tail;
char c[110000],ch[2];

struct node
{
	int count;
	char a[3002];
	int next;
};

node e[2100];

void query()
{
	x=1;
	while(x!=-1)
	{
		if(e[x].count<rank)
		{
			rank-=e[x].count;
			x=e[x].next;
		}
		else	
            return ; 
	}
}

void insert()
{
	int i;
    if(rank>n)
	{
	   x=tail;
       e[x].a[e[x].count+1]=ch[0];
	}
	else
	{
	  query();
	  for(i=e[x].count;i>=rank;i--)  ///移位..
		e[x].a[i+1]=e[x].a[i];
 	  e[x].a[rank]=ch[0];
	}

	e[x].count++;


	if(e[x].count==2*block)
	{
		++size;
		for(i=1;i<=block;i++)
			e[size].a[i]=e[x].a[i+block];

		e[size].next=e[x].next;
		e[size].count=block;
		e[x].next=size;
		e[x].count=block;
		if(e[size].next==-1)
			tail=size;
	}

}

int main()
{
	int i,j,m,begin,end;

 
	gets(c+1);///未涉及到删除操作...,只会分离
	
        n=strlen(c+1);
		block=ceil(sqrt(n*1.0));
		
		if(n%block)
			size=n/block+1;
		else
			size=n/block;

		for(i=1;i<=size;i++)
		{
			begin=(i-1)*block+1;
			end=i*block<n?i*block:n;

			e[i].next=i+1;
			e[i].count=end-begin+1;

			for(j=begin;j<=end;j++)
				e[i].a[j-begin+1]=c[j];
		}

		e[size].next=-1;
		tail=size;
       
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
				n++;
			}
		}

	
	return 0;
}


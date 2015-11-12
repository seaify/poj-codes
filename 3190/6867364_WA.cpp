#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
using namespace std;

struct node
{
	int p,v;
};
node e[200000];

int n,size,a[100000],heap[200000];

int cmp(node a,node b)
{
	return abs(a.v)<abs(b.v);
}

void push(int s) 
{
	int i,tmp;
	heap[++size]=s;
	i=size;
	while(i>1&&heap[i/2]>heap[i])
	{
		tmp=heap[i];
		heap[i]=heap[i/2];
		heap[i/2]=tmp;
		i=i/2;
	}
}

int del()
{
	int i,l,r,min,tmp,vx;
	tmp=heap[1];
	heap[1]=heap[size--];
	i=1;
	while(1)
	{
		l=2*i;
		r=2*i+1;
		min=i;
		if(l<=size&&heap[l]<heap[i]) //取出较小元素置为根。。。
			min=l;
		if(r<=size&&heap[r]<heap[min])
			min=r;
		if(min!=i)
		{
			vx=heap[i];
			heap[i]=heap[min];
			heap[min]=vx;
			i=min;
		}
		else
			break;
	}
    return tmp;
}


int main()
{
	int i,x,y,tmp,result;
	while(EOF!=scanf("%d",&n))
	{
		size=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&y);
            e[i].p=i;
			e[i].v=x;
			e[i+n].p=i;
			e[i+n].v=-y;
	        push(i);		
		}
		sort(e+1,e+2*n+1,cmp);
		result=0;
		for(i=1;i<=2*n;i++)
		{
			if(e[i].v>0)
			{
				tmp=del();
				if(tmp>result)
				   result=tmp;
				a[e[i].p]=tmp;
			}
			else
                push(a[e[i].p]);
		}
		printf("%d\n",result);
		for(i=1;i<=n;i++)
			printf("%d\n",a[i]);
	}
}
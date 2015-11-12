#include<stdio.h>
#include<algorithm>
using namespace std;
int n,size,heap[20000];

struct node
{
	int x,t;
};

node a[11000];

int cmp(node a,node b)
{
	return a.t<b.t;
}

void insert(int s) 
{
	int i;
	int tmp;
	heap[++size]=s;
	i=size;
	while(i>1&&heap[i/2]<=heap[i])
	{
		tmp=heap[i];
		heap[i]=heap[i/2];
		heap[i/2]=tmp;
		i=i/2;
	}
}

int del()
{
	int i,l,r,max;
	int tmp,vx;
	tmp=heap[1];
	heap[1]=heap[size--];
	i=1;
	while(1)
	{
		l=2*i;
		r=2*i+1;
		max=i;
		if(l<=size&&heap[l]>heap[i]) //取出较小元素置为根。。。
			max=l;
		if(r<=size&&heap[r]>heap[max])
			max=r;
		if(max!=i)
		{
			vx=heap[i];
			heap[i]=heap[max];
			heap[max]=vx;
			i=max;
		}
		else
			break;
	}
    return tmp;
}


int main()
{
	int i,j,c,tmp,sum;
	while(EOF!=scanf("%d",&n))
	{
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		for(i=1;i<=n;i++)
			scanf("%d %d",&a[i].x,&a[i].t);

		sort(a+1,a+n+1,cmp);

		tmp=0;
		sum=0;

		for(i=1;i<=n;)
		{
			c=a[i].t-tmp;
			j=i;
            size=0;
			while(a[j].t==a[i].t)
			{
                insert(a[j].x);
				j++;		
			}
			while(c--&&size)
				sum+=del();		
			tmp=a[i].t;
			i=j;
		}
		printf("%d\n",sum);
	}
	return 0;
}

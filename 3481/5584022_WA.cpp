#include<cstdio>
#include<cstring>

int size;

struct Q
{
	int state;
	int cost;
};
Q heap[5000000],tmp,vx;

void insert(Q s) 
{
	int i;
	Q tmp;
	heap[++size]=s;
	i=size;
	while(i>1&&heap[i/2].cost>heap[i].cost)
	{
		tmp=heap[i];
		heap[i]=heap[i/2];
		heap[i/2]=tmp;
		i=i/2;
	}
}

struct Q del()
{
	int i,l,r,min;
	Q tmp,vx;
	tmp=heap[1];
	heap[1]=heap[size--];
	i=1;
	while(1)
	{
		l=2*i;
		r=2*i+1;
		min=i;
		if(l<=size&&heap[l].cost<heap[i].cost) //取出较小元素置为根。。。
			min=l;
		if(r<=size&&heap[r].cost<heap[min].cost)
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
	int T;
	size=0;
    while(EOF!=scanf("%d",&T))
	{
		if(T==0)
			break;
		if(T==1)
		{
			scanf("%d %d",&tmp.state,&tmp.cost);
			insert(tmp);
			continue;
		}
		if(size==0)
		{
			printf("0\n");
			continue;
		}
	    if(T==2)
			printf("%d\n",heap[size--].state);
		else
			printf("%d\n",del().state);
	}
	return 0;
}
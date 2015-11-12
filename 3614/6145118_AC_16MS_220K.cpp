#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000;

int size,C,L,pt;
int heap[maxn];

struct node
{
    int x,y;
};

node cow[3000],sun[3000];

int cmp(node a,node b)
{
    return a.x<b.x;
} 

void insert(int s) 
{
	int i;
	int tmp;
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
	int i,l,r,min;
	int tmp,vx;
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
    int i,sum;
	while(EOF!=scanf("%d %d",&C,&L))
	{
         for(i=1;i<=C;i++)
            scanf("%d %d",&cow[i].x,&cow[i].y);
            
         for(i=1;i<=L;i++)
            scanf("%d %d",&sun[i].x,&sun[i].y);
            
         sort(cow+1,cow+C+1,cmp);
         sort(sun+1,sun+L+1,cmp); 
         
         pt=1;
         size=0;
         sum=0;
         
         for(i=1;i<=L;i++)
         {
            for(;pt<=C&&cow[pt].x<=sun[i].x;pt++)
            {
                if(sun[i].x<=cow[pt].y)
                   insert(cow[pt].y);
            }  
            
            while(size>=1&&heap[1]<sun[i].x)
                del();
            
            while(size>=1&&heap[1]>=sun[i].x&&sun[i].y>0)
            {
                del();
                sun[i].y--;
                sum++;
            }
            
         
            
         }
         
         printf("%d\n",sum);
    }
	return 0;
}

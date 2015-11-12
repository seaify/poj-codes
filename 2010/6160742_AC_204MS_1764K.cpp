#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int heap[30000];
int up[110000],down[110000];
int size,sum,big,N,C,F;


struct node
{
    int score,cost;
};

node cow[110000];

int cmp(node a,node b)
{
    if(a.score!=b.score) 
        return a.score<b.score; ////wait 
    return a.cost<b.cost;
} 

void insert(int s) 
{
	int i;
	int tmp;
	heap[++size]=s;
	i=size;
	while(i>1&&heap[i/2]<heap[i])
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
		if(l<=size&&heap[l]>heap[i]) //
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

void solve(int i)
{
     down[i]=0;
     if(size==big)
           down[i]=sum;
     if(size<big)
     {
           insert(cow[i].cost);   
           sum+=cow[i].cost;
     }
     else 
     {
           if(cow[i].cost>=heap[1])
                  return ;
           sum+=cow[i].cost-heap[1];
           del();
           insert(cow[i].cost); 
     }           
}

int main()
{
    int i,flag;
	while(EOF!=scanf("%d %d %d",&N,&C,&F))
	{
         for(i=1;i<=C;i++)
            scanf("%d %d",&cow[i].score,&cow[i].cost); 
         sort(cow+1,cow+C+1,cmp);
         
         big=(N-1)/2;
         
         size=0;
         sum=0;
         for(i=C;i>=1;i--)
         {
            solve(i);
            up[i]=down[i];
         }
         
         size=0;
         sum=0;
         for(i=1;i<=C;i++)
            solve(i);
            
         flag=1;
         
         for(i=C-big;i>=big+1;i--)
             if(up[i]+down[i]+cow[i].cost<=F)
             {
                  flag=0;
                  printf("%d\n",cow[i].score);
                  break;
             }
             
         if(flag)
             printf("-1\n");

             
    }
	return 0;
}


#include<stdio.h>
#include<algorithm>
using namespace std;
int n,l,p,size,ans;
int heap[11000];

struct node
{
    int x,y;
};
node e[11000];

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
	int i,l,r,t;
	int tmp,vx;
	tmp=heap[1];
	heap[1]=heap[size--];
	i=1;
	while(1)
	{
		l=2*i;
		r=2*i+1;
		t=i;
		if(l<=size&&heap[l]>heap[i]) //取出较小元素置为根。。。
			t=l;
		if(r<=size&&heap[r]>heap[t])
			t=r;
		if(t!=i)
		{
			vx=heap[i];
			heap[i]=heap[t];
			heap[t]=vx;
			i=t;
		}
		else
			break;
	}
    return tmp;
}



int main()
{
    int i,tmp;
    while(EOF!=scanf("%d",&n))
    {
          e[0].x=0;
          e[0].y=0;
          for(i=1;i<=n;i++)
                scanf("%d %d",&e[i].x,&e[i].y); 
          scanf("%d %d",&l,&p);
          for(i=1;i<=n;i++)
                e[i].x=l-e[i].x;
          sort(e,e+n+1,cmp);      
          e[n+1].x=l;
          ans=0;
          for(i=0;i<=n;i++)  ///
          {
               if(i)
                    insert(e[i].y);     
               tmp=e[i+1].x-e[i].x;
               if(p>=tmp)
                   p-=tmp;
               else 
               {
                   while(size>=1&&p<tmp)
                   {
                         p+=del();
                         ans++;
                   }
                   if(p<tmp)
                       break;
                   else
                       p-=tmp;
               }                                            
          }
          if(i==n+1)
               printf("%d\n",ans);
          else
               printf("-1\n");            
    }
    return 0;
}

#include<stdio.h>
#include<algorithm>
using namespace std;
const long long INF=(1ll<<60);

int N,M,E,flag,size;
long long f[11000],result;

struct node
{
	int x,y;
	long long cost;
};
node a[11000],q[11000],hh;

int cmp(node a,node b)
{
	if(a.y!=b.y)
	   return a.y<b.y;
	return a.x<b.x;
}

int solve(int cur)
{
	int left=1,mid,right=size;

	if(a[cur].x==M)
	{
		  f[cur]=a[cur].cost;
		  return 1;
	}

	if(size==0||q[size].y+1<a[cur].x)
	{
		  f[cur]=INF;
		  return 0;
	}

	while(left<=right)
	{
		  mid=(left+right)/2;
          if(q[mid].y+1>=a[cur].x)
			  right=mid-1;
		  else
			  left=mid+1;
	}

	f[cur]=f[q[left].x]+a[cur].cost;
	return 1;
}

void del(int cur)
{
	while(size>=1&&q[size].cost>=f[cur])
		  size--;
        ++size;
        q[size].x=cur;
	q[size].y=a[cur].y;
        q[size].cost=f[cur];
}

int main()
{
	int i;
	while(EOF!=scanf("%d %d %d",&N,&M,&E))
	{
		 for(i=1;i<=N;i++)
			 scanf("%d %d %lld",&a[i].x,&a[i].y,&a[i].cost);

		 sort(a+1,a+N+1,cmp);
         size=0;
     //    flag=1;

		 for(i=1;i<=N;i++)
		 {
             solve(i);
			 //printf("%d %d %lld\n",i,flag,f[i]);
			 del(i);
		 }
         
		 result=INF;

		 for(i=1;i<=N;i++)
				 if(a[i].y==E&&f[i]<result)
						 result=f[i];

		 if(result==INF)
			     printf("-1\n");
		 else
		         printf("%lld\n",result);

	}
	return 0;
}
#include<stdio.h>
#include<algorithm>
using namespace std;

int N,L,sum,size;
int p[11000],num[11000],hh[11000],front[11000];

struct node
{
	int cost,deadline;
};
node a[11000];

int cmp(node a,node b)
{
	return a.cost>b.cost;
}

void init(int x)
{
     p[x]=-1;
	 num[x]=1;
	 front[x]=x;
}

int find(int x)
{
    int r=x,tmp;
	
	while(p[r]!=-1)
		r=p[r];

	while(x!=r)
	{
		tmp=p[x];
		p[x]=r;
		x=tmp;
	}
    
	return r;
}

void Union(int a,int b)
{
	int t1,t2;
	
	t1=find(a),t2=find(b);

	if(t1==t2)
		return ;

	if(num[t1]>=num[t2])
	{
		p[t2]=t1;
		num[t1]+=num[t2];
		front[t1]=b;
	}
	else
	{
		p[t1]=t2;
		num[t2]+=num[t1];
		front[t2]=b;
	}
}

int main()
{
	int i,x,root;

	while(EOF!=scanf("%d %d",&N,&L))
	{
		 size=0;
		 for(i=1;i<=N;i++)
		 {
			 scanf("%d %d",&a[i].cost,&a[i].deadline);
             if(a[i].deadline>size)
				 size=a[i].deadline;
		 }

		 if(N==0||L==0)
		 {
			 printf("0\n");
			 continue;
		 }

		 sort(a+1,a+N+1,cmp);

		 for(i=0;i<=size;i++)
		 {
			 hh[i]=0;
			 init(i);
		 }

		 sum=0;
		 for(i=1;i<=N;i++)
		 {
			 root=find(a[i].deadline);
             x=front[root];
			 if(x==0&&hh[x]==L)
				 continue;

			 hh[x]++;
			 if(x&&hh[x]==L)
				 Union(x,x-1);
             sum+=a[i].cost;
		 }
		 
		 printf("%d\n",sum);
	}
	return 0;
}
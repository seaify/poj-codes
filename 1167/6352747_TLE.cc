#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[400];
int n,flag,result;

struct node 
{
	 int d,v;
};
node c[20];

int cmp(node a,node b)
{
    if(a.d!=b.d)
		return a.d<b.d;
	return a.v+a.d>b.v+b.d;
}

void dfs(int num,int depth)
{
	int i,x,y;
	node hh[20];

	if(depth==n+1)
	{
		 if(c[1].d<=0||num>result)
			 return ;
		 result=num;
		 return ;
	}

	if(num>result)
		return ;

	memcpy(hh,c,sizeof(c));
	sort(c+1,c+num+1,cmp);

	for(i=1;i<=num;i++)
	{
        x=c[i].d,y=c[i].v;


		if(c[i].d<0)
			c[i].d=0;

		else if(c[i].d==0)
		{
			if(a[depth]-c[i].v<=0)
				continue;
			c[i].d=a[depth]-c[i].v;
		}
		else
		{
			if(a[depth]>c[i].d+c[i].v)
				break;
			if(a[depth]<c[i].d+c[i].v)
				continue;
			
		}
		c[i].v=a[depth];
		dfs(num,depth+1);
		c[i].d=x,c[i].v=y;
	}
    
	if(num+1>=result)
	{
		memcpy(c,hh,sizeof(hh));
		return ;
	}

	c[num+1].d=0;
	c[num+1].v=a[depth];
	dfs(num+1,depth+1);
	c[num+1].d=-1;
    memcpy(c,hh,sizeof(hh));
}

int main()
{
	int i;
	while(EOF!=scanf("%d",&n))
	{
		  for(i=1;i<=n;i++)
			  scanf("%d",&a[i]);
		  result=18;
		  for(i=1;i<=20;i++)
			  c[i].d=-1,c[i].v=0;
		  dfs(0,1);
		  printf("%d\n",result);
	}
	return 0;
}
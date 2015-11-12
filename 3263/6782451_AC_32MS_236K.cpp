#include<stdio.h>
#include<algorithm>
using namespace std;

int N,I,H,M,f[40000];

struct node
{
	int x,y;
};
node e[40000],tmp;

int cmp(node a,node b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}

int main()
{
	int i,sum;
	while(EOF!=scanf("%d %d %d %d",&N,&I,&H,&M))
	{
		for(i=1;i<=M;i++)
		{
			scanf("%d %d",&e[i].x,&e[i].y);
			if(e[i].x>e[i].y)
				swap(e[i].x,e[i].y);
		}
		sort(e+1,e+M+1,cmp);
		for(i=1;i<=N;i++)
			f[i]=0;
        for(i=1;i<=M;i++)
			if(i==1||e[i].x!=tmp.x||e[i].y!=tmp.y)
			{
				f[e[i].x+1]--;
				f[e[i].y]++;
				tmp=e[i];
			}
	   sum=0;
	   for(i=1;i<=N;i++)
	   {
		   sum+=f[i];
		   printf("%d\n",sum+H);
	   }
	}
}
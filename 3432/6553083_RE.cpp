#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

set < int > H;

struct node
{
	int x,y;
};
node e[1100];

int n;

int cmp(node a,node b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y>b.y;
}

int main()
{
	int i,j,c,d,result;
	int xmid,ymid,xdis,ydis,x3,y3,x4,y4;

	while(EOF!=scanf("%d",&n)&&n)
	{
		H.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&e[i].x,&e[i].y);
			e[i].x*=2;
			e[i].y*=2;
			c=e[i].x*40000+e[i].y;
			H.insert(c);
		}

		sort(e+1,e+n+1,cmp);

		result=0;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
			{
                  if(e[j].y>=e[i].y)
					  continue;
                  xmid=(e[j].x+e[i].x)/2;
				  ymid=(e[j].y+e[i].y)/2;
				  xdis=(e[j].x-e[i].x)/2;
				  ydis=(e[j].y-e[i].y)/2;

				  x3=xmid-ydis;
				  y3=ymid+xdis;
				  x4=xmid+ydis;
				  y4=ymid-xdis;

				  c=x3*40000+y3;
				  d=x4*40000+y4;
				  if(H.count(c)&&H.count(d))
				  {
				//	  printf("%d %d %d %d\n",e[i].x,e[i].y,e[j].x,e[j].y);
					  ++result;
				  }

			}

        printf("%d\n",result);
	}
	return 0;
}
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m;

struct node
{
	int data,y;
};
node a[110000];

int cmp(node a,node b)
{
	return a.data<b.data;
}

int main()
{
	int i,x,y,c;
	while(EOF!=scanf("%d %d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i].data);
			a[i].y=i;
		}

		sort(a+1,a+n+1,cmp);
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&c);
			for(i=1;i<=n&&c;i++)
				if(a[i].y>=x&&a[i].y<=y)
					c--;
			printf("%d\n",a[i-1].data);
		}
	}
	return 0;
}
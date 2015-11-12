#include<stdio.h>
#include<algorithm>
using namespace std;

struct node
{
	int x,y;
};
node e[100],tmp;

int cmp(node a,node b)
{
	return a.x*b.y>b.x*a.y;
}

int main()
{
	int i=0,c,n;

	//freopen("data","r",stdin);

	while(EOF!=scanf("%d %d",&e[i].x,&e[i].y))
		  i++;

	n=i;
    sort(e+1,e+n,cmp);

	for(i=0;i<n;i++)
		printf("(%d,%d)\n",e[i].x,e[i].y);

}
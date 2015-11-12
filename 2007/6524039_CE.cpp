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
	return (a.x-e[0].x)*(b.y-e[0].y)<(b.x-e[0].x)*(a.y-e[0].y);
}

int main()
{
	int i=0,c,n;
	while(EOF!=scanf("%d %d",&e[i].x,&e[i].y))
	{
		    
		  if(i==0||e[i].y<e[c].y||(e[i].y==e[c].y&&e[i].x<e[c].x))
			  c=i;
		  i++;
	}
	tmp=e[0];
	e[0]=e[c];
	e[c]=tmp;

	n=i;
    sort(e+1,e+n,cmp);
	for(i=0;i<n;i++)
		if(e[i]==tmp)
			break;
	c=i;
	for(i=0;i<n;i++)
		printf("(%d,%d)",a[(c+i)%n].x,a[(c+i)%n].y);

}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	double x,y;
};
node p[1100],t;
int stack[1100];
double pi,s,l;
double multi(node p1, node p2, node p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

double distance(node p1, node p2)
{
   return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int cmp(const void *a, const void *b)
{
	node *c = (node *)a;
    node *d = (node *)b;
    double k = multi(*c, *d, p[0]);
    if(k< 0) return 1;
    else if(k == 0 && distance(*c, p[0]) < distance(*d, p[0])) return 1;
    else return -1;   
}

int main()
{
	int i,n,top;
	scanf("%d%lf",&n,&l);
	for(i=0;i<n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	for(i=1;i<n;i++)
		if(p[i].y<p[0].y||(p[i].y==p[0].y&&p[i].x<p[0].x))
		{
			t=p[0];
			p[0]=p[i];
			p[i]=t;
		}
	qsort(p+1,n-1,sizeof(p[1]),cmp);
	for(i=0;i<=2;i++)
		stack[i]=i;
	top=2;
	for(i=3;i<n;i++)
	{
		while(multi(p[i], p[stack[top]], p[stack[top - 1]]) >= 0)  top--;
        top++;
        stack[top] = i;
	}
	s=0;
	for(i=0;i<=top;i++)
		s=s+distance(p[stack[i]],p[stack[(i+1)%(top+1)]]);
	pi=acos(-1.0);
	s=2*pi*l+s;
	printf("%.0lf\n",s);
	return 0;
}
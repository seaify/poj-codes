#include<stdio.h>
#include<algorithm>
using namespace std;

struct node
{
    int id,f;
    double l;
};

node e[100000];

int cmp(node a,node b)
{
    return b.l*a.f>a.l*b.f;
}

int main()
{
    int i,s,n;
    while(EOF!=scanf("%d",&n))
    {
          for(i=0;i<n;i++)
              scanf("%d %d %lf",&e[i].id,&e[i].f,&e[i].l);
          scanf("%d",&s);
          sort(e,e+n,cmp);
          printf("%d\n",e[s-1].id);
    }
    return 0;
}

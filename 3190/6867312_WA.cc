#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
using namespace std;

struct node
{
	int p,v;
};
node e[200000];

int n,a[100000];
set<int> H;

int cmp(node a,node b)
{
	return abs(a.v)<abs(b.v);
}

int main()
{
	int i,x,y,tmp,result;
	while(EOF!=scanf("%d",&n))
	{
		H.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&y);
            e[i].p=i;
			e[i].v=x;
			e[i+n].p=i;
			e[i+n].v=-y;
			H.insert(i);
		}
		sort(e+1,e+2*n+1,cmp);
		result=0;
		for(i=1;i<=2*n;i++)
		{
			if(e[i].v>0)
			{
				tmp=*H.begin();
			    if(tmp>result)
				   result=tmp;
				a[e[i].p]=tmp;
				H.erase(tmp);
			}
			else
                H.insert(a[e[i].p]);
		}
		printf("%d\n",result);
		for(i=1;i<=n;i++)
			printf("%d\n",a[i]);
	}
}
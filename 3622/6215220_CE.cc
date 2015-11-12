#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int T,n,m,flag;
__int64 sum;

multiset < int > q;
multiset < int > ::iterator it;

struct node
{
	int x,y;
};

node cow[110000],store[110000];

int cmp(node a,node b)
{
    if(a.y!=b.y)
	  return a.y>b.y;   ////
    return a.x>b.x;
}

int main()
{
	int i,j;
	while(EOF!=scanf("%d %d",&n,&m))
	{
		for(i=1;i<=n;i++)
			scanf("%d %d",&cow[i].x,&cow[i].y);
		for(i=1;i<=m;i++)
			scanf("%d %d",&store[i].x,&store[i].y);
		if(n>m)
		{
			printf("-1\n");
			continue;
		}
		
		sort(cow+1,cow+n+1,cmp);
		sort(store+1,store+m+1,cmp);

		sum=0;
		flag=1;
		j=1;
		q.clear();
	

		for(i=1;i<=n;i++)
		{
            while(j<=m&&store[j].y>=cow[i].y)
            {
                  q.insert(store[j].x);
                  j++;
            }

            
            it=q.lower_bound(cow[i].x);

			if(it==q.end())
			{
				flag=0;
				break;
			}

            sum+=*it;
			q.erase(it);
                 
		}

		if(flag)
			printf("%I64d\n",sum);
		else
			printf("-1\n");

	}
	return 0;
}



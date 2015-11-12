#include<cstdio>
#include<set>
using namespace std;
set < int > q;
int N,M,j,v,high,low,top,last[60000];
char ch[5];

int main()
{
	while(EOF!=scanf("%d %d",&N,&M))
	{
		q.clear();
		q.insert(0);
		q.insert(N+1);
		top=0;
		while(M--)
		{
			scanf("%s",ch);
			if(ch[0]=='D')
			{
				scanf("%d",&j);
				last[++top]=j;
				q.insert(j);
			}
			else if(ch[0]=='Q')
			{
				scanf("%d",&v);
				if(q.count(v))
				{
					printf("0\n");
					continue;
				}
				low=*(--q.lower_bound(v));
				high=*q.upper_bound(v);
			//	printf("%d %d\n",low,high);
				printf("%d\n",high-low-1);
			}
			else
			{
				q.erase(last[top--]);
			}
		}
	}
	return 0;
}
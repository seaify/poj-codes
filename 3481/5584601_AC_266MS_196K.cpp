#include<cstdio>
#include<map>
using namespace std;
map < int ,int > q;
map < int ,int > ::iterator it;
int main()
{
	int T,x,y;
    while(EOF!=scanf("%d",&T))
	{
		if(T==0)
			break;
		if(T==1)
		{
			scanf("%d %d",&x,&y);
			q[y]=x;
			continue;
		}
		if(q.size()==0)
		{
			printf("0\n");
			continue;
		}
		if(T==2)
		{
			it=q.end();
			it--;
			printf("%d\n",it->second);
			q.erase(it);
		}
		else
		{
			it=q.begin();
			printf("%d\n",it->second);
			q.erase(it);
		}
	  
	}
	return 0;
}
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int M,N,c[50000],p[50000],i,j,value;
int main()
{
  while(EOF!=scanf("%d %d",&M,&N))
  {
	 priority_queue < int > a,b;
	 for(i=1;i<=M;++i)
		 scanf("%d",&c[i]);
	 p[0]=0;
	 for(i=1;i<=N;++i)
		 scanf("%d",&p[i]);
	 for(i=1;i<=N;++i)
	 {
		for(j=p[i-1]+1;j<=p[i];++j)
		{
		   a.push(c[j]);
		   if(a.size()>i-1)
		   {
			   value=-a.top();
			   a.pop();
			   b.push(value);
		   }

		}
		value=-b.top();
		b.pop();
		a.push(value);
		printf("%d\n",a.top());
	 }
  }
  return 0;
}

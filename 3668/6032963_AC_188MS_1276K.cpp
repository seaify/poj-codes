#include<stdio.h>
#include<set>
using namespace std;
int x[300],y[300],n,top;

set < double > q;

double tmp;

int main()
{
	int i,j;
	while(EOF!=scanf("%d",&n))
	{
		q.clear();

		for(i=0;i<n;i++)
			scanf("%d %d",&x[i],&y[i]);

		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				tmp=double(y[j]-y[i])/double(x[j]-x[i]);
			    if(x[i]==x[j])
					q.insert(10000);
				else
					q.insert(tmp);
			}

	
		printf("%d\n",q.size());

	}
	return 0;
}
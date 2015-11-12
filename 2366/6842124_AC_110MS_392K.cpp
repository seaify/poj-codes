#include<stdio.h>
#include<algorithm>
using namespace std;

int n,m,a[100000],b[100000];

int main()
{
	int i,c,flag;
	while(EOF!=scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(i=1;i<=m;i++)
			scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		flag=0;
		for(i=1;i<=n;i++)
           // if((lower_bound(b+1,b+m+1,10000-a[i])-b-1)==m)
			{
				c=upper_bound(b+1,b+m+1,10000-a[i])-lower_bound(b+1,b+m+1,10000-a[i]);
			//	printf("%d\n",c);

				flag=c;
				if(flag)
					break;
			}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

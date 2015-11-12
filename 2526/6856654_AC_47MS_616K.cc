#include<stdio.h>
#include<algorithm>
using namespace std;

const long long INF=20000000;

long long x[20000],y[20000],c[20000],a,b,n;

int main()
{
	long long i,v,T,flag;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		a=0,b=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld %lld",&x[i],&y[i]);
			x[i]*=2,y[i]*=2;
            a+=x[i],b+=y[i];
			c[i]=x[i]*INF+y[i];
		}
		if((a%n)!=0||(b%n)!=0)
		{
			printf("no\n");
			continue;
		}
		a/=n,b/=n;
		flag=1;
		sort(c+1,c+n+1);
		for(i=1;i<=n&&flag;i++)
		{
			v=(2*a-x[i])*INF+(2*b-y[i]);
			if(upper_bound(c+1,c+n+1,v)-lower_bound(c+1,c+n+1,v)==0)
               flag=0;
		}
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}
}
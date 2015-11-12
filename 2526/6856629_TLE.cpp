#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;

const long long INF=20000000;

set < long long > H;
long long x[20000],y[20000],a,b,n;

int main()
{
	long long i,v,T,flag;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		a=0,b=0;
		H.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%lld %lld",&x[i],&y[i]);
			x[i]*=2,y[i]*=2;
            a+=x[i],b+=y[i];
			H.insert(x[i]*INF+y[i]);
		}
		if((a%n)!=0||(b%n)!=0)
		{
			printf("no\n");
			continue;
		}
		a/=n,b/=n;
		flag=1;
		for(i=1;i<=n&&flag;i++)
		{
			v=(2*a-x[i])*INF+(2*b-y[i]);
			if(H.count(v)==0)
               flag=0;
		}
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}
}
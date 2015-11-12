#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

multiset< long long > H,W;
long long N,a[400],b[400];

void cut(int v)
{
	W.erase(W.lower_bound(v));
}

int main()
{
	long long i,j,c,x,ans,flag,total;
	while(EOF!=scanf("%lld",&N))
	{
		 total=(N*(N-1))/2;
		 H.clear();
         for(i=1;i<=total;i++)
         {
			 scanf("%lld",&x);
			 b[i]=x;
			 H.insert(x);
		 }
		 sort(b+1,b+total+1);
		 for(i=3;i<=N+1&&i<=total;i++)
		 {
			 flag=1;
			 ans=b[1]+b[2]-b[i];
             if(ans%2)
			 {
				flag=0;
				continue;
			 }
			 a[1]=ans/2;
			 a[2]=b[1]-a[1];
			 a[3]=b[2]-a[1];
			 W=H;
			 cut(a[1]+a[2]);
			 cut(a[1]+a[3]);
			 cut(a[2]+a[3]);
			 for(j=4;j<=N&&flag;j++)
			 {
                 a[j]=*W.begin()-a[1];
				 for(c=1;c<j&&flag;c++)
				 {
					 if(W.count(a[c]+a[j]))
						 cut(a[c]+a[j]);
					 else
						 flag=0;
				 }
			 }
			 if(flag&&W.empty())
				 break;
		 }
		 if(flag)
		 {
             for(i=1;i<N;i++)
				 printf("%lld ",a[i]);
			 printf("%lld\n",a[N]);
		 }
		 else
			 printf("Impossible\n");

	}
	return 0;
}
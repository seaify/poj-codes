#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

long long N,total,a[400],b[400],s[400];

int cut(long long v)
{
	long long j;
	for(j=1;j<=total;j++)
		if(s[j]&&b[j]==v)
		{
			s[j]=0;
			return 1;
		}
	return 0;
}

int main()
{
	long long i,j,c,x,ans,flag;
	while(EOF!=scanf("%lld",&N))
	{
		 total=(N*(N-1))/2;
         for(i=1;i<=total;i++)
         {
			 scanf("%lld",&x);
			 b[i]=x;
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
			 memset(s,1,sizeof(s));
			 cut(a[1]+a[2]);
			 cut(a[1]+a[3]);
			 cut(a[2]+a[3]);
			 for(j=4;j<=N&&flag;j++)
			 {
                 for(c=1;c<=total;c++)
					 if(s[c])
					 {
						 a[j]=b[c]-a[1];
						 break;
					 }
				 for(c=1;c<j&&flag;c++)
				 {
					 if(cut(a[c]+a[j])==0)
						 flag=0;
				 }
			 }
			 if(flag)
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
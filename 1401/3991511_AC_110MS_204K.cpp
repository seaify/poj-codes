#include<stdio.h>
int main()
{
	long n,sum,t;
	scanf("%d",&t);
	while(t--)
	{   
		sum=0;
		scanf("%ld",&n);
		while(n)
		{
			n/=5;
			sum+=n;
		}
		printf("%ld\n",sum);
	}
	return 0;
}

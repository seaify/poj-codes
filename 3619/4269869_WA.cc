#include<stdio.h>
#include<math.h>
int main()
{
	long x,y,a,b,c,n,t,s;double k;
	scanf("%ld%ld",&n,&t);
	while(t--)
	{
		scanf("%ld%ld%ld",&a,&b,&c);
		x=n/(a*b);y=n%(a*b);
		if(y==0)
		{
			s=(x-1)*(b+c);
			printf("%ld\n",s);
		}
		else
		{
			s=x*(b+c);
			k=double(y*1.0/a);
			s+=ceil(k);
		}
		printf("%ld\n",s);
	}
	return 0;
}
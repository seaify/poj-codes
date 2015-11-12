#include<stdio.h>
int main()
{
	long p,e,i,a,b,c;
	while(EOF!=scanf("%ld%ld%ld",&p,&e,&i))
	{
		a=p-3*e+3*i;
		b=3*p-8*e+6*i;
		c=6*p-15*e+10*i;
		printf("%ld %ld %ld\n",a,b,c);
	}
	return 0;
}


		

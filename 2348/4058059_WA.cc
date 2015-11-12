#include<stdio.h>
int main()
{
	long a,b,i,t;
	while(EOF!=scanf("%ld%ld",&a,&b)&&(a||b))
	{
		
		if(a<b)
		{
			t=a;
			a=b;
			b=t;
		}
		if(a>=2*b)
            printf("Stan wins\n");
		else
		{
			i=0;
		while(a%b!=0)
		{
			a=a%b;
			t=a;
			a=b;
			b=t;
			i++;
		}i++;printf("%ld\n",i);
		if(i%2!=0)
           printf("Stan wins\n");
		else
			printf("Ollie wins\n");
		}
	}
	return 0;
}


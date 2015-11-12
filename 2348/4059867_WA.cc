#include<stdio.h>
long i;
void printf()
{
	if(i)
		printf("Stan wins\n");
	else 
	
					printf("Ollie wins\n");		
}
int main()
{
	long a,b,t;
	while(EOF!=scanf("%ld%ld",&a,&b)&&(a||b))
	{
		
		if(a<b)
		{
			t=a;
			a=b;
			b=t;
		}
	
			i=1;
		while(1)
		{
			if(a>=2*b)
            {
			  printf();
				break;
			}
			
			t=a%b;
			a=b;
			b=t;
			if(t==0)
			{
			   printf();
				break;
			}
			i=1-i;
		
		}
	}
	
	return 0;
}


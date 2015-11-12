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
	
			i=1;
		while(1)
		{
			if(a>=2*b)
            {
				if(i)printf("Stan wins\n");
				else 
					printf("Ollie wins\n");

				break;
			}
			
			t=a%b;
			a=b;
			b=t;
			if(t==0)
			{
				if(i)printf("Stan wins\n");
				else 
					printf("Ollie wins\n");
			}
			i=1-i;
		
		}
	}
	
	return 0;
}



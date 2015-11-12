#include<stdio.h>
int main()
{
	long a,b,i,t,c;
	while(EOF!=scanf("%ld%ld",&a,&b)&&(a||b))
	{
		
		if(a<b)
		{
			t=a;
			a=b;
			b=t;
		}
	
			i=0;c=0;
		while(a%b!=0)
		{
			if(a>=2*b)
            {printf("Stan wins\n");c=1;break;}
			a=a%b;
			t=a;
			a=b;
			b=t;
			i++;
		
		}i++;
		if(c==0)
		{if(i%2!=0)
           printf("Stan wins\n");
		else
			printf("Ollie wins\n");
		}
	}
	
	return 0;
}


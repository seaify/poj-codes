#include<stdio.h>
#include<math.h>
int main()
{
   long t;
    __int64 c,d,max,min,j,k,i;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%I64d",&i); 
		min=sqrt(2*i-1.0/4)-1.5;
		max=sqrt(2*i-1.0/4)-0.5;
		for(j=min;j<=max;j++)
	         if(j*j+j>2*i)
				 break;
		  j=j-1;
		  c=j*(j+1);
		  c=c/2;

	
	
			printf("%I64d\n",i-c);
	}
	return 0;
}
			
	
           

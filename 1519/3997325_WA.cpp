#include<stdio.h>
int main()
{
	long n,i;int a[50],sum;
	while(EOF!=scanf("%ld",&n)&&n)
	while(1)
		{   sum=0;
			for(i=0;n!=0;i++)
			{
				a[i]=n%10;
				sum+=a[i];
				n/=10;
			}
			if(sum>=10)
				n=sum;
			else
			{printf("%d\n",sum);break;}
		}
	return 0;
}

			
		
		


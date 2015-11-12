#include <stdio.h>
int main()
{
	int n,n2,n5,digit,i,j;
	while(EOF!=scanf("%d",&n))
	{
		n2=0;n5=0;digit=1;
		for(i=2;i<=n;i++)
		{
			j=i;
			while(j%2==0)
			{
				n2++;
				j/=2;
			}
			while(j%5==0)
			{
				n5++;
				j/=5;
			}
			digit=(digit*j)%10;
		}
		for(i=1;i<=n2-n5;i++)
			digit=(digit*2)%10;
		printf("%5d -> %d\n",n,digit);
	}
	return 0;
}
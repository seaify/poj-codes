#include<stdio.h>
int main()
{
	int m,n,i,j,h;long s;double x;
	while(EOF!=scanf("%d%d",&n,&m)&&(m||n))
	{
		j=(n-m)?n-m:m;h=n-j;x=1;
		for(i=1;i<=j;i++)
		{
			x*=((h+i)*1.0)/i;
			s=long(x+0.1);
			x=s;
		}
		printf("%d things taken %d at a time is %ld exactly.\n",n,m,s);

	}
	return 0;
}
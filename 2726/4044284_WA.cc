#include<stdio.h>
int main()
{
	int t,a,b,c;
	while(EOF!=scanf("%d",&t)&&t)
	{
		c=0;
		while(t--)
		{
		scanf("%d%d",&a,&b);
		if(a>=b)
			c++;
		}
		printf("%d\n",c);
	}
	return 0;
}
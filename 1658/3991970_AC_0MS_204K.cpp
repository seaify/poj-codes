#include <stdio.h>
int main()
{
	int i,t,a[6];
	scanf("%d",&t);
	while(t--)
	{
		for(i=1;i<=4;i++)
			scanf("%ld",&a[i]);
		for(i=1;i<=4;i++)
			printf("%ld ",a[i]);
		if(2*a[2]==a[1]+a[3]&&2*a[3]==a[2]+a[4])
			printf("%ld\n",2*a[4]-a[3]);
		else
			printf("%ld\n",(a[4]*a[4])/a[3]);
	}
	return 0;
}

    
   



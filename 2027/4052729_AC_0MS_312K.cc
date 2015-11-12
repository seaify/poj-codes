#include<stdio.h>
int main()
{
	int a,b,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if(a>=b)
			printf("MMM BRAINS\n");
		else
			printf("NO BRAINS\n");
	}
	return 0;
}

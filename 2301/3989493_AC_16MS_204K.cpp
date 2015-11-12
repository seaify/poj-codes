#include<stdio.h>
int main()
{
	int t;long x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld%ld",&x,&y);
		if(x<y)
			printf("impossible\n");
		else
		{
			if((x-y)%2==0&&(x+y)%2==0)
				printf("%ld %ld\n",(x+y)/2,(x-y)/2);
			else
				printf("impossible\n");
		}
	}
	return 0;
}

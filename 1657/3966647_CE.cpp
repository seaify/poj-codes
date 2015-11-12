#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,x,y,m;
	char begin[10],end[10];
	while(EOF!=scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%s%s",begin,end);
			x=fabs(begin[0]-end[0])+0.1;
			y=fabs(begin[1]-end[1])+0.1;
			if(x<y)
				printf("%d ",y);
			else
				printf("%d ",x);
			if(x==y||x==0||y==0)
				printf("1 ");
			else
				printf("2 ");
			if(x==0||y==0)
				printf("1 ");
			else
				printf("2 ");
		    m=fabs(x-y)+0.1;
			if(m%2==0)
				if(x==y)
					printf("1\n");
				else
					printf("2\n");
			else
				printf("Inf\n");
		}
	}
	return 0;
}

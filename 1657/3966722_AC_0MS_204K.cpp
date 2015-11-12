#include<stdio.h>
#include<string.h>
int main()
{
	int t,x,y,m;
	char begin[10],end[10];
     scanf("%d",&t);

		while(t--)
		{
			scanf("%s%s",begin,end);
			if(begin[0]<end[0])
                 x=end[0]-begin[0];
			else
				x=begin[0]-end[0];
			if(begin[1]<end[1])
				y=end[1]-begin[1];
			else
				y=begin[1]-end[1];
		    if(x==0&&y==0)
				printf("0 0 0 0\n");
			else
			{
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
		    if(x<y)
			    m=y-x;
		    else
			    m=x-y;
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


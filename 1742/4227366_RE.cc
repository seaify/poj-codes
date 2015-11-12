#include<stdio.h>    
#include<string.h>
#include<stdlib.h>
int flag[1000005];
typedef struct Point
{
	long x,y;
};
int cmp(const void *a,const void *b)
{
   struct Point *x=(Point *)a;
     struct Point *y=(Point *)b;
     return x->x-y->x;
}
int main()
{   long max,s,j,n;
    long i,k,m;Point p[105];
	while(EOF!=scanf("%d%ld",&n,&m)&&(m||n))
	{    
		for(i=1;i<=n;i++)
			scanf("%ld",&p[i].x);
		for(i=1;i<=n;i++)
			scanf("%ld",&p[i].y);
		qsort(p,0,sizeof(p),cmp);
		memset(flag,0,sizeof(flag));
		flag[0]=1;max=0;s=0;
		for(i=1;i<=n;i++)
		{
			max+=p[i].x*p[i].y;
		    if(max>m)
			     max=m;
			for(j=max;j>=0;j--)
				if(flag[j])
				{
					for(k=1;k<=p[i].y;k++)
					{
						if(flag[j+k*p[i].x])
							continue;
						flag[j+k*p[i].x]=1;
						if(j+k*p[i].x<=m)
							s++;
						else
							break;
					}
				}
		}
		printf("%ld\n",s);
	}
	return 0;
}



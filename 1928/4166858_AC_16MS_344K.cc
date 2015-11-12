#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct point
{
	int x1,y1,value;
}point;
point p[2510];
int cmp(const void *a,const void *b)
{
     struct point *aa=(point *)a;
     struct point *bb=(point *)b;  
         return  (bb->value)-(aa->value);
}
int main()
{
	int  i,j,M,N,K,total,x,y,t,cases,c;
	scanf("%d",&cases);
	while(cases--)
	{
	 scanf("%d%d%d",&M,&N,&K);c=1;
    	for(i=1;i<=M;i++)
		for(j=1;j<=N;j++)
		{
			scanf("%d",&p[c].value);
            p[c].x1=i;p[c].y1=j;c++;
		}
	 qsort(&p[1],M*N,sizeof(p[1]),cmp);
	t=0;x=0;i=1;total=0;
	while(t<K)
	{
		if(p[i].value==0)
			break;
		if(x==0)
			y=p[i].y1;
		if(t+p[i].x1+1+abs(p[i].x1-x)+abs(p[i].y1-y)<=K)
		{
			t+=1+abs(p[i].x1-x)+abs(p[i].y1-y);
			x=p[i].x1;y=p[i].y1;
			total+=p[i].value;
		}
		else
			break;
		i++;
	}
	printf("%d\n",total);
	}
    return 0;
}
		
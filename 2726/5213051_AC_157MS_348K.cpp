#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,N,minv,t,sum;
bool flag[20000];
struct node
{
	int x,y,no;
};
node e[20000];
int cmp(const void *a,const void *b)
{
     struct node *aa=(node *)a;
     struct node *bb=(node *)b;
     if(aa->x!=bb->x)
		 return aa->x-bb->x;
	 else
		 return aa->y-bb->y;//递减排序。。。
}
void solve()
{
	minv=e[1].y;
	for(i=2;i<=N;++i)
	{
    	if(e[i].y>=minv)
			flag[e[i].no]=false;
		else
             minv=e[i].y;
	}
}
int main()
{
	while(EOF!=scanf("%d",&N))
	{
		if(N==0)
			break;
		for(i=1;i<=N;++i)
		{
			scanf("%d %d",&e[i].x,&e[i].y);
			e[i].no=i;
		}
		memset(flag,true,sizeof(flag));
		qsort(e+1,N,sizeof(e[1]),cmp);
	    solve();
		for(i=1;i<=N;++i)
		{
			t=e[i].x;
			e[i].x=e[i].y;
			e[i].y=t;
		}
		qsort(e+1,N,sizeof(e[1]),cmp);
		solve();
		sum=0;
		for(i=1;i<=N;++i)
			if(flag[i])
				++sum;
        printf("%d\n",sum);
	}
	return 0;
}
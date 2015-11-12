#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct annal
{
	int proft;
	int time;
}Annal;
Annal arr[10001];

int cmp(const void*a,const void*b)
{
	Annal *c = (Annal*)a;
	Annal *d = (Annal*)b;
	return d->proft - c->proft;
}

int main()
{
	int n,i,j;
	int s;
	int last;
	int temp[10001];
	int maxtime;
	while(scanf("%d",&n)!=EOF)
	{
		s=0;
		last = -1;
		memset(temp,0,sizeof(temp));
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&arr[i].proft,&arr[i].time);
			if(i==0)
				maxtime = arr[0].time;
			else if(arr[i].time>maxtime)
				maxtime = arr[i].time;
		}
		qsort(arr,n,sizeof(arr[0]),cmp);
		for(i=0;i<n;i++)
		{
			if(arr[i].time<1)
				continue;
			if(temp[arr[i].time] == 0)
				temp[arr[i].time] = arr[i].proft;
			else
				arr[i].time--,i--;
		}
		for(i=1;i<=maxtime;i++)
			s+=temp[i];
		printf("%d\n",s);
	}
	return 0;
}
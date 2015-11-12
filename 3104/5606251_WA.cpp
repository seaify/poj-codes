#include<cstdio>
int a[110000],n,water;
int left,right,mid;

int check()
{
	int i,total,v;
	total=0;
	for(i=1;i<=n;i++)
	{
		v=a[i]-mid;
		if(v<=0)
			continue;
		total+=v/water;
		if(v%water)
			total++;
	}
	if(total<=mid)
		return 1;
	return 0;
}

int main()
{
	int i;
	while(EOF!=scanf("%d",&n))
	{
		left=1;
		right=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>right)
				right=a[i];
		}
		scanf("%d",&water);
		if(water==1)
		{
			printf("%d\n",right);
			continue;
		}
		water--;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(check())
				right=mid-1;
			else
				left=mid+1;
		}
		printf("%d\n",left);
	}
	return 0;
}

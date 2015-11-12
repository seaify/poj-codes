#include<cstdio>
int n;
__int64 left,right,mid,m,water,a[110000];

int check()
{
	int i;
	__int64 total,v;
    total=mid*m;
	for(i=1;i<=n;i++)
	{
		v=a[i]-mid;
		if(v<=0)
			continue;
		if(v/water>mid)
		     return 0;
		total-=v/water;
		if(v%water)
			total--;
	    if(total<0)
	         return 0;
	}
	return 1;
}

int main()
{
	int i,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		left=1;
		right=0;
		for(i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
			if(a[i]>right)
				right=a[i];
		}
		scanf("%I64d %I64d",&m,&water);
		if(water==1)
		{
			printf("%I64d\n",right);
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
		printf("%I64d\n",left);
	}
	return 0;
}

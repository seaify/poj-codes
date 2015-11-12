#include<cstdio>
int a[110000],n,m,water;
int left,right,mid;

int check()
{
	int i,v;
	__int64 total=0,ans;
    ans=(__int64)(mid*m);
	for(i=1;i<=n;i++)
	{
		v=a[i]-mid;
		if(v<=0)
			continue;
		if(v/water>mid)
		     return 0;
		total+=v/water;
		if(v%water)
			total++;
	    if(total>ans)
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
			scanf("%d",&a[i]);
			if(a[i]>right)
				right=a[i];
		}
		scanf("%d %d",&m,&water);
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

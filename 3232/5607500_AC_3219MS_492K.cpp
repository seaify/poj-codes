#include<cstdio>
int a[110000],n,m,water;
int left,right,mid;

bool check(__int64 t)
	{
		int i;
		__int64 tmp=0,j;
		j=(__int64)(t*m);
		for(i=1;i<=n;i++)
		{
			if (a[i]-t<=0)
				continue;
			if ((a[i]-t)%(water-1)==0)
				tmp=(a[i]-t)/(water-1);
			else
				tmp=(a[i]-t)/(water-1)+1;
			
			if (tmp>t||tmp>j)
				return false;
			j-=tmp;
		}
		return true;
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
		while(left<=right)
		{
			mid=(left+right)/2;
			if(check(mid))
				right=mid-1;
			else
				left=mid+1;
		}
		printf("%d\n",left);
	}
	return 0;
}


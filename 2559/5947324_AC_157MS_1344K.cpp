#include<stdio.h>
int n;
int h[110000],left[110000],right[110000];
__int64 x,ans,tmp;

int main()
{
	int i,j;
	while(EOF!=scanf("%d",&n))   ////数据显然会超..
	{
		if(n==0)
			break;
		for(i=1;i<=n;i++)
			scanf("%d",&h[i]);
		for(i=1;i<=n;i++)
		{
			if(i!=1&&h[i-1]>=h[i])
			{
				j=i-1;
				while(left[j]>1&&h[left[j]-1]>=h[i])
					j=left[j]-1;
				left[i]=left[j];
			}
			else
				left[i]=i;
		}

		for(i=n;i>=1;i--)
		{
			if(i!=n&&h[i+1]>=h[i])
			{
				j=i+1;
				while(right[j]<n&&h[right[j]+1]>=h[i])
					j=right[j]+1;
				right[i]=right[j];
			}
			else
				right[i]=i;
		}

        ans=0;

		for(i=1;i<=n;i++)
		{
            tmp=right[i]-left[i]+1;
			x=h[i];
			tmp*=x;
			if(tmp>ans)
				ans=tmp;
		}

		printf("%I64d\n",ans);

	}
	return 0;
}
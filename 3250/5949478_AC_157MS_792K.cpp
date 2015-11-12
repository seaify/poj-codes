#include<stdio.h>
int n;
int h[110000],right[110000];
__int64 ans;

int main()
{
	int i,j;
	while(EOF!=scanf("%d",&n))   ////数据显然会超..
	{
	
		for(i=1;i<=n;i++)
			scanf("%d",&h[i]);

		for(i=n;i>=1;i--)
		{
			if(i!=n&&h[i+1]<h[i])
			{
				j=i+1;
				while(right[j]<n&&h[right[j]+1]<h[i])
					j=right[j]+1;
				right[i]=right[j];
			}
			else
				right[i]=i;
		}

        ans=0;

		for(i=1;i<=n;i++)           
			ans+=right[i]-i;

		printf("%I64d\n",ans);

	}
	return 0;
}

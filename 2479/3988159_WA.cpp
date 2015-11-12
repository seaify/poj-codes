#include<stdio.h>
#define MIN  -9999999
int a[50005],f[50005];
int main()
{
	int t,i,n;
	long sum,tmp,ans;sum=0;tmp=MIN;
	scanf("%d",&t);
	while(t--)
	{   scanf("%d",&n);
		for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		if(sum>tmp)
			tmp=sum;
		f[i]=tmp;
		if(sum<0)
			sum=0;
	}
	tmp=ans=MIN;sum=0;
	for(i=n;i>1;i--)
	{
		sum+=a[i];
		if(sum>tmp)
			tmp=sum;
		if(ans<(f[i-1]+tmp))
			ans=f[i-1]+tmp;
		if(sum<0)
			sum=0;
	}
	printf("%ld\n",ans);
	}
	return 0;
}




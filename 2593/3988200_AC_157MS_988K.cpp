#include<stdio.h>
#define MIN  -999999999
int a[100005],f[100005];
int main()
{
	int i,n;
	long sum,tmp,ans;

	
   while(EOF!=scanf("%d",&n)&&n)
   {
	   sum=0;tmp=MIN;
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




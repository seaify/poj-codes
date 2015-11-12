#include<stdio.h>
int N,M,a[110000],left,right,mid;
int check(int value)
{
	int cnt=1,i,sum=0;
	for(i=1;i<=N;++i)
	{
        if(sum+a[i]<=value)
			sum+=a[i];
		else
		{
			++cnt;
			sum=a[i];
		}
	}
	if(cnt<=M)
		return 1;
	return 0;
}
int main()
{
	int i;
	while(EOF!=scanf("%d %d",&N,&M))
	{
		left=0,right=0;
		for(i=1;i<=N;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]>left)
				left=a[i];
			right+=a[i];
		}
	    while(left<=right)
		{
           mid=(left+right)/2;
		   if(check(mid))//成立
                right=mid-1;
		   else
			    left=mid+1;
		}
        printf("%d\n",left);
	}
	return 0;
}

#include<stdio.h>
#include<math.h>
const double eps=1e-9;
int a[110000],left,right,mid;
int N,M;
int check(int value)
{
	int cnt=0,i;
	for(i=1;i<=N;++i)
		cnt+=a[i]/value; 
	if(cnt>=M)
		return 1;
	return 0;
}
int main()
{
	int i,sum;double value;
	while(EOF!=scanf("%d %d",&N,&M))
	{
		left=1,right=0;
		for(i=1;i<=N;++i)
		{
			scanf("%lf",&value);
			a[i]=int(100*value);
			if(a[i]>right)
				right=a[i];
		}
	    while(left<=right)
		{
           mid=(left+right)/2;
		   if(check(mid))//成立
                left=mid+1;
		   else
			    right=mid-1;
		}
		if(right==0)
        {
			printf("0.00\n");
			continue;
		}
		sum=0;
		for(i=1;i<=N;i++)
			sum+=a[i]/right;
		if(sum>=M)
			printf("%.2lf\n",right*0.01);			
		else 
			printf("%.2lf\n",left*0.01);
	}
	return 0;
}

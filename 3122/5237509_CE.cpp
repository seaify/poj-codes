#include<stdio.h>
#include<math.h>
const double eps=1e-6;
double a[11000],left,right,mid;
int N,M,T;
const double pi=acos(-1);
int check(double value)
{
	int cnt=0,i;
	for(i=1;i<=N;++i)
		cnt+=int(a[i]/value); 
	if(cnt>=M+1)
		return 1;
	return 0;
}
int main()
{
	int i,v;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		left=0.0,right=0.0;
		for(i=1;i<=N;++i)
		{
			scanf("%d",&v);
			a[i]=pi*v*v;
			if(a[i]>right)
				right=a[i];
		}
	    while(left+eps<=right)
		{
           mid=(left+right)/2.0;
		   if(check(mid))//成立
                left=mid;
		   else
			    right=mid;
		}
		printf("%.4lf\n",right);			
	}
	return 0;
}


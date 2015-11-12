#include<stdio.h>
#include<math.h>
const double eps=1e-9;
double a[110000],left,right,mid;
int N,M;
int check(double value)
{
	int cnt=0,i;
	for(i=1;i<=N;++i)
		cnt+=int(a[i]/value); 
	if(cnt>=M)
		return 1;
	return 0;
}
int main()
{
	int i;
	while(EOF!=scanf("%d %d",&N,&M))
	{
		left=0.0,right=0.0;
		for(i=1;i<=N;++i)
		{
			scanf("%lf",&a[i]);
			right+=a[i];
		}
	    while(fabs(left-right)>eps)
		{
           mid=(left+right)/2.0;
		   if(check(mid))//成立
                left=mid;
		   else
			    right=mid;
		}
		if(left+eps>=0.01)
           printf("%.2lf\n",left);
		else
	       printf("0.00\n");
	}
	return 0;
}

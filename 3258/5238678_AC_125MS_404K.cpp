#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF=1000000000;
int a[60000],N,M,L;
int check(int v)
{
	int last,i,cnt;
	last=a[0];cnt=0;
	for(i=1;i<=N+1;++i)
	{
		if(a[i]-last>=v)
			last=a[i];
		else
			++cnt;
	}
	if(cnt<=M)
		return 1;
	return 0;
}
int main()
{
	int left,right,mid,i;
	while(EOF!=scanf("%d %d %d",&L,&N,&M))
	{
		for(i=1;i<=N;++i)
			scanf("%d",&a[i]);
		a[0]=0,a[N+1]=L;
		sort(a,a+N+2);
		left=INF;
		for(i=0;i<=N;++i)
			if(a[i+1]-a[i]<left)
				left=a[i+1]-a[i];
		right=L;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(check(mid))
				left=mid+1;
			else
				right=mid-1;
		}
		printf("%d\n",right);
	}
	return 0;
}
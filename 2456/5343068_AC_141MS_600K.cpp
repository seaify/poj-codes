#include<cstdio>
#include<algorithm>
using namespace std;
int a[110000],N,C;
int check(int v)
{
	int i,cnt,M;
	cnt=a[0],M=1;
	for(i=1;i<N;++i)
	{
		if(a[i]-cnt>=v)
			cnt=a[i],++M;
		if(M>=C)
			return 1;
	}
	return 0;
}
int main()
{
	int i,left,mid,right;
	while(EOF!=scanf("%d %d",&N,&C))
	{
		for(i=0;i<N;++i)
			scanf("%d",&a[i]);
		sort(a,a+N);
		left=right=a[N-1]-a[0];
		for(i=1;i<N;++i)
			if(a[i]-a[i-1]<left)
				left=a[i]-a[i-1];
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

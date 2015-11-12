#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF=1000000000;

int a[1100],f[1100][1100][2];
int n,L,beg;

int check(int i,int j,int k)
{
	if(f[i][j][k]>=0)
		return 1;  ///合法..

}

int min(int a,int b)
{
	if(a>=INF&&b>=INF)
		return INF;
	if(a<b)
		return a;
	return b;
}

int main()
{
	int i,j,k,c,flag,result;
	while(EOF!=scanf("%d %d",&n,&L))
	{
		flag=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==L)
				flag=1;
		}
		if(flag==0)
			a[++n]=L;
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
			if(a[i]==L)
			{
				beg=i;
				break;
			}

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				f[i][j][0]=f[i][j][1]=INF;

		f[beg][beg][0]=f[beg][beg][1]=0;

		for(k=1;k<n;k++)
			for(i=1;i<=beg&&i+k<=n;i++)
			{
				j=i+k;
				c=n-j+i;
				if(i<beg&&j>=beg&&i+1<=n)
				{
                      f[i][j][0]=min(f[i+1][j][0]+(a[i+1]-a[i])*c,f[i+1][j][1]+(a[j]-a[i])*c);

				}
				if(j>beg)
				{
					 f[i][j][1]=min(f[i][j-1][1]+(a[j]-a[j-1])*c,f[i][j-1][0]+(a[j]-a[i])*c);
				}
			}
		result=min(f[1][n][0],f[1][n][1]);
		printf("%d\n",result);
	}
	return 0;
}
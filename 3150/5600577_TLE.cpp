#include<cstdio>
#include<cstring>
int n,m,d,k;
__int64 a[600],b[600],c[600],f[600];

void mul(__int64 x[600],__int64 y[600],int t)
{
	 int i,j;
     memset(c,0,sizeof(c));
	 for(i=0;i<n;i++)
	 {
		 for(j=0;j<n;j++)
			 c[i]=c[i]+x[j]*y[i-j>=0?i-j:i-j+n];
		 while(c[i]>=m)
			 c[i]-=m;
	 }
	 if(t==1)
		 memcpy(b,c,sizeof(c));
	 else
		 memcpy(a,c,sizeof(c));
}

void solve()
{
	int i;
	memset(a,0,n*sizeof(a[0]));
	a[0]=1;
	for(i=1;i<=d;i++)   ///初始化矩阵..
		a[i]=a[n-i]=1;
	memcpy(b,a,sizeof(a));
	k--;
	while(k)
	{
		if(k&1)
			mul(b,a,1);
		mul(a,a,2);
		k>>=1;
	}
	mul(f,b,2);
	for(i=0;i<n-1;i++)
		printf("%I64d ",a[i]);
	printf("%I64d\n",a[n-1]);
}

int main()
{
	int i;
	while(EOF!=scanf("%d %d %d %d",&n,&m,&d,&k))
	{
		for(i=0;i<n;++i)
		{
			scanf("%I64d",&f[i]);
			while(f[i]>=m)
				f[i]-=m;
		}
		solve();
	}
	return 0;
}
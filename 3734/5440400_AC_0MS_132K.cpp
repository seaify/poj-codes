#include<stdio.h>

int main()
{
	int T,n,k,l;
	__int64 a1,a2,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		k=n-1;
		l=k<<1;
		a1=1;
		a2=1;
		b=2;
		while(k|l)
		{
			if(k&1)
			{
				a1*=b;
				if(a1>=10007)a1%=10007;
			}
			if(l&1)
			{
				a2*=b;
				if(a2>=10007)a2%=10007;
			}
			k>>=1;
			l>>=1;
			b*=b;
			if(b>=10007)b%=10007;
		}
		a1=a1+a2;
		if(a1>=10007)a1-=10007;
		printf("%I64d\n",a1);
	}
	return 0;
}
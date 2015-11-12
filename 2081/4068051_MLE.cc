#include<stdio.h>
#include<string.h>
long flag[50000000],a[500000];
int main()
{
	long n,i,t;
	
	while(EOF!=scanf("%d",&n))
	{
		if(n==-1)break;
		a[0]=0;memset(flag,0,sizeof(flag));
		for(i=1;i<=n;i++)
		{
			t=a[i-1]-i;
			if(t>0&&flag[t]==0)
				a[i]=t;
			else
				a[i]=a[i-1]+i;
			flag[a[i]]=1;
		}
		printf("%ld\n",a[n]);
	}
	return 0;
}
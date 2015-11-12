#include<stdio.h>
int main()
{
	int n,i,t,time=1;__int64 a[55][2],f[55];
	a[1][1]=1;a[1][0]=1;f[1]=2;
	for(i=2;i<=45;i++)
	{
		a[i][0]=f[i-1];
		a[i][1]=a[i-1][0];
		f[i]=a[i][0]+a[i][1];
	}
	scanf("%d",&t);
    while(t--)
	{
		scanf("%d",&n);
		printf("Scenario #%d:\n",time++);
		printf("%I64d\n\n",f[n]);
	}
	return 0;
}

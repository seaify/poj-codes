#include<stdio.h>
int main()
{
	int n,i,t,time=1;__int64 f[46];
	for(i=3;i<=45;i++)
		f[i]=f[i-1]+f[i-2];
	scanf("%d",&t);
    while(t--)
	{
		scanf("%d",&n);
		printf("Scenario #%d:\n",time++);
		printf("%I64d\n\n",f[n]);
	}
	return 0;
}

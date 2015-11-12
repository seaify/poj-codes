#include<stdio.h>
int main()
{
	int i,j,n,a[1001],f[1001];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[1]=1;
	for(i=2;i<=n;i++)
		for(j=1;j<i;j++)
			if(j==1||(a[j]<a[i]&&f[i]<f[j]+1))
				f[i]=f[j]+1;
	printf("%d\n",f[n]);
    return 0;
}
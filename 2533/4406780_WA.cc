#include<stdio.h>
int main()
{
	int i,j,n,a[1001],f[1001],max;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[1]=1;max=1;
	for(i=2;i<=n;i++)
	{
		f[i]=1;
	   for(j=1;j<i;j++)
	       if(a[j]<=a[i]&&f[i]<f[j]+1)
			  	f[i]=f[j]+1;
	
	}
	for(i=1;i<=n;i++)
		if(f[i]>max)
			max=f[i];
	printf("%d\n",max);
    return 0;
}


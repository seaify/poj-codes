#include<stdio.h>
int main()
{
	int i,j;double sum;
	long a[15];a[0]=1;
	for(i=1;i<=9;i++)
		a[i]=a[i-1]*i;
	printf("n e\n");
	printf("- -----------\n");
	for(i=0;i<=9;i++)
	{    
		sum=0;
		for(j=0;j<=i;j++)
			sum+=1.0/a[j];
		printf("%d %.9lf\n",i,sum);
	}
	return 0;
}

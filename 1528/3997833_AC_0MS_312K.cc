#include<stdio.h>
#include<math.h>
int main()
{  long i,j,t,n,s, a[105];
	for(i=1; ;i++)
	{
		scanf("%ld",&a[i]);
		if(a[i]==0)
			break;
	}
	n=i-1;
	printf("PERFECTION OUTPUT\n");
	for(i=1;i<=n;i++)
	{  
		t=int(sqrt(a[i]));s=0;
		for(j=2;j<=t;j++)
			if(a[i]%j==0)
				s+=j+a[i]/j;
			if(a[i]!=1)s=s+1;
			if(s==a[i])
				printf("%5d  PERFECT\n",a[i]);
			else if(s>a[i])
				printf("%5d  ABUNDANT\n",a[i]);
			else
				printf("%5d  DEFICIENT\n",a[i]);
	}
	printf("END OF OUTPUT\n");
	return 0;
}






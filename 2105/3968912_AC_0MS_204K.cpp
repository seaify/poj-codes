#include<stdio.h>
int main()
{
	char a[35];
	int b[35];
	int i,j,k,m,casen,s;
	scanf("%d",&casen);
	while(casen--)
	{
		scanf("%s",a);
		for(i=0;a[i]!='\0';i++)
	         b[i]=a[i]-48;
		for(i=0;i<=3;i++)
		{  	
			for(m=0;m<=7;m++)
			b[m]=b[m+8*i];
			k=1;s=0;
			for(j=7;j>=0;j--)
			{
				s+=b[j]*k;
				k=2*k;
			}
			printf("%d",s);
			if(i!=3)printf(".");
		}
		printf("\n");
	}
	return 0;
}
		
		
		

	

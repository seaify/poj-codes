#include<stdio.h>
#include<string.h>
int main()
{
	char a[5][80],c;
	int flag[30];
	int i,j,max,t;memset(flag,0,sizeof(flag));
  for(i=0;i<=3;i++)
	{
		gets(a[i]);
		for(j=0;a[i][j]!='\0';j++)
		{
			t=a[i][j]-65;
			if(t>=0&&t<=25)
				flag[t]++;
		}
	}
	max=0;
	for(i=0;i<=25;i++)
		if(flag[i]>max)
			max=flag[i];
		for(i=max;i>=1;i--)
		{
			for(j=0;j<=25;j++)
				if(flag[j]>=i)
					printf("* ");
	            else
					printf("  ");
				printf("\n");
		}
		for(c=65;c<=89;c++)
			printf("%c ",c);
		printf("Z\n");
		return 0;
}
			

			
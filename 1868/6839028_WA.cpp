#include<stdio.h>

int n,a[20000],b[20000];

int main()
{
	int i,j,flag;
	char ch[10];

	while(EOF!=scanf("%d",&n)&&n)
	{
        scanf("%s",ch);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[a[i]]=i;
		}
		flag=1;
		for(i=0;i<n&&flag;i++)
		{
			for(j=1;a[i]+2*j<n&&flag;j++)
				if(b[a[i]+j]>i&&b[a[i]+2*j]>b[a[i]+j])
					flag=0;
		}
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}
}
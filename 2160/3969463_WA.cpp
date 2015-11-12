#include<stdio.h>
#include<string.h>
int main()
{
	int a[10],b[10],flag[10],i,j,c;
	for(i=1;i<=6;i++)
		scanf("%d%d",&a[i],&b[i]);
	memset(flag,1,sizeof(flag));
	for(i=1;i<=6;i++)
		for(j=1;j<=6;j++)
			if(flag[i]&&flag[j]&&((a[i]==a[j]&&b[i]==b[j])||(a[i]==b[j]&&b[i]==a[j])))
			{
				flag[i]=0;flag[j]=0;c=1;
			}
			else
				c=0;
	if(c)
		printf("POSSIBLE\n");
	else
		printf("IMPOSSIBLE\n");
		return 0;
}
			

			
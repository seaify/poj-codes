#include<stdio.h>
#include<string.h>
char a[100000];
int  b[100000],f[100000];
int i,n;
int main()
{
	while(EOF!=scanf("%s",a+1))
	{
		if(a[1]=='0')
			break;
		n=strlen(a+1);
		for(i=1;i<=n;i++)
			b[i]=a[i]-'0';
		f[1]=1;
		if(b[2]==0&&b[1]>3)
		{
			printf("0\n");
			continue;
		}
		else if(b[2]==0)
			f[2]=1;
		else if(b[2]+10*b[1]>26)
			f[2]=1;
		else 
		    f[2]=2;	
		for(i=3;i<=n;i++)
		{
			if(b[i]!=0&&b[i]+10*b[i-1]<=26)
				f[i]=f[i-1]+f[i-2];
			else if(b[i]!=0)
				f[i]=f[i-1];
			else if(b[i-1]>=1&&b[i-1]<=2)
				f[i]=f[i-2];
			else
			{
				printf("0\n");
				break;
			}
		}
		if(i==n+1)
			printf("%d\n",f[n]);
	}
	return 0;
}
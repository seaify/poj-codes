#include<stdio.h>

int n;
int a[20000],c[20000],s[20000];

int main()
{
	int i,ls,rs,flag;
	while(EOF!=scanf("%d",&n))
	{
		s[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		//	a[i]%=n;
			s[i]=(s[i-1]+a[i])%n;
			c[i-1]=0;
		}
        
		flag=1;
		for(i=1;i<=n&&flag;i++)
		{
			if(s[i]==0)
			{
				ls=1,rs=i;
				flag=0;
			}
            else if(c[s[i]])
			{
				ls=c[s[i]]+1,rs=i;
				flag=0;
			}
			else
				c[s[i]]=i;
		}
        printf("%d\n",rs-ls+1);
		for(i=ls;i<=rs;i++)
			printf("%d\n",a[i]);
	}
	return 0;
}
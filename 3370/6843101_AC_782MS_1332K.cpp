#include<stdio.h>

int m,n;
int a[200000],c[200000],s[200000];

int main()
{
	int i,ls,rs,flag;
	while(EOF!=scanf("%d %d",&m,&n))
	{
		if(m==0&&n==0)
			break;
		s[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		//	a[i]%=n;
			s[i]=(s[i-1]+a[i])%m;
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
		for(i=ls;i<rs;i++)
			printf("%d ",i);
		printf("%d\n",rs);
	}
	return 0;
}
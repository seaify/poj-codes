#include<stdio.h>

int n,M;
int a[100000],T[maxn];

int main()
{
	int TT=0,i,X,result,ans;
	char ch[10];
	while(EOF!=scanf("%d",&M)&&M)
	{
		printf("Case %d:\n",++TT);
		n=0;
		for(t=1;t<=M;t++)
	    {
			scanf("%s %d",ch,&X);
			if(ch[0]=='A')
			{
				if(n==0)
				{
					printf("-1\n");
					continue;
				}
				result=X;
				for(i=n;i>=1;i--)
					if((a[i]%X)<result)
					{
						result=a[i]%X;
						ans=i;
						if(result==0)
							break;
					}
				printf("%d\n",ans);
			}
			else
			{
				a[++n]=X;
			}
		}
	}
	return 0;
}
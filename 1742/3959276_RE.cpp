#include<stdio.h>    
#include<string.h>
int flag[1000005];
int main()
{   long max,s,j,a[105],n;
    int i,k,c[105],m;
	while(EOF!=scanf("%d%ld",&n,&m)&&(m||n))
	{    
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&c[i]);
		memset(flag,0,sizeof(flag));
		flag[0]=1;max=0;s=0;
		for(i=1;i<=n;i++)
		{
			max+=a[i]*c[i];
		    if(max>=m)
				max=m;
			for(j=max;j>=0;j--)
				if(flag[j])
				{
					for(k=1;k<=c[i];k++)
					{
						if(flag[j+k*a[i]])
							continue;
						flag[j+k*a[i]]=1;
						if(j+k*a[i]<=m)
							s++;
						else
							break;
					}
				}
		}
		printf("%ld\n",s);
	}
	return 0;
}



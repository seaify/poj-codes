#include<stdio.h>
#include<string.h>
char x[110],tmp[110],ans[110];

struct node
{
	char c[110];
};
node a[110];

int n;

void solve()
{
	int i,j,k,len,flag;
    len=strlen(a[0].c);
    for(j=len;j>=1;j--)
	{
			for(i=0;i<=len-j;i++)
			{
				strncpy(tmp,&a[0].c[i],j);
				tmp[j]='\0';
				strcpy(x,tmp);

				_strrev(x);

				flag=1;

				for(k=1;k<n;k++)
					if(strstr(a[k].c,tmp)==NULL&&strstr(a[k].c,x)==NULL)
					{
						flag=0;
						break;
					}

                if(flag)
				{
				    printf("%d\n",j);
				    return ;
				}
			}
		}
		printf("0\n");
}

int main()
{
    int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",a[i].c);
		solve();
	}
	return 0;
}
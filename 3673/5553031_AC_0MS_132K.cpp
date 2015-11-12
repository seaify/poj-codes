#include<cstdio>
#include<cstring>
char a[20],b[20];
int m,n,i,j,sum;

int main()
{
	while(EOF!=scanf("%s %s",a,b))
	{
		m=strlen(a);
		n=strlen(b);
		sum=0;
		for(i=0;i<m;++i)
			for(j=0;j<n;++j)
				sum+=(a[i]-'0')*(b[j]-'0');
		printf("%d\n",sum);

	}
	return 0;
}
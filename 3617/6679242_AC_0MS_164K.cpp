#include<stdio.h>

int n,tot;
char a[40000];

void output(char c)
{
    if(tot==80)
	{
		printf("\n");
		tot=0;
	}
	printf("%c",c);
	++tot;
}

int check(int ls,int rs)
{
    while(ls<=rs&&a[ls]==a[rs])
		ls++,rs--;
    if(ls>rs)
		return 1;
	return a[ls]<a[rs];
}

int main()
{
	char b[5];
	int i,ls,rs;
	while(EOF!=scanf("%d",&n))
	{
		 tot=0;
         for(i=1;i<=n;i++)
		 {
			 scanf("%s",b);
			 a[i]=b[0];
		 }
		 ls=1,rs=n;
         while(ls<=rs)
		 {
			 if(check(ls,rs))
			 {
				 output(a[ls]);
			     ++ls;
			 }
			 else
			 {
				 output(a[rs]);
				 --rs;
			 }
		 }
	}
	return 0;
}
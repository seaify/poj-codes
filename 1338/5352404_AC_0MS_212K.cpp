#include<cstdio>
int x[2000],a,b,c,i,n;

int min(int a,int b,int c)
{
	if(b<a)
		a=b;
	if(c<a)
		a=c;
	return a;
}
int main()
{
	x[1]=1;
	a=1,b=1,c=1;
	for(i=2;i<=1500;++i)
	{
        x[i]=min(x[a]*2,x[b]*3,x[c]*5);
		if(x[i]==x[a]*2)
				++a;
		if(x[i]==x[b]*3)
				++b;
		if(x[i]==x[c]*5)
				++c;
	}
	while(EOF!=scanf("%d",&n))
	{
		if(n==0)
			break;
		printf("%d\n",x[n]);
	}
	return 0;
}
#include<cstdio>
int x[10000],a,b,c,d,i,n;

int min(int a,int b,int c,int d)
{
	if(b<a)
		a=b;
	if(c<a)
		a=c;
	if(d<a)
		a=d;
	return a;
}
int main()
{
	x[1]=1;
	a=1,b=1,c=1,d=1;
	for(i=2;i<=5842;++i)
	{
        x[i]=min(x[a]*2,x[b]*3,x[c]*5,x[d]*7);
		if(x[i]==x[a]*2)
				++a;
		if(x[i]==x[b]*3)
				++b;
		if(x[i]==x[c]*5)
				++c;
		if(x[i]==x[d]*7)
			    ++d;
	}
	while(EOF!=scanf("%d",&n))
	{
		if(n==0)
			break;
		if(n%4==1)
			printf("The %dst humble number is %d.\n",n,x[n]);
		else if(n%4==2)
			printf("The %dnd humble number is %d.\n",n,x[n]);
		else if(n%4==3)
			printf("The %drd humble number is %d.\n",n,x[n]);
		else
			printf("The %dth humble number is %d.\n",n,x[n]);
	}
	return 0;
}

#include<cstdio>
int x[4000000],a,b,c,i,n,p1,p2,p3,cnt;

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
	while(EOF!=scanf("%d %d %d %d",&p1,&p2,&p3,&n))
	{
	   x[0]=1;
	   a=0,b=0,c=0;
 	   for(i=1;i<=n;++i)
	   {
         x[i]=min(x[a]*p1,x[b]*p2,x[c]*p3);
		 if(x[i]==x[a]*p1)
				++a;
		 if(x[i]==x[b]*p2)
				++b;
		 if(x[i]==x[c]*p3)
				++c;
	   }
	   printf("%d\n",x[n]);
	}
	return 0;
}
#include<stdio.h>
int c,cnt;
double a,b;
int main()
{
    int i;
    while(EOF!=scanf("%lf%lf%d",&b,&a,&c))
	{
	    b=(b+100)/100;
		for(i=1;i<=c;++i)
			a*=b;
		cnt=(int)a;
		printf("%d\n",cnt);
	}
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const double eps=1e-9;

int n,N;
double a[20],c[4],ok[4],p,last;

void mul(double x[4],double y[4],int t)
{
	double a[4];
    a[0]=x[0]*y[0]+x[1]*y[2];
	a[1]=x[0]*y[1]+x[1]*y[3];
	a[2]=x[2]*y[0]+x[3]*y[2];
	a[3]=x[2]*y[1]+x[3]*y[3];
	if(t)
		memcpy(ok,a,sizeof(a));
	else
		memcpy(c,a,sizeof(a));
}

double solve(int N)
{
	if(N==0)
		return last;
	ok[0]=1;ok[1]=0;ok[2]=0;ok[3]=1;
    c[0]=p;c[1]=1;c[2]=1-p;c[3]=0;
    while(N)
	{
		if(N&1)
			mul(ok,c,1);
		mul(c,c,0);
		N/=2;
	}
	return last*ok[0];
}

int main()
{
	int i,flag;
	while(EOF!=scanf("%d %lf",&n,&p))
	{
		for(i=1;i<=n;i++)
			scanf("%lf",&a[i]);
        sort(a+1,a+n+1);
		a[0]=0;
		last=1;
		flag=0;
		for(i=1;i<=n;i++)
		{
           N=a[i]-a[i-1]-2;
           if(N<0)         ///相邻..
		   {
			   flag=1;
			   break;
		   }
		   last=solve(N); //
		   last*=p;
		   if(last<eps)
		   {
			   flag=1;
			   break;
		   }
		}
		if(flag)
			printf("0.0000000\n");
		else
			printf("%.7lf\n",last);
	}
}
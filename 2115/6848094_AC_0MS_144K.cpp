#include<stdio.h>

#define min(a,b) a<b?a:b;

long long A,B,C,D,K,M,d,x,y;

long long gcd(long long a,long long b)
{
	long long tmp,d;
	if(b==0)
	{
		x=1;
		y=0;
		return a;
    }
	d=gcd(b,a%b);
    tmp=x;
	x=y;
	y=tmp-(a/b)*y;
    return d;
}

int main()
{
	long long x1,y1,r;

	while(EOF!=scanf("%lld %lld %lld %lld",&A,&B,&C,&K))
	{
          if(A==0&&B==0&&C==0&&K==0)
			  break;
		  if(A==B)
		  {
			  printf("0\n");
			  continue;
		  }
		  if(C==0)
		  {
			  printf("FOREVER\n");
			  continue;
		  }
		  M=(1LL<<K);
          
		  B=(B-A+M)%M;
		  D=gcd(C,M);

		  if((B%D)==0)  
		  {
              gcd(C/D,M/D);
			  x=(x+(M/D))%(M/D);
              x1=((B/D)*x)%M;
			  if(D==2)
			  {
				  y1=(x1+M/D)%M;
			      x1=min(x1,y1);
			  }
              printf("%lld\n",x1);
		  }
		  else
			  printf("FOREVER\n");		  
	}
}
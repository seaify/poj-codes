#include<stdio.h>
__int64 x,y;
__int64 Extend_Gcd(__int64 a,__int64 b)
{
  __int64 temp,d;
  if(b==0)
  {
	x=1;
	y=0;
	return a;
  } 
  d=Extend_Gcd(b,a%b);
  temp=x;
  x=y;
  y=temp-(a/b)*y;
  return d;
}
int main()
{
  __int64 min,i,c,m,n,d,L,a,b;;
  while(EOF!=scanf("%I64d %I64d %I64d %I64d %I64d",&x,&y,&m,&n,&L))
  {
     a=m-n;
     b=y-x;
     if(a<0)
     {
        a=-a;
        b=-b;
     }
	 d=Extend_Gcd(a,L);//求一元同余方程。。。。 
	 if(m==n||b%d!=0)
     {
        printf("Impossible\n");
        continue;
     } 
     b/=d;
     L/=d;
     x=x*b;
     x=(x%L+L)%L;
     printf("%I64d\n",x); 
  }
  return 0;
}




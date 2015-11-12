#include<iostream>
#include<time.h>

const __int64 S=50;  ////测试次数... 

__int64 x1,y1,p,q,d;         /////关键点注意数据范围.... ,d为最大公约数.. 
__int64 C,E,N,phi;

__int64 Extend_Gcd(__int64 a,__int64 b)
{
  __int64 temp;
  if(b==0)
  {
	x1=1;
	y1=0;
	return a;
  } 
 
  d=Extend_Gcd(b,a%b);
  temp=x1;
  x1=y1;
  y1=temp-(a/b)*y1;   ////注意.... 
  return d;
}

__int64 check(__int64 a,__int64 n,__int64 p)  ////a*n%p;
{
    __int64 result=0;
    a%=p;
    n%=p;
    while(n)
    {
        if(n&1)
           result=(result+a)%p;
        a=(a<<1)%p;
        n>>=1;
    }
    return result;
}

__int64 solve(__int64 a,__int64 n,__int64 p) //a^n%p;
{
    __int64 result=1;
    a%=p;
    while(n)
    {
        if(n&1)
           result=check(result,a,p); 
        a=check(a,a,p);
        n>>=1;
    }
    return result;
}


int POLLARD_RHO(__int64 N)
{
    __int64 i,k,x,y,d,c;
        
    srand(time(0));
    i=1;
    x=rand()%N;
    y=x;
    k=2;
    c=rand()%N;
    if(c==0||c==2)
       c=1;
    while(1)
    {
        i++;
        x=(check(x,x,N)+N-c)%N;  ///确保x<N; 
        d=Extend_Gcd(y-x+N,N);  ////确保为正数 
        if(d!=1&&d!=N)
             return d;
             
        if(y==x)
           return N;
        if(i==k)
        {
           y=x;
           k<<=1;
        }
       
    }
  
}

int main()
{
    __int64 t;
    while(EOF!=scanf("%I64d %I64d %I64d",&C,&E,&N))
    {
          while(1)
          {
             p=POLLARD_RHO(N);
             if(p<N)
                break;
          }
          q=N/p;
          phi=(p-1)*(q-1); 
          Extend_Gcd(E,phi);
          x1=(x1+phi)%phi;
          printf("%I64d\n",solve(C,x1,N));
    }
    return 0;
}


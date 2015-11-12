#include<iostream>
#include<time.h>

const __int64 S=100;  ////测试次数... 

__int64 T,N,ans;

__int64 gcd(__int64 a,__int64 b)
{
    if(b==0)
        return a;
    return gcd(b,a%b); 
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

__int64 WITNESS(__int64 a,__int64 n)
{
    __int64 x,u,y,num,i;
    y=n-1;
    num=(y&-y);   ////num=2^t;
    u=y/num;
    x=solve(a,u,n);
    for(i=1;(1<<i)<=num;i++)
    {
        y=check(x,x,n);
        if(y==1&&x!=1&&x!=n-1)
           return 1;    ////合数 
        x=y;
    }
    if(y!=1)
        return 1;
    return 0;
}

__int64 MILLER_RABIN(__int64 n,__int64 s)
{
    __int64 a,j;
    for(j=1;j<=s;j++)
    {
        a=rand()%n;
        if(a==0)
           a=1;
        if(WITNESS(a,n))  ////合数..... 
           return 0;
    }
    return 1;     ///素数.... 
}

void POLLARD_RHO(__int64 N)
{
    __int64 i,k,x,y,z,d,c;
    
    srand((unsigned)time(NULL));
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
        
        z=(check(x,x,N)+N-c)%N;
        d=gcd(y-z+N,N);
        if(d!=1&&d!=N)
        {
       
           if(MILLER_RABIN(d,100)) ///是素数... 
           {
              if(d<ans)
                ans=d;
           }
           else
               POLLARD_RHO(d);
               
           if(MILLER_RABIN(N/d,100))
           {
              if(N/d<ans)
                 ans=N/d;
           }
           else            
               POLLARD_RHO(N/d);
               
           return ;
        }
        if(i==k)
        {
           y=z;
           k<<=1;
        }
        x=z;
    }
    return ;
}

int main()
{
    srand((unsigned)time(NULL));
    scanf("%I64d",&T);
    while(T--)
    {
         scanf("%I64d",&N);
         if((N&1)==0)
         {
              printf("2\n");
              continue;
         }                ////N为奇数...
          
         if(MILLER_RABIN(N,S))
         {
              printf("Prime\n");
              continue;
         }
  
         ans=(1LL<<56);

        
         POLLARD_RHO(N); 
         
         printf("%I64d\n",ans);
         
         
    }
    return 0;
}

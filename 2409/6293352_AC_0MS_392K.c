#include<stdio.h>
#include<math.h>

const double eps=0.1;

int p,n,a[40];
long long sum;

int gcd(int a,int b)
{
     if(b==0)
  	return a;
     return gcd(b,a%b);
}

int main()
{
     int i,j,x,y;
     while(EOF!=scanf("%d %d",&p,&n)&&n&&p)
     {   
          sum=0;
	  for(i=0;i<n;i++)
	     sum+=(long long)(pow(p,gcd(n,i))+eps);

          if(n&1)
                sum+=(long long)(pow(p,(n-1)/2+1)+eps)*n;     
          else
          {
		sum+=(long long)n*(pow(p,n/2+1)+eps)/2;
                sum+=(long long)n*(pow(p,n/2)+eps)/2; 
       
          }
                  
           printf("%lld\n",sum/(2*n));
          	 
     }
     return 0;
}
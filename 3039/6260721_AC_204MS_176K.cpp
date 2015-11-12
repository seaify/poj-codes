#include<iostream>
#include<math.h>

int a,b,c,d,x,y;

int gcd(int a,int b)
{
    if(b==0)
       return a;
    return gcd(b,a%b);
}

int main()
{
    int i,tmp;
    double ans,value;
    while(EOF!=scanf("%d %d",&a,&b))
    {
         ans=10000000;
          for(d=1;d<=32767;d++)
          {
              tmp=(a*d)/b;
              for(;tmp>=1;tmp--)
			  {
				 if(d==b&&tmp==a)
					 continue;
                 if(gcd(d,tmp)==1)
                    break;
			  }
              value=(double)(abs(a*d-b*tmp))/(double)(b*d);
              if(tmp>=1&&value<=ans)
                    ans=value,x=tmp,y=d;
                    
              tmp=(a*d)/b;
              for(tmp++;tmp<=32767;tmp++)
			  {
				  if(d==b&&tmp==a)
					 continue;
                 if(gcd(d,tmp)==1)
                    break;
			  }
                    
              value=(double)(abs(a*d-b*tmp))/(double)(b*d);
              if(tmp<=32767&&value<=ans)
                    ans=value,x=tmp,y=d;
              
          }
          printf("%d %d\n",x,y);
    }
    return 0;
} 

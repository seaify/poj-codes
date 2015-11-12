#include <stdio.h> 
#include <math.h> 
const double eps=1e-12;
const double pi=acos(-1);
double left,mid,right,L,N,C,value,temp,ans;
int main() 
{ 
   while(EOF!=scanf("%lf %lf %lf",&L,&N,&C))
   {
	   if(L<0.0||N<0.0||C<0.0)
	   {
		   printf("0.000\n");
		   break;
	   }
	   value=(1.0+N*C)*L;
	   left=0.0,right=pi/2.0;
	   while(fabs(left-right)>eps)
	   {
           mid=(left+right)/2.0;
		   temp=(L*mid)/sin(mid);
		   if(temp<value)
			   left=mid;
		   else
			   right=mid;
	   }
       ans=(L/sin(mid)-L/tan(mid))/2.0;
	   printf("%.3lf\n",ans);
   }
   return 0;
} 

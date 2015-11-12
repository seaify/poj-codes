#include<stdio.h>    
#include<math.h>
int main()
{  
	int i;char k;
	double s,a;
	s=0;k=36;
	for(i=1;i<=12;i++)
	{
		scanf("%lf",&a);
	    s+=a;
	}
	s=s/12.0;
	printf("%c",k);
	printf("%.2lf\n",s); 
	return 0;    

 }    


	


	
   
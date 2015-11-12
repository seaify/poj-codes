#include<stdio.h>  
int main()
{
	double v,w,s;int c;
	while(EOF!=scanf("%lf%lf%lf",&v,&w,&s)&&(v||w||s))
	{    c=0;
		if(v<=4.5&&w>=150&&s>=200)
		{
			printf("Wide Receiver ");c=1;
		}
		if(v<=6.0&&w>=300&&s>=200)
		{printf("Lineman ");c=1;}
		if(v<=5.0&&w>=200&&s>=300)
		{printf("Quarterback");c=1;}
		if(c==0)
			printf("No positions");
		printf("\n");
	}
     return 0;  
 }  



  

	

	

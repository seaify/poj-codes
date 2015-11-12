#include<stdio.h>
int main()
{
	double s,a,k;
    int i;
	while(EOF!=scanf("%f",&a))
	{
		s=0;
		for(i=1; ;i++)
		{
			k=i;
			s+=1.0/(k+1.0);
		    if(s>=a)
			{
				printf("%d\n",i);
		     	break;
			}
		}
	}
	return 0;
}

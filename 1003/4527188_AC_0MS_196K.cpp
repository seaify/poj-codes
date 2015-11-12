#include<stdio.h>
int main()
{
	double s,a,k;
    int i;
	while(EOF!=scanf("%lf",&a))
	{
        if(a==0.00)
            break;
		s=0;
		for(i=1; ;i++)
		{			
			s+=1.0/(i+1.0);
		    if(s>=a)
			{
				printf("%d card(s)\n",i);
		     	break;
			}
		}
	}
	return 0;
}


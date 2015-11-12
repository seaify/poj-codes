#include<stdio.h>
#include<math.h>
int main()
{
	long i,n,k;double x,y,pi;
	pi=acos(-1);i=1;
	scanf("%ld",&n);
	while(n--)
	{
		scanf("%lf%lf",&x,&y);
		k=int(ceil(pi*(x*x+y*y)/100));
        printf("Property %ld: This property will begin eroding in year %ld.\n",i,k);
		i++;
	}
	printf("END OF OUTPUT.\n");
   return 0;
}
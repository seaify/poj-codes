#include<cstdio>
#include<cstdlib>
#include<cmath>
double S,pi;
int main()
{
	pi=acos(-1.0);
	while(EOF!=scanf("%lf",&S))
	{
  
		printf("%.2lf\n",sqrt(S*S*S/(72*pi)));
		printf("%.2lf\n",sqrt((2*S)/pi));
		printf("%.2lf\n",sqrt(S/4/pi));
	}
	return 0;
}
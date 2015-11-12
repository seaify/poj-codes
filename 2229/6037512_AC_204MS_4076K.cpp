#include<stdio.h>
#include<math.h>

int f[1000005];
int n;

void init()
{
	int i;

	n=1000000;

	f[1]=1;
    f[2]=2;

	for(i=3;i<=n;i++)
		if(i%2)
			f[i]=f[i-1];
		else
			f[i]=(f[i-1]+f[i/2])%1000000000;

	return ;

}

int main()
{

	init();

	while(EOF!=scanf("%d",&n))	

		printf("%d\n",f[n]);

	return 0;
}
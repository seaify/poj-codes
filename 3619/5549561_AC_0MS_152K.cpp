#include<stdio.h>
#include<math.h>
int main()
{
	int N,K,a,b,c,T,ans;
	scanf("%d %d",&N,&K);
	while(K--)
	{
		scanf("%d %d %d",&a,&b,&c);
		T=a*b;
		if(N%T==0)
		{
			T=N/T;
			printf("%d\n",T*(b+c)-c);
		}
		else
		{
			ans=N%T;
			T=N/T;
			ans=ceil(double(ans)/double(a));
			printf("%d\n",T*(b+c)+ans);
		}
	}
 
	return 0;
}

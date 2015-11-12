#include <algorithm>
#include<stdio.h>
using namespace std ;
int i,t,n,k,value,a[1025];
int main()
{
    scanf("%d",&t);
	while(t--)
	{
	 scanf("%d%d",&n,&k);
	 for(i=0;i<n;i++)
		 scanf("%d",a+i);
	 while(k--)
	 {
	   next_permutation(a, a+n);
	 }
	 n--;
	 for(i=0;i<n; ++i)
        printf("%d ",a[i]);
	 printf("%d\n",a[n]);
	}
	return 0;
}


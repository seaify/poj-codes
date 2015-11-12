#include <algorithm>
#include<stdio.h>
using namespace std ;
int n;
char a[210];
int main()
{
    scanf("%s",a);
	n=strlen(a);
	sort(a,a+n);
	printf("%s\n",a);
	while(next_permutation(a, a+n))
	{
	  printf("%s\n",a);
	}
	return 0;
}

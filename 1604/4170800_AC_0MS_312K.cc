#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n2, n5, i, j, n, digit;
    while(EOF!=scanf("%d",&n))
	{
	 digit = 1;
	 n2 = n5 = 0;
	 for(i=2; i<=n; i++) {
		j = i;
		while(j%2 == 0) {
			n2++;
			j /= 2;
		}
		while(j%5 == 0) {
			n5++;
			j /= 5;
		}
		digit = (digit * j) % 10;
	}
	for(i=0; i<n2-n5; i++)
		digit = (digit * 2) % 10;
   printf("%5d -> %d\n",n,digit);
	}
	return 0;
}
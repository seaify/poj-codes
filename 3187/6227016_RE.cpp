#include <algorithm>
#include<stdio.h>
using namespace std ;

int n,sum,tmp; 
int a[100],p[100];

int main()
{
    int i;
    
    p[1]=1;
    for(i=2;i<=10;i++)
         p[i]=p[i-1]*i;
   
	while(EOF!=scanf("%d %d",&n,&sum))
	{
	 
       for(i=1;i<=n;i++)
            a[i]=i;

       while(1)
       {
	        tmp=0;
	        for(i=1;i<=n;i++)
	            tmp+=(p[n-1]*a[i])/(p[i]*p[n-i-1]);
		  
            if(tmp==sum)
            {
                for(i=1;i<n;i++)
                    printf("%d ",a[i]);
                printf("%d\n",a[n]); 
				break;
            }
           
            next_permutation(a+1, a+n+1);
       }

	}
	return 0;
}



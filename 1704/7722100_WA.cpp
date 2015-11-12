#include<stdio.h>
#include<algorithm>
using namespace std;

int x[2000],a[2000],n;

int main()
{
    int i,s,T;

    scanf("%d",&T);
    while(T--)
    {
         scanf("%d",&n);
        
         for(i=1;i<=n;i++)
              scanf("%d",&x[i]);
            
         if(n==1)
         {
			  if(x[1]==1)
			       printf("Bob will win\n");
			  else
			       printf("Georgia will win\n");
			  continue;
		 }
          
         sort(x+1,x+n+1);
         
         for(i=1;i<n;i++)
             a[i]=x[i+1]-x[i];
         
        // s=x[1];
         s=0;

         for(i=1;i<n;i++)
              s^=(a[i]-1);

         if(s!=0)
              printf("Georgia will win\n");
         else
              printf("Bob will win\n");
              
         
    }
    return 0;
}

#include<stdio.h>
#include<algorithm>
using namespace std;

int x[2000],n;

int main()
{
    int i,s,T;

    scanf("%d",&T);
    while(T--)
    {
         scanf("%d",&n);
         s=0;
         for(i=1;i<=n;i++)
              scanf("%d",&x[i]);
          
         sort(x+1,x+n+1);

         for(i=1;i<=n;i++)
              s^=(x[i]-i);

         if(s!=0)
              printf("Georgia will win\n");
         else
              printf("Bob will win\n");
              
         
    }
    return 0;
}
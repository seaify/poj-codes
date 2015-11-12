#include<stdio.h>

int main()
{

 int n,c,x;

    while(EOF!=scanf("%d",&n))
    {
 c=0;
          while(n--)
          {
                scanf("%d",&x);
                c^=x;
         }
         if(c)
               printf("YES\n");
         else
                   printf("NO\n");
    }

    return 0;
}
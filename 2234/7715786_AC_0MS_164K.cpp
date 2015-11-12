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
               printf("Yes\n");
         else
                   printf("No\n");
    }

    return 0;
}

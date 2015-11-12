#include<stdio.h>

int main()
{
     int n;
     while(EOF!=scanf("%d",&n))
{
      if(n%6==0)
            printf("2\n");
      else
            printf("1\n");
}
     return 0;
}
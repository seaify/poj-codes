#include<iostream>

int n;

int main()
{
    while(EOF!=scanf("%d",&n))
    {
       if((n&(-n))==n)
            printf("YES\n");
       else
            printf("NO\n"); 
    }
    return 0;
}

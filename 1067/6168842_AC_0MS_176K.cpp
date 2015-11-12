#include<iostream>
#include<math.h>
using namespace std;

int a,b;

int main()
{
    double e=(sqrt(5.0)+1.0)/2.0;
    
    while(EOF!=scanf("%d %d",&a,&b))
    {
          if(a>b)
             swap(a,b);
          if(a!=b&&floor(e*(b-a))==a)
              printf("0\n");
          else
              printf("1\n");
                          
    }
}


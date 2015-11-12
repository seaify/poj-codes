#include<iostream>

int n,k,t,c,num;

int main()
{
    while(EOF!=scanf("%d %d",&n,&k))
    {
          if(k==0||k==n)
              printf("1\n");
          else
          {
              t=n;
              num=0;
              c=2;
              
              while(t/c)
              {
                  num+=t/c;
                  c*=2; 
              }
              
              t=k;
              c=2;
              while(t/c)
              {
                   num-=t/c;
                   c*=2;
              }
              
              t=n-k;
              c=2;
              while(t/c)
              {
                    num-=t/c;
                    c*=2;
              }
              if(num>=1)
                    printf("0\n");
              else
                    printf("1\n");
          }
    } 
    return 0;
}

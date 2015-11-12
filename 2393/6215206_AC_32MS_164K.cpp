#include<iostream>

int N,S,small,x,y;
__int64 sum;

int main()
{
    int i,tmp;
    while(EOF!=scanf("%d %d",&N,&S))
    { 
          small=100000;
          sum=0;
          for(i=1;i<=N;i++)
          {
             scanf("%d %d",&x,&y);
             if(x-i*S<small)
                  small=x-i*S;
             sum+=(__int64)small*y+(__int64)i*S*y;
          }                    
          printf("%I64d\n",sum);           
    }
    return 0;
}

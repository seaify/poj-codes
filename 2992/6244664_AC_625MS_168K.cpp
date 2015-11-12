#include<iostream>

int prime[500];
int n,k,top;
__int64 result;


int main()
{
    int i,j,c,num;
    
    prime[1]=2;
    top=1;
    for(i=3;i<=431;i+=2)
    {
         for(j=2;j*j<=i;j++)
              if(i%j==0)
                 break; 
         if(j*j>i)
               prime[++top]=i;
    }
    
    while(EOF!=scanf("%d %d",&n,&k))
    {
         if(k==0||k==n)
         {
              printf("1\n");
              continue;
         }
         result=1;
         for(i=1;i<=top&&prime[i]<=n;i++)
         {
              num=0;
              
              j=n;
              c=prime[i];
              while(j/c)
              {
                    num+=j/c;
                    c*=prime[i];
              }
              
              j=k;
              c=prime[i];
              while(j/c)
              {                   
                    num-=j/c;
                    c*=prime[i];
              }
              
              j=n-k;
              c=prime[i];
              while(j/c)
              {                
                    num-=j/c;
                    c*=prime[i];
              }
              
              result*=(num+1);                               
         }
         printf("%I64d\n",result);
    }
}

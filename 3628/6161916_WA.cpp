#include<iostream>
#include<algorithm>
using namespace std;

int x[30],p[30];
int n,ans,sum,size,total;

int main()
{
    int i,j;
    
    for(i=0;i<=20;i++)
        p[i]=(1<<i);
        
    while(EOF!=scanf("%d %d",&n,&ans))
    {
          for(i=0;i<n;i++)
             scanf("%d",&x[i]);
             
          total=(1<<n);
          size=30000000;
          
          for(i=1;i<total;i++)
          {
               sum=ans;
               for(j=0;j<n;j++)
               {
                   if(i&p[j])
                      sum-=x[j];                                     
               }
               
               if(sum>=0&&sum<size)
                    size=sum;              
          }
          printf("%d\n",size);    
    }
}

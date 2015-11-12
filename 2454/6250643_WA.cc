#include<stdio.h>
#include<algorithm>
using namespace std;

int n,result;
int a[200],x[200];

int main()
{
    int i,sum,total,tmp;
    
    while(EOF!=scanf("%d",&n))
    {
                              
          total=0;
          for(i=0;i<3*n;i++)
          {
              scanf("%d",&x[i]);
              total+=x[i];
              a[i]=i;
          }
             
          while(1)
          {
               random_shuffle(a,a+3*n);    
               result=0;
               tmp=total;
               
               for(i=0;i<n;i++)
                   sum+=x[a[i]];
               tmp-=sum;
                   
               if(sum>n*500)
                    result++;
               
               sum=0;
               for(i=n;i<2*n;i++)
                   sum+=x[a[i]];
               tmp-=sum;
                   
               if(sum>n*500)
                    result++;
                    
               if(tmp>n*500)
                    result++;
                    
               if(result>=2)
                    break;
          } 
          
          for(i=0;i<3*n;i++)
               printf("%d\n",a[i]+1);
              
              
          
    }
    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

int x[30000];
int n,ans,sum,size;

int main()
{
    int i;
    
    while(EOF!=scanf("%d %d",&n,&ans))
    {
          for(i=1;i<=n;i++)
             scanf("%d",&x[i]);
             
          sort(x+1,x+n+1);
          
          size=0;
          
          for(i=n;i>=1;i--)
          {
              sum+=x[i];
              size++;
              if(sum>=ans)
              {
                 printf("%d\n",size);
                 break;
              }
          }
    }
}

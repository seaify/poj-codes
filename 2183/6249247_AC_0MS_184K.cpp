#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

map < int ,int > H;

int n,mid;

int main()
{
    int step;
    while(EOF!=scanf("%d",&n))
    {
          H.clear();
          for(step=1; ;step++)
          {
              mid=n;
              if(n>=10000)
              {
                  mid-=n%10;
                  mid/=10;
              }
              mid%=10000;
              mid*=mid;
              mid%=1000000;
              if(H.count(mid))
              {
                  printf("%d %d %d\n",mid,step-H[mid],step);
                  break;
              }
              else
                  H[mid]=step;
              n=mid;
          }                       
    }
}

#include<iostream>
#include<algorithm>
using namespace std;

int n,result;
int a[200];

struct node
{
    int x,y;
};
node e[200];

int cmp(node a, node b)
{
    return a.x>b.x;
}

int main()
{
    int i,sum,total,tmp;
    
    while(EOF!=scanf("%d",&n))
    {
    
          for(i=0;i<3*n;i++)
          {
              scanf("%d",&e[i].x);
              e[i].y=i;
          }
       
          sort(e,e+3*n,cmp);
          
          for(i=2*n;i<3*n;i++)
              printf("%d\n",e[i].y+1); 
          
          total=0;
          for(i=0;i<2*n;i++) 
          {
                a[i]=i;
                total+=e[i].x;
          }
          
             
          while(1)
          {
               random_shuffle(a,a+2*n);    
    
               sum=0;
               
               for(i=0;i<n;i++)
                   sum+=e[a[i]].x;
                   
               if(sum>n*500&&total-sum>n*500)
                    break;
          } 
          
          for(i=0;i<2*n;i++)
               printf("%d\n",e[a[i]].y+1);
              
              
          
    }
    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

__int64 N,L,begin;
__int64 ans,num;

struct node
{
    __int64 x,y;
};

node e[20000];

int cmp(node a,node b)
{
    return a.x<b.x;
}


int main()
{
    int i,j;
    
  
    while(EOF!=scanf("%I64d %I64d",&N,&L))
    {
        for(i=1;i<=N;i++)
            scanf("%I64d %I64d",&e[i].x,&e[i].y);
            
        sort(e+1,e+N+1,cmp);
        
        ans=0;
        begin=e[1].x;
        i=1;
        
        while(i<=N)        ///////注意L的大小...... 
        {
            num=(e[i].y-begin+L-1)/L;
            begin+=num*L+1;////新的起点.. 
            ans+=num;
             
            j=i+1;
            
            while(1)
            {
               if(begin>e[j].y)
                    j++;
               else
               {
                   if(begin<=e[j].x)
                       begin=e[j].x;
                   break;
               }
              
            }
        
            i=j;
        }
              
        printf("%I64d\n",ans);
               
    } 
    return 0;
}

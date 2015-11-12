#include<iostream>
#include<algorithm>
using namespace std;

int N,T,begin,tmp;
int minx,maxx,sum;

struct node
{
    int x,y;
};
node e[30000];

int cmp(node a,node b)
{
    if(a.x!=b.x)
       return a.x<b.x;
    return a.y>b.y; 
}

int main()
{
    int i,j,flag;
    while(EOF!=scanf("%d %d",&N,&T))
    {
         minx=2000000;
         maxx=-1;
         for(i=1;i<=N;i++)
         {
             scanf("%d %d",&e[i].x,&e[i].y);
             if(e[i].x<minx)
                minx=e[i].x;
             if(e[i].y>maxx)
                maxx=e[i].y;
         }  
         if(minx!=1||maxx<T)
         {
             printf("-1\n");
             continue;
         }      
         
         sort(e+1,e+N+1,cmp);   
         
         tmp=e[1].y;
         i=1;
         sum=0;
         flag=1;
         
         while(i<=N&&flag)
         {
              begin=tmp;             
              sum++;
              j=i+1;
              tmp=-1;
              if(begin>=T)
                 break; 
              while(j<=N&&e[j].x<=begin+1)
              { 
                   if(e[j].y>tmp)
                      tmp=e[j].y;   
                   j++;              
              }
              if(tmp==-1)
              {
                 flag=0;
                 printf("-1\n");
              }
              i=j-1;
         }
         
         if(flag)
              printf("%d\n",sum);
         
                     
    }
    return 0;
}


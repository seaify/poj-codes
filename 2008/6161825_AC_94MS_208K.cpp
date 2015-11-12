#include<iostream>
#include<algorithm>
using namespace std;

int n,A,B,C,sum,ans;
int num[1100]; 

struct node
{
   int h,w,value,pos;
};
node e[1100],f[1100];

int cmp(node a ,node b)
{
    return a.w<b.w;
}

int cmp1(node a,node b)
{
    return a.value<b.value;
}

int main()
{
    int i,j,k;
    
    while(EOF!=scanf("%d",&n))
    {
                              
         scanf("%d %d %d",&A,&B,&C);
         
         for(i=1;i<=n;i++)
         {
            scanf("%d %d",&e[i].h,&e[i].w);
            e[i].value=A*e[i].h+B*e[i].w-C;
         }
            
         sort(e+1,e+n+1,cmp);
         
         for(i=1;i<=n;i++) 
         {
            f[i]=e[i];
            f[i].pos=i;
         }
         
         sort(f+1,f+n+1,cmp1);
         
         ans=0;
         
         for(i=1;i<=n;i++)
         {
             sum=0;
             k=1;
             for(j=1;j<=n;j++)
                num[j]=0;
             for(j=1;j<=n;j++)
             {
                  while(k<=n&&f[k].value<=A*e[i].h+B*e[j].w)
                  {
                        if(f[k].h>=e[i].h&&f[k].w>=e[j].w)
                        {
                            num[f[k].pos]++;
                            sum++;                              
                        }                                 
                        k++;
                  }           
                  if(sum>ans)
                     ans=sum;
                  sum-=num[j];
             }
         }
         
         printf("%d\n",ans);
         
    }
    return 0;
}

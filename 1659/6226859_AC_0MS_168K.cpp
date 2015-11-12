#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std; 

int n,T;
int map[20][20];

struct node
{
    int x,pos;
};
node a[100];

int cmp(node a,node b)
{
    return a.x>b.x;
}

int solve()
{
    int i,j,tp;
    
    sort(a+1,a+n+1,cmp);
    memset(map,0,sizeof(map));
    
    for(i=1;i<n;i++)
    {
        tp=i+a[i].x;
        if(tp>n)
           return 0;
        for(j=i+1;j<=tp;j++)
        {
             a[j].x--;
             map[a[i].pos][a[j].pos]=1;
             map[a[j].pos][a[i].pos]=1;
             if(a[j].x<0)
                 return 0;
        }
        sort(a+i+1,a+n+1,cmp);
    }
    
    if(a[n].x==0)
        return 1;
    
    return 0;
    
}

int main()
{
    int i,j,k,sum;
    scanf("%d",&T);
    for(k=1;k<=T;k++)
    {
         scanf("%d",&n);
         sum=0;
         for(i=1;i<=n;i++)
         {
             scanf("%d",&a[i].x);
             sum+=a[i].x;
             a[i].pos=i;
         }
         
        // printf("%d\n",sum);
         if(sum&1||!solve())
         {
              printf("NO\n\n");
              continue;
         }
         
         printf("YES\n");
         
         for(i=1;i<=n;i++)
         {
             for(j=1;j<n;j++)
                 printf("%d ",map[i][j]);
             printf("%d\n",map[i][n]);
         }
         
         if(k<T)
              printf("\n");
    }
    return 0;
}

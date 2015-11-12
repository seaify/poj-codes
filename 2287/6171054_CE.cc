#include<iostream>
#include<algorithm>
using namespace std;

int king[1100],x[1100];
int f[1100][1100];
int n,sum;

int cmp(int x,int y)
{
    if(x>y)
       return -200;
    if(x==y)
       return 0;
    return 200;
}

int main()
{
    int i,j;
    
    while(EOF!=scanf("%d",&n)&&n)
    {
         for(i=1;i<=n;i++)
            scanf("%d",&x[i]);
            
         for(i=1;i<=n;i++)
            scanf("%d",&king[i]);
            
         sort(x+1,x+n+1,greater<int>());
         sort(king+1,king+n+1,greater<int>());
         
         f[1][1]=cmp(king[1],x[1]);
         f[1][0]=cmp(king[1],x[n]);
         
                    
         for(i=2;i<=n;i++)
         {
            for(j=0;j<=i;j++)
             {
                 f[i][j]=-2000000;
                 
                 if(i!=j)
                    f[i][j]=f[i-1][j]+cmp(king[i],x[n-(i-j)+1]); 
           
                 if(j>0)
                 {
                    if(f[i-1][j-1]+cmp(king[i],x[j])>f[i][j])
                       f[i][j]=f[i-1][j-1]+cmp(king[i],x[j]);
                 }
             }                        
         }
         
        sum=-2000000;
        
        for(i=0;i<=n;i++)
           if(f[n][i]>sum)
              sum=f[n][i];
        
        printf("%d\n",sum);
            
                                 
    }
    
    return 0;
    
}

#include<iostream>
#include<math.h>

int n,flag;
int v[100],sum[100];
double p,ans;

void dfs(int x,double a,double b,double c)  ///a<=b<=c;
{
     double tmp;  
     
     if(a>=p||b>=p||c>=p) ////可行性剪枝.... 
          return ;
          
     tmp=sqrt(p*(p-a)*(p-b)*(p-c));  
     
     if(tmp<ans)           ///最优性剪枝.... ,当前可能的最大值.... 
            return ;
     
     if(x==n+1)
     {
          flag=1;
          ans=tmp;
          return ;
     }
     
   
     
     if(b+sum[n]-sum[x]<a||c+sum[n]-sum[x]<b)
           return ; 
     
     dfs(x+1,a+v[x],b,c); 
     dfs(x+1,a,b+v[x],c);
     dfs(x+1,a,b,c+v[x]);
     
    // printf("%lf %lf %lf\n",a,b,c); 
}

int main()
{
    int i;
    while(EOF!=scanf("%d",&n))
    {
         sum[0]=0;
         for(i=1;i<=n;i++)
         {
            scanf("%d",&v[i]);
            sum[i]=sum[i-1]+v[i];
         }
         p=(double)sum[n]/2.0;
         flag=0;
         ans=-1;
         dfs(1,0,0,0);
          
         if(flag)
              printf("%d\n",(int)(100*ans)); 
         else
              printf("-1\n");
    }
    return 0;
} 

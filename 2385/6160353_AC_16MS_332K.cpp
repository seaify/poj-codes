#include<iostream>

int f[1100][40][4];
int x[1100],a[1100],b[1100];
int n,w,top,ans;

int main()
{
    int i,j,k;
    while(EOF!=scanf("%d %d",&n,&w))
    {
         for(i=1;i<=n;i++)
            scanf("%d",&x[i]);
            
         top=0;
         x[0]=-1;
         
         for(i=1;i<=n;i++)
         {
             if(x[i]!=x[i-1])
             {
                 a[++top]=x[i];
                 b[top]=1;
             }
             else
                 b[top]++;
         }
         
         n=top;
         
      //   for(i=1;i<=n;i++)
    //         printf("%d %d\n",a[i],b[i]);
         
    
           for(k=1;k<=2;k++)
           {
                f[1][0][k]=0;
                if(k==a[1])
                  f[1][0][k]=b[1];
                f[1][1][k]=b[1];
           }
           
         for(j=2;j<=w;j++)
            for(k=1;k<=2;k++)
                f[1][j][k]=0;
           
         for(i=2;i<=n;i++)
           for(j=0;j<=w;j++)
             for(k=1;k<=2;k++)
             {
                 f[i][j][k]=0;
                 if(k==a[i])
                     f[i][j][k]=f[i-1][j][k]+b[i];
                 else
                     f[i][j][k]=f[i-1][j][k];
                 
                 if(j>=1)
                 {
                     if(f[i-1][j-1][3-k]+b[i]>f[i][j][k])
                        f[i][j][k]=f[i-1][j-1][3-k]+b[i];
                 }
                     
             }
             
         ans=0;
         
         for(j=0;j<=w;j++)
           for(k=1;k<=2;k++)
              if(f[n][j][k]>ans)
                 ans=f[n][j][k];
                 
         printf("%d\n",ans);
             
        
         
         
    }
    return 0;
} 

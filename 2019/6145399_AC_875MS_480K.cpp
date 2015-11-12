#include<iostream>

int n,B,K,small,big;
int a[400][400];

int main()
{
    int i,j,x,y;
    while(EOF!=scanf("%d %d %d",&n,&B,&K))
    {
          for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
               scanf("%d",&a[i][j]);
               
          while(K--)
          {
               scanf("%d %d",&x,&y);
               small=10000;
               big=-1;
               for(i=x;i<=x+B-1;i++)
                 for(j=y;j<=y+B-1;j++)
                 {
                     if(a[i][j]>big)
                          big=a[i][j];
                     if(a[i][j]<small)
                          small=a[i][j];                      
                 }
               printf("%d\n",big-small); 
          }
    }
}

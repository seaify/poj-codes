#include<stdio.h>
const int maxn=110;
int a[maxn][maxn],c[maxn][maxn];
int m,w,h,s,t,ans,tmp;

int main()
{
    int i,j,x,y;
    while(EOF!=scanf("%d",&m))
    {
        if(m==0)
             break;
        scanf("%d %d",&w,&h);
        
        for(i=0;i<=w;i++)
           for(j=0;j<=h;j++)
               a[i][j]=0,c[i][j]=0;
               
        while(m--)
        {
             scanf("%d %d",&x,&y);          
             a[x][y]=1;
        }
        scanf("%d %d",&s,&t);
        
        for(i=1;i<=w;i++)
           for(j=1;j<=h;j++)
                c[i][j]=a[i][j]+c[i][j-1]+c[i-1][j]-c[i-1][j-1];
                
        ans=0;
        for(i=1;i+s-1<=w;i++)
        {
               for(j=1;j+t-1<=h;j++)
               {
                    tmp=c[i+s-1][j+t-1]-c[i-1][j+t-1]-c[i+s-1][j-1]+c[i-1][j-1];
                    if(tmp>ans)
                          ans=tmp;
               }
        }
        printf("%d\n",ans);                                       
    }
    return 0;
}

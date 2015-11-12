#include<stdio.h>
#include<algorithm>
using namespace std;

const int N=2400;

int n1,n2,n3,L;
int a[N],b[N],px[N],py[N],x[N],y[N],s[N][N],c[N][N];

int check(int x0,int y0,int x1,int y1)
{
    return c[x1][y1]-c[x0-1][y1]-c[x1][y0-1]+c[x0-1][y0-1];
}

int main()
{
    int i,j,sum;
    while(EOF!=scanf("%d %d %d",&n1,&n2,&n3))
    {
          for(i=0;i<N;i++)
          {
              x[i]=0,y[i]=0;
              for(j=0;j<N;j++)
                  s[i][j]=0,c[i][j]=0;
          }
          
          for(i=1;i<=n1;i++)
          {
              scanf("%d",&b[i]);
              y[b[i]]=1;
          }
          
          for(i=1;i<=n2;i++)
          {
              scanf("%d",&a[i]);
              x[a[i]]=1;
          }
          
          for(i=1;i<=n3;i++)
          {
              scanf("%d %d",&px[i],&py[i]);
              s[px[i]][py[i]]=1;
          }
          
          sort(b+1,b+n1+1);
          sort(a+1,a+n2+1);
          
          c[0][0]=s[0][0];
          for(i=1;i<N;i++)
              c[0][i]=c[0][i-1]+s[0][i];
          
          for(i=1;i<N;i++)
              c[i][0]=c[i-1][0]+s[i][0];
          
          for(i=1;i<N;i++)
             for(j=1;j<N;j++)
                  c[i][j]=c[i][j-1]-c[i-1][j-1]+c[i-1][j]+s[i][j];
          
          sum=0;
          
          for(L=1;L<N;L++)
          {
              for(i=1;i<=n1&&b[i]+L<N;i++)
              {
                   if(y[b[i]+L]==0)
                        continue;
                   
                   for(j=1;j<=n2&&a[j]+L<N;j++)
                   {
                        if(x[a[j]+L]==0)
                              continue;
                        
                        if(check(a[j],b[i],a[j]+L,b[i]+L))
                              sum++;
                   }
              }
          }
          
          printf("%d\n",sum);
                           
              
    }
    return 0;
}

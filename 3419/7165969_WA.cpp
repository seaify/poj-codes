#include<stdio.h>
#include<math.h>

const int maxn=400100;
const int INF=1000000;

#define min(a,b)  (a)<(b)?(a):(b);

int n,m;
int max[maxn][20],a[maxn],f[maxn];
int flag[2000100],p[30];

void init()
{
 int i,j,m;
 m=int(log((double)n)/log(2.0));
 for(i=1;i<=m;i++)
   for(j=n+1-p[i];j>=1;j--)
	   max[j][i]=max[j][i-1]>max[j+p[i-1]][i-1]?max[j][i-1]:max[j+p[i-1]][i-1];
}

int RMQ(int i,int j)
{
   int m,a;
   m=int(log((double)(j-i+1))/log(2.0));
   a=max[i][m]>max[j-p[m]+1][m]?max[i][m]:max[j-p[m]+1][m];
   return a;
}


int main()
{
    int i,x,y;
    for(i=0;i<=20;i++)
	   p[i]=(1<<i);
 
    while(EOF!=scanf("%d %d",&n,&m))
    {
          for(i=1;i<=n;i++)
              scanf("%d",&a[i]);
          
          for(i=0;i<=2*INF;i++)
              flag[i]=n+1;
                  
          f[n+1]=n;
          for(i=n;i>=1;i--)
          {       
              f[i]=min(f[i+1],flag[a[i]+INF]-1);           
              flag[a[i]+INF]=i;
          }
          
          for(i=1;i<=n;i++)
              max[i][0]=f[i]-i+1;
          
          init();
          
          while(m--)
          {
              scanf("%d %d",&x,&y);
              printf("%d\n",RMQ(x+1,y+1));
          }
    }

    return 0;
}

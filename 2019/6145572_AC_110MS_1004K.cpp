#include<stdio.h>
#include<deque>
using namespace std;
const int maxn=300;

int a[maxn][maxn],small[maxn][maxn],big[maxn][maxn];
int minx[maxn][maxn],maxx[maxn][maxn];
int q[maxn],l[maxn],r[maxn];
int N,K,Q,ls,rs;  

deque < int > c,d;

void solve(int cur)
{
   int v,t,c1,d1;
   t=q[cur];
   while(!c.empty())
   {
	 v=q[c.back()];
     if(v<=t) 
        c.pop_back();
      else
        break;
   }
   c.push_back(cur);
   c1=c.front();
   if(cur-c.front()>=K)
       c.pop_front();
   if(cur>=K)
       r[++rs]=c.front();
   while(!d.empty())
   {
	  v=q[d.back()];
      if(v>=t)
        d.pop_back();
      else
        break;
   }
   d.push_back(cur);
   d1=d.front();
   if(cur-d.front()>=K)
       d.pop_front();
   if(cur>=K)
       l[++ls]=d.front();
}

void init()
{
     int i,j;
     
     for(j=1;j<=N;j++)
     { 
         c.clear();
         d.clear();
         ls=0;
         rs=0;
         for(i=1;i<=N;i++)
             q[i]=a[i][j];
             
         for(i=1;i<=N;++i)
            solve(i);  
         for(i=1;i<=N-K+1;i++)
         {
             minx[i][j]=q[l[i]];
             maxx[i][j]=q[r[i]];
         }           
     }
     
     /*printf("\n");
     
     for(i=1;i<=N-K+1;i++)
     {
        for(j=1;j<=N;j++)
          printf("%d ",minx[i][j]);
        printf("\n");
     }
     
     printf("\n");
     
     for(i=1;i<=N-K+1;i++)
     {
        for(j=1;j<=N;j++)
          printf("%d ",maxx[i][j]);
        printf("\n");
     }
     
     printf("\n");*/
     
     for(i=1;i<=N-K+1;i++)
     {
         c.clear();
         d.clear();
         ls=0;
         rs=0;
         for(j=1;j<=N;j++)
            q[j]=minx[i][j];
            
         for(j=1;j<=N;j++)
            solve(j);
         
         for(j=1;j<=N-K+1;j++)
            small[i][j]=q[l[j]];
            
         c.clear();
         d.clear();
         ls=0;
         rs=0;
         for(j=1;j<=N;j++)
            q[j]=maxx[i][j];
            
         for(j=1;j<=N;j++)
            solve(j);
            
         for(j=1;j<=N-K+1;j++)
            big[i][j]=q[r[j]];
            
         
             
     }
     
     
}

int main()
{

   int i,j;
   
   while(EOF!=scanf("%d %d %d",&N,&K,&Q))
   {
                        
       for(i=1;i<=N;++i)
          for(j=1;j<=N;++j)
            scanf("%d",&a[i][j]);
            
       
       init();
            
            
       while(Q--)
       {
            scanf("%d %d",&i,&j);
         //   printf("%d %d\n",big[i][j],small[i][j]);
            printf("%d\n",big[i][j]-small[i][j]);
       }
            
     
   }
   return 0;
}


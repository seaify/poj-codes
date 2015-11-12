#include<stdio.h>
const int maxn=1100000;
const int INF=2000;

int n,m,tot;
int x[maxn],y[maxn],num[maxn];
int U[maxn],D[maxn],L[maxn],R[maxn];
int ok[1100],tail[1100],q[1100];


void remove(int c)
{
     
     int i,j;
     
     R[L[c]]=R[c];
     L[R[c]]=L[c];
     
     for(i=D[c];i!=c;i=D[i])
         for(j=R[i];j!=i;j=R[j])
         {
              U[D[j]]=U[j];
              D[U[j]]=D[j]; 
              num[y[j]]--;
         }
                                     
}

void resume(int c)
{
     int i,j;
     
     for(i=U[c];i!=c;i=U[i])
        for(j=L[i];j!=i;j=L[j])
        {
             U[D[j]]=j;
             D[U[j]]=j;
             num[y[j]]++;
        } 
     
     R[L[c]]=c;
     L[R[c]]=c;   
     
}

int dfs(int k)
{
     int count,i,j,c;
     
     if(R[0]==0)      
     {
          
         printf("Yes, I found it\n");                        
         return 1;
     }
     
     count=INF;
     
     for(i=R[0];i!=0;i=R[i])
         if(num[i]<count)
         {
              count=num[i];
              c=i;       ////对于入口 
         }
         
     remove(c);
     
     for(i=D[c];i!=c;i=D[i])
     {
        ok[k]=x[i];
        for(j=R[i];j!=i;j=R[j])
                remove(y[j]);
                
        if(dfs(k+1))
              return 1;
        
        for(j=L[i];j!=i;j=L[j])
              resume(y[j]);
     }
     
     resume(c);
     
     return 0;
         
} 

void init()
{
     
   int i,j,col,c;
   
   for(i=0;i<=m;i++)  /////不需要初始化x,y,根本不会用上.... 
   {
       L[i]=i-1;
       R[i]=i+1;
       U[i]=i;
       D[i]=i;
       num[i]=0;
       tail[i]=i;    ////尾部指针.... 
	   y[i]=i;
   }
   
   L[0]=m;
   R[m]=0;
   
   tot=m;
   
   for(i=1;i<=n;i++)
   {
                    
       c=0;
       for(j=1;j<=m;j++)
       {
           scanf("%d",&col);
           if(col)
              q[++c]=j;
       }
           
       
       for(j=1;j<=c;j++)
       {
                        
           col=q[j];
           
           
           x[tot+j]=i;
           y[tot+j]=col;
           
           
           R[tot+j]=tot+j+1;
           L[tot+j]=tot+j-1;
           
           U[col]=tot+j;
           D[tail[col]]=tot+j;
           U[tot+j]=tail[col];
           D[tot+j]=col;
           tail[col]=tot+j;
           num[col]++;
           
       }
       
      if(c)
      {
          L[tot+1]=tot+c;
          R[tot+c]=tot+1;
      }
       
      tot+=c;
       
   }
   
  
       
   for(i=1;i<=m;i++)
       if(num[i]==0)
       {
           printf("It is impossible\n");
           return ;
       }
       

   if(!dfs(0))
	   printf("It is impossible\n");
    
         
}

int main()
{
    while(EOF!=scanf("%d %d",&n,&m))
    {
          init();
    }
    return 0;
} 

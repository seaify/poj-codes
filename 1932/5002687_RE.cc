#include<stdio.h>
const int INF=110000000;
int c,flag,d[11000],value[11000],close[11000];
struct node
{
  int x,y,value;
};
node edge[200002];
int output(int i)
{
   if(i==1)
        return 1;
   if(d[i]<=0)
        return 0;
   if(close[i]==-1)
        return 0;
   output(close[i]); 
} 
int main()
{
  int i,j,k,m,n;
  while(EOF!=scanf("%d",&n))
  {   
   if(n==-1)
         break; 
   m=0;
   for(i=1;i<=n;++i)
   {
     d[i]=-INF;
     close[i]=-1;//表示其前驱。。。。 
     scanf("%d%d",&value[i],&k);
     while(k--)
     {
       scanf("%d",&j);
       edge[++m].x=i;
       edge[m].y=j;
     }
   }  
   for(i=1;i<=m;++i)
      edge[i].value=value[edge[i].y];                    
   flag=1;d[1]=100;
   for(i=1;i<n&&flag;++i)
   {
     flag=0;
     for(j=1;j<=m;++j)
         if(d[edge[j].y]<=d[edge[j].x]+edge[j].value)//注意对0的处理。。。 
             d[edge[j].y]=d[edge[j].x]+edge[j].value,close[edge[j].y]=edge[j].x,flag=1;
   }
   flag=output(n);
   if(flag)
       printf("winnable\n");
   else
       printf("hopeless\n");         
  }
  return 0;
}


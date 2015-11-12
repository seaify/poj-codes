#include<stdio.h>
#include<string.h>
const int INF=100000000;
int map[110][110],N,M,d[110],L[110],P[110];
bool flag[110];
int Dijkstra(int beg)
{
   int end,i,j,minv,x,last;
   end=beg+M;
   memset(flag,false,sizeof(flag)); 
   for(i=1;i<=N;++i)//其实可以用二分优化的。。。。 
   {
       d[i]=INF;
       if(L[i]<beg||L[i]>end)
          flag[i]=true;
   }
   for(i=2;i<=N;++i)
       d[i]=map[1][i];
   flag[1]=true;d[1]=0;
   last=P[1];
   for(i=1;i<N;++i)
   {
       minv=INF;
       x=-1;
       for(j=2;j<=N;++j)
          if(!flag[j]&&d[j]<minv)
              minv=d[j],x=j; 
       if(x==-1)
          break;
       flag[x]=true;
       if(minv+P[x]<last)
           last=minv+P[x];
       for(j=2;j<=N;++j)
          if(!flag[j]&&minv+map[x][j]<d[j])
               d[j]=minv+map[x][j];               
   }
   return last;
}
int main()
{
   int i,j,X,V,minx,temp,T;
   while(EOF!=scanf("%d%d",&M,&N))
   {
      for(i=1;i<=N;++i)
      {
        for(j=1;j<=N;++j)
             map[i][j]=INF;
        map[i][i]=0;
      }
      for(i=1;i<=N;++i)
      {
         scanf("%d%d%d",&P[i],&L[i],&X);
         while(X--)
         {
           scanf("%d%d",&T,&V);
           map[i][T]=V;
         }
      }
    //  for(i=1;i<=N;++i)
//      {
//        for(j=1;j<=N;++j)
//           printf("%d ",map[i][j]);
//        printf("\n");
//      }
      minx=P[1];
      for(i=0;i<=M;++i)
      {
          temp=Dijkstra(L[1]-i);
          if(temp<minx)
             minx=temp;
      }
      printf("%d\n",minx);
   }
   return 0;
}

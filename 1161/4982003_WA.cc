#include<stdio.h>
#include<vector>
using namespace std;
const int INF=100000000;
vector < int > map[300];
int N,M,L,i,j,k,a[300],f[300][300],d[300][300],sum,last,minx;
int main()
{
  scanf("%d%d%d",&M,&N,&L);
  for(i=1;i<=N;++i)
         map[i].clear();
     for(i=1;i<=L;++i)
         scanf("%d",&a[i]);
     for(i=1;i<=M;++i)
     {
       scanf("%d",&k);
       while(k--)
       {
         scanf("%d",&j);
         map[j].push_back(i);
       }
     }
     memset(f,0,sizeof(f));
     for(i=1;i<=N;++i)//无向图 
     {
       for(j=0;j<map[i].size();++j)
       {
         for(k=j+1;k<map[i].size();++k)
              ++f[map[i][j]][map[i][k]];
       }
     }
     for(i=1;i<=M;++i)
     {
       for(j=1;j<=M;++j)
            d[i][j]=INF;
       d[i][i]=0;
     }
     for(i=1;i<M;++i)
       for(j=i+1;j<=M;++j)
           if(f[i][j]>=2)
               d[i][j]=d[j][i]=1; 
            
   
    for(k=1;k<=M;++k)
      for(i=1;i<=M;++i)
        for(j=1;j<=M;++j)
        {
		   if(d[i][j]>d[i][k]+d[k][j])
              d[i][j]=d[i][k]+d[k][j];
        } 
	/*	for(i=1;i<=M;++i)
     { 
       for(j=1;j<=M;++j)
         printf("%d ",d[i][j]);
       printf("\n");
    } */
    sum=INF; 
    for(i=1;i<=M;++i) 
    {
       last=0;
       for(j=1;j<=L;++j)
       {
          minx=INF;
          for(k=0;k<map[a[j]].size();++k)
			  minx=minx<d[map[a[j]][k]][i]?minx:d[map[a[j]][k]][i];
          last+=minx;
       }
	   if(last<sum)
       sum=last;         
    }
    printf("%d\n",sum);                                   
  return 0;
}

#include<stdio.h>
#include<string.h> 
const int INF=100000000;
int N,M,L,i,j,k,map[300][300],a[300],edge[300][300],d[300][300],sum,minx;
int first,last,cur,temp;
int main()
{
    scanf("%d%d%d",&M,&N,&L);
    for(i=1;i<=L;++i)
         scanf("%d",&a[i]);
     memset(map,0,sizeof(map)); 
     memset(edge,0,sizeof(edge)); 
      for(i=1;i<=M;++i)
     {
       for(j=1;j<=M;++j)
            d[i][j]=INF;
       d[i][i]=0;
     }
     for(i=1;i<=M;++i)
     {
       scanf("%d",&k);
       scanf("%d",&first);//map[i][j]表示i和j号空地相邻 
       map[first][i]=1; 
       --k;last=first;
       while(k--)
       {
         scanf("%d",&cur);
         map[cur][i]=1;
         temp=edge[last][cur];
         if(temp>0)
              d[temp][i]=d[i][temp]=1;
         else
              edge[last][cur]=edge[cur][last]=i;
         last=cur;
       }
       temp=edge[last][first];
       if(temp>0)
           d[temp][i]=d[i][temp]=1;
       else
           edge[last][first]=edge[first][last]=i;
     }
    for(k=1;k<=M;++k)
      for(i=1;i<=M;++i)
        for(j=1;j<=M;++j)
        {
              d[i][j]<?=d[i][k]+d[k][j];
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
          for(k=1;k<=M;++k)//
          {
              temp=map[a[j]][k];
              if(temp==0)
                  continue;
			  minx<?=d[k][i];
			  if(minx==0)
                  break; 
          }
          last+=minx;
       }
	   sum<?=last;       
    }
    printf("%d\n",sum);                        
  return 0;
}


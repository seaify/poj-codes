#include<stdio.h>
int map[310][310],i,j,k,m,n,min,sum,a[310];
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
       for(j=1;j<=n;++j)
           map[i][j]=100000;
    while(m--)
    {
      scanf("%d",&k);
      for(i=1;i<=k;++i)
          scanf("%d",&a[i]);
      for(i=1;i<=k;++i)
          for(j=1;j<=k;++j)
             map[a[i]][a[j]]=map[a[j]][a[i]]=1;
    }
    for(k=1;k<=n;++k)
      for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            map[i][j]<?=map[i][k]+map[k][j];
    min=100000;
    for(i=1;i<=n;++i)
    {
      sum=0;map[i][i]=0;
      for(j=1;j<=n;++j)
         sum+=map[i][j];
      if(sum<min)
         min=sum;
    }
    min=int((100*min)/(n-1));
    printf("%d\n",min);
    return 0;
}

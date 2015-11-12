#include<stdio.h>//动态图的传递闭包，有向图
#include<string.h> 
int c[30],x[30],y[30],pos[30],i,j,k,s,t,n,last,first,m,sum,map[30][30];
char a[5];bool temp,flag[30];
void update(int s,int t)
{
   map[s][t]=1;
   for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
          if(i!=s&&t!=j)
            map[i][j]=map[i][j]||(map[i][s]&&map[t][j]);
          else if(i==s&&t!=j)
            map[i][j]=map[i][j]||map[t][j];
          else if(i!=s&&t==j)
            map[i][j]=map[i][j]||map[i][s];
   for(i=1;i<=n;++i)
       if(map[i][i])
       {
         last=1;
         first=k;
         return ;
       }
  for(i=1;i<=n;++i)
  {
     x[i]=0;y[i]=0;
     for(j=1;j<=n;++j)
     {
         x[i]+=map[i][j];
         y[i]+=map[j][i];//每一列的和 
        // printf("%d ",map[i][j]);      
     }
    // printf("\n");
  }  
  t=0;
  for(i=1;i<=n;++i)
      if(x[i]+y[i]==n-1)
           pos[y[i]]=i-1,++t;
  if(t==n)
  {
    first=k;
    last=2;
  }
}
int main()
{
  while(EOF!=scanf("%d%d",&n,&m))//动态地加入m条边 
  {
    if(n==0&&m==0)
        break;
    memset(map,0,sizeof(map));
    last=0;
    for(k=1;k<=m;++k)
    {
      scanf("%s",a);
      if(last!=0)
         continue;
      s=a[0]-'A'+1;
      t=a[2]-'A'+1;
      update(s,t);       
    }
    if(last==0)
        printf("Sorted sequence cannot be determined.\n");
    else if(last==1)
        printf("Inconsistency found after %d relations.\n",first);
    else
    {
        printf("Sorted sequence determined after %d relations: ",first);
        for(i=0;i<n;++i)
            printf("%c",'A'+pos[i]);
        printf(".\n");
    }
  }
}

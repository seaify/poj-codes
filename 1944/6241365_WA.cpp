#include<iostream>

int num[1100],map[1100][1100];
int pos[1100],v[1100];
int n,p,ans,small,big,sum;


int main()
{
    int i,j,k,x,y,tmp;
    while(EOF!=scanf("%d %d",&n,&p))
    {
          for(i=1;i<=n;i++)
              num[i]=0;
              
          for(i=1;i<=p;i++)
          {
              scanf("%d %d",&x,&y);
              map[x][++num[x]]=y;
              map[y][++num[y]]=x;
          }
          
          ans=2*n;                ///pos[i]表示在位置i的编号，v[i]表示编号i的位置.... 
          
          for(i=0;i<n;i++)  ///枚举.. 
          {
              for(j=1;j<=n;j++)
              {
                 tmp=j-i?j-i:n; 
                 pos[j]=tmp;
                 v[tmp]=j;
              }
              
              big=0;
              sum=0;
              
              for(j=1;j<=n;j++)
                 if(num[pos[j]])
                 {
                    if(j>big)
                       big=j-1;
                    
                     x=pos[j];
                     tmp=0;
                     for(k=1;k<=num[x];k++)
                     {
                       y=map[x][k];
                       if(v[y]>tmp)
                          tmp=v[y];
                     }
                      if(tmp>big)
                        sum+=tmp-big;
                       
               }
               
               if(sum<ans)
                    ans=sum;
               

          }
          printf("%d\n",ans);
    }
    return 0;
}

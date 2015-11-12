#include<stdio.h>

int n,x1,x2,y1,y2,tot,flag;
int dir[4][2]={{1,0},{1,-1},{0,1},{0,-1}};
int c[100],len[100],hh[10];

void dfs(int x,int y,int sum,int state)
{
     int i,j,x3,y3,tmp,use[5];              ////已经使用 
     
     if(sum>tot)
          return ;
          
     if(x==x2&&y==y2)
     {
          flag=1;
          return ;
     }
     
     tmp=state;     ///11进制 
     for(i=n;i>=1;i--)
     {
         use[i]=tmp%11;
         tmp/=11;
     } 
          
     for(i=1;i<=n&&flag==0;i++)
         if(use[i]<c[i])
         {
            for(j=0;j<4&&flag;j++)
            {
                x3=x+len[i]*dir[j][0];
                y3=y+len[i]*dir[j][1];
                dfs(x3,y3,sum+1,state+hh[n-i]);
            }
         }
}

int main()
{
    int i,sum;
    hh[0]=1;
    for(i=1;i<=4;i++)
          hh[i]=hh[i-1]*11;
    while(EOF!=scanf("%d %d %d %d",&x1,&y1,&x2,&y2))
    {
          scanf("%d",&n);
          sum=0;
          for(i=1;i<=n;i++)
          {
              scanf("%d %d",&len[i],&c[i]);
              sum+=c[i];
          }
          if(x1==x2&&y1==y2)
          {
              printf("0\n");
              break;
          }
          for(tot=1;tot<=sum;tot++)
          {
                flag=0; 
                dfs(x1,y1,0,0);
                if(flag)
                    break;
          }
          if(tot>sum)
               printf("-1\n");
          else
               printf("%d\n",tot);
    }                 
    return 0;
}

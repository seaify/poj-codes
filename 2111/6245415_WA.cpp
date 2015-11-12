#include<iostream>
#include<algorithm>
using namespace std;

int n,ans,flag;
int a[400][400];
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

int in[160000],map[160000][9],path[160000],num[160000];

void dfs(int x,int depth)
{
     int i;
     if(num[x]==0&&depth>ans)
             ans=depth;
     for(i=1;i<=num[x];i++)
           dfs(map[x][i],depth+1);
}

void DFS(int x,int depth)
{
     int i;
     
     if(flag==0&&num[x]==0&&depth==ans)
     {
           for(i=1;i<=ans;i++)
           {
               // printf("%d ",path[i]);
                printf("%d\n",a[path[i]/n][path[i]%n]);
           }
           flag=1;                
     }
   //  printf("%d %d\n",depth,ans);
     
     if(flag)
         return ;
         
      for(i=1;i<=num[x];i++)
      {
           path[depth+1]=map[x][i];
           DFS(map[x][i],depth+1);   
      }
}



int main()
{
    int i,j,k,x,y;
    
    while(EOF!=scanf("%d",&n))   /////记住加入点 
    {
         for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
         
         for(i=0;i<=n*n;i++)
         {
                num[i]=0;
                in[i]=0;
         }
                
         for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                 for(k=0;k<8;k++)
                 {
                      x=i+dir[k][0];
                      y=j+dir[k][1];
                      if(x>=0&&x<n&&y>=0&&y<n&&a[i][j]<a[x][y])
                      {
                           in[x*n+y]++; 
                           num[i*n+j]++;
                           map[i*n+j][num[i*n+j]]=x*n+y;
                      }
                 }
                 sort(map[i*n+j]+1,map[i*n+j]+num[i*n+j]+1);
                /* for(k=1;k<=num[i*n+j];k++)
                      printf("%d ",map[i*n+j][k]);
                 printf("\n");*/
            }
            
         for(i=0;i<n*n;i++)
            if(in[i]==0)
            {
                num[n*n]++;
                map[n*n][num[n*n]]=i;
            } 
                 
                
         ans=-1;
              
         dfs(n*n,0);    /////
           
         printf("%d\n",ans);
         
         flag=0;
         DFS(n*n,0);

         
        
      //   output(big);
    }
    return 0;
}

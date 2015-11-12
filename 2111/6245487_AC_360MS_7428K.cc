#include<stdio.h>
#include<algorithm>
using namespace std;

int n,ans,flag;
int a[400][400];
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

int in[160000],map[160000][9],path[160000],num[160000];
int dp[160000];

int cmp(int x,int y)
{
	return a[x/n][x%n]<a[y/n][y%n];
}

int dfs(int x,int depth)
{
     int i,tmp;

     if(num[x]==0)
             dp[x]=1;

	 if(dp[x]>0)
		 return dp[x];

     for(i=1;i<=num[x];i++)
	 {
           tmp=dfs(map[x][i],depth+1);
		   if(tmp+1>dp[x])
			   dp[x]=tmp+1;
	 }

	 return dp[x];
}

void DFS(int x,int depth)
{
     int i;
     
     if(flag==0&&num[x]==0&&depth==ans)
     {
           for(i=1;i<=ans;i++)
           {
         
                printf("%d\n",a[path[i]/n][path[i]%n]);
           }
           flag=1;                
     }
   
     
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
				dp[0]=0;
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
                 sort(map[i*n+j]+1,map[i*n+j]+num[i*n+j]+1,cmp);
         
            }
            
         for(i=0;i<n*n;i++)
            if(in[i]==0)
            {
                num[n*n]++;
                map[n*n][num[n*n]]=i;
            } 
                 
		 sort(map[n*n]+1,map[n*n]+num[n*n]+1,cmp);
                
       
              
         ans=dfs(n*n,0);    /////
		 ans--;
           
         printf("%d\n",ans);
         
         flag=0;
         DFS(n*n,0);

         
    }
    return 0;
}

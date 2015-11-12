#include<iostream>

const int mod=100000000;

int a[5000][2];
int map[20][20];
int m,n,x,sum,tmp;

void dfs(int last,int now ,int depth)
{
     if(depth==n)
     {
         if(tmp)
              a[now][x]=(a[now][x]+a[last][1-x])%mod;
         else
              a[now][x]=1;
         return ;
     }
 
     dfs(last<<1,now<<1,depth+1);

     if(tmp&&map[tmp-1][depth]&&(last&1)==0)
             dfs((last<<1)+1,now<<1,depth+1); 
  
     if((now&1)==0&&map[tmp][depth])
         dfs(last<<1,(now<<1)+1,depth+1);    

}

int main()
{
    int i,j;
    while(EOF!=scanf("%d %d",&m,&n))
    {
         for(i=0;i<m;i++)
           for(j=0;j<n;j++)
             scanf("%d",&map[i][j]);
             
         for(i=0;i<(1<<n);i++)
             a[i][0]=a[i][1]=0;
             
         for(i=0;i<m;i++)
         {
             tmp=i;
             x=(i&1);   ////求第x 
             dfs(0,0,0);
             for(j=0;j<(1<<n);j++)
                 a[j][1-x]=0;
         }
         
         sum=0;
         for(j=0;j<(1<<n);j++)
             sum=(sum+a[j][x])%mod;
             
         printf("%d\n",sum);
    }
    return 0;
}

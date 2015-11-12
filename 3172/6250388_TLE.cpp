#include<iostream>

int a[100];
int N,C,ans;

void dfs(int sum,int depth)
{
     __int64 tmp;
         
     if(sum>C)
          return ;
          
     if(sum>ans)
          ans=sum;
          
     if(ans==C)
          return ; 
	 
     if(depth==N+1)
          return ;
     
     dfs(sum,depth+1);
     
     tmp=sum;
     tmp+=a[depth];
     
     if(tmp>C)
         return ;
     else
         dfs(sum+a[depth],depth+1);
         
}

int main()
{
    int i,flag;
    
    while(EOF!=scanf("%d %d",&N,&C))
    {
          flag=0;
          for(i=1;i<=N;i++)
          {
              scanf("%d",&a[i]);
              if(a[i]==C)
                  flag=1;
          }
          if(flag)
          {
              printf("%d\n",C);
              continue;
          }
          
          for(i=1;i<=N;i++)
              if(a[i]>C)
                   break;
                   
          N=i-1;
          
          ans=-1;
          dfs(0,1);
          printf("%d\n",ans);
                     
    }
 
}

#include<iostream>

int a[100],b[100];
__int64 total[100],ans;
int N,C;

void dfs(__int64 sum,int depth)
{
         
     if(sum>C)
          return ;
          
     if(sum>ans)
          ans=sum;
          
     if(ans==C)
          return ; 
	 
     if(depth==N+1)
          return ;

	 if(total[N]-total[depth-1]+sum<ans)
		  return ;
     
     dfs(sum+a[depth],depth+1); 
	 
	 dfs(sum,depth+1);
         
}

int main()
{
    int i,j,flag;
    
    while(EOF!=scanf("%d %d",&N,&C))
    {

          flag=0;

          for(i=1;i<=N;i++)
          {
              scanf("%d",&b[i]);
              if(b[i]==C)
                  flag=1;
          }

          if(flag)
          {
              printf("%d\n",C);
              continue;
          }
          
          for(i=1;i<=N;i++)
              if(b[i]>C)
                   break;
                   
          N=i-1;

		  j=N;
		  total[0]=0;

		  for(i=1;i<=N;i++,j--)
		  {
			  a[i]=b[j];
			  total[i]=total[i-1]+a[i];
		  }
          
          ans=-1;
          dfs(0,1);

          printf("%I64d\n",ans);
                     
    }

	return 0;
 
}


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const int INF=80000000;

int N,M,result;

void dfs(int R1,int H1,int V,int S,int depth)
{
	 int R,H,p;

	 if(depth==M+1)
	 {
         if(V==N&&S<result)
			 result=S;
		 return ;
	 }


	 if(R1&&(2*N-2*V)/R1+S>=result)
		 return ;

     for(R=R1-1;R>=M-depth+1;R--)
	 {

		if(depth==1)
			S=R*R;


	    for(H=M-depth+1;H<H1;H++)
		{
			   
               if(V+R*R*H>N)

				   break;

               if(S+2*R*H>=result)
			        break;
  
			   
		   	  
 		  	  if(V+(M-depth+1)*H*R*R<N)
			        continue;


			   dfs(R,H,V+R*R*H,S+2*R*H,depth+1); 
		}

	 }
}

int main()
{
	while(EOF!=scanf("%d %d",&N,&M))
	{
          result=INF;


		  dfs(N+1,N+1,0,0,1);
		  if(result==INF)
		         printf("0\n");
		  else
		         printf("%d\n",result);
	}
	return 0;
}
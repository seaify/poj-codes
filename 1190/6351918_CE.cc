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


     for(R=R1-1;R>=M-depth+1;R--)
	 {
		if(depth==1)
			S+=R*R;


	    for(H=M-depth+1;H<H1;H++)
		{
			   
               if(V+R*R*H>N)
				   break;

               if(S+2*R*H>=result)
			        break;

			   
	         /* p=(2*N-2*V-2*R*R*H)/R;

		      if(S+2*R*H+p>=result)
			       continue;
		   	*/  
 		  	  if(V+(M-depth+1)*H*R*R<N)
			        continue;


			   dfs(R,H,V+R*R*H,S+2*R*H,depth+1); 
		}

		if(depth==1)
		       S-=R*R;
	 }
}

int main()
{
	int maxh,maxr;
	while(EOF!=scanf("%d %d",&N,&M))
	{

          result=INF;
          maxh=(6*N)/(M*(M+1)*(2*M+1));
          maxr=ceil(sqrt((2*N/(M*M+M))*1.0));


		  dfs(maxr+1,maxh+1,0,0,1);
		  if(result==INF)
		         printf("0\n");
		  else
		         printf("%d\n",result);
	}
	return 0;
}
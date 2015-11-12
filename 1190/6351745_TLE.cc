#include<stdio.h>

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


     for(R=R1+1;V+R*R<=N;R++)
	 {
		if(depth==M)
			S+=R*R;

	    for(H=H1+1;V+H*R*R<=N;H++)
		{
               if(S+2*R*H>=result)
			        break;

			   
		       if(V+(M-depth+1)*H*R*R>N)
			        break;

			   if(S+2*R*H*(M-depth+1)>=result)
				    break;
			   
			   ////最大的都比N小
               
			  /* p=(2*N-2*V)/R;

			   if(S+p>=result)
				    continue;*/
		   	  
			   dfs(R,H,V+R*R*H,S+2*R*H,depth+1); 
		}

		if(depth==M)
		       S-=R*R;
	 }
}

int main()
{
	while(EOF!=scanf("%d %d",&N,&M))
	{
          result=INF;
		  dfs(0,0,0,0,1);
		  if(result==INF)
		         printf("0\n");
		  else
		         printf("%d\n",result);
	}
	return 0;
}
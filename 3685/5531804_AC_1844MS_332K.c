#include<stdio.h>
#include<string.h>
const __int64 INF=(1<<60);
__int64 N,M,i,left,right,mid,T;

__int64 solve(__int64 i,__int64 j)
{
       return i*i+100000*i+j*j-100000*j+i*j;
}

int check(__int64 v)   /////nlogn
{
      __int64 sum=0,j,left,right,mid;
	  for(j=1;j<=N;++j)
	  {
		  left=1;
		  right=N;
		  while(left<=right)
		  {
			  mid=(left+right)/2;
			  if(solve(mid,j)>v)
				  right=mid-1;
			  else
				  left=mid+1;
		  }
		  sum+=right;   ///right指向最前面的
	  }
	  if(sum>=M)
		  return 1;
	  return 0;
}

int main()
{
	__int64 i,j,x,y;
	scanf("%I64d",&T);
	while(T--)
	{
		 scanf("%I64d %I64d",&N,&M);
		 left=INF;
		 right=-INF;
		/* for(i=1;i<=N;++i)
		 {
			 for(j=1;j<=N;++j)
				 printf("%I64d ",solve(i,j));
			 printf("\n");
		 }*/
         for(i=1;i<=N;++i)   ///
		 {
			 x=solve(1,i);
			 y=solve(N,i);
			 if(x>right)
				 right=x;
			 if(y>right)
				 right=y;
			 if(x<left)
				 left=x;
			 if(y<left)
				 left=y;
		 }
		 while(left<=right)  
		 {
			 mid=(left+right)/2;
			 if(check(mid))
				 right=mid-1;
			 else
				 left=mid+1;
		 }
		 printf("%I64d\n",left);
	}
	return 0;
}

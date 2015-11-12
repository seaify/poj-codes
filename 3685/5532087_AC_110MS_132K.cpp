#include<cstdio>
#include<cstring>
const __int64 INF=(1<<60);
__int64 i,M,left,right,mid,N;

__int64 solve(__int64 i,__int64 j)
{
       return i*i+100000*i+j*j-100000*j+i*j;
}

int check(__int64 v)   /////nlogn
{
      __int64 sum=0,j,right=N;;
	  for(j=N;j>=1;j--)
	  {
		  while(right>=1&&solve(right,j)>v)
			  right--;
		  sum+=right;   ///right指向最前面的
	  }
	  if(sum>=M)
		  return 1;
	  return 0;
}

int main()
{
	int T;
	__int64 x,y;
	scanf("%d",&T);
	while(T--)
	{
		 scanf("%d %I64d",&N,&M);
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

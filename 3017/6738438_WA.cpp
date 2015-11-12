#include<stdio.h>

__int64 N,M,sum[110000],f[110000];
__int64 a[110000],p[110000];

__int64 max(__int64 a,__int64 b)
{
        return a>b?a:b;
}
        
void dp()
{
   __int64 i,j,tmp,maxv;
   f[0]=0;
   f[1]=a[1];
   p[1]=1;
   maxv=a[1];
   for(i=2;i<=N;i++)
   {
	f[i]=-1;
        if(sum[i]-sum[p[i-1]-1]>M)
	{
	      tmp=0;
	      for(j=i;j>=1&&sum[i]-sum[j-1]<=M;j--)
	      {
		    tmp=max(tmp,a[j]);
          if(f[i]==-1||f[j-1]+tmp<f[i])
		    {
			f[i]=f[j-1]+tmp;
			p[i]=j;
			maxv=tmp;
		    }
	      }
	}
	else
	{
	     if(a[i]<=maxv)
	     {
		    f[i]=f[i-1];
		    p[i]=p[i-1];
	     }
	     else
	     {
		    tmp=a[i];
		    for(j=p[i-1];j>=1&&sum[i]-sum[j-1]<=M;j--)
		    { 
                    tmp=max(tmp,a[j]);
			
                        if(f[i]==-1||f[j-1]+tmp<f[i])
			{
			   f[i]=f[j-1]+tmp;
			   p[i]=j;
			   maxv=tmp;
             
			} 
           
		    }
	     }
	}

   }
   printf("%I64d\n",f[N]);
}

int main()
{
    int i,flag;
    
    scanf("%I64d %I64d",&N,&M);
    
	  flag=0;sum[0]=0;
	  for(i=1;i<=N;i++)
	  {
	      scanf("%I64d",&a[i]);
	      sum[i]=sum[i-1]+a[i];
	      if(a[i]>M)
		   flag=1;
	  }
	  if(flag)
	      printf("-1\n");
          dp();
    
    return 0;
}


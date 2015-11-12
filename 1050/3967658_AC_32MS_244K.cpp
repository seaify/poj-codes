#include<stdio.h>  
 #include<string.h> 
long getmax(int n,long *b)
{   
	long c,i,max;
	c=0;
	for(i=1;i<=n;i++)
	{
		if(c>0)
			c=c+b[i];
		else
			c=b[i];
		if(c>max)
			max=c;
	}
	return max;
}
 int main()  
 {   int i,j,k,n,m;
     long mmax,b[105],a[105][105],h;
	 scanf("%d",&n);
	 for(i=1;i<=n;i++)
		 for(j=1;j<=n;j++)
			 scanf("%d",&a[i][j]);
	 mmax=0;
	 for(i=1;i<=n;i++)
		 for(j=i;j<=n;j++)
		 {
			 memset(b,0,sizeof(b));
			 
			 for(k=1;k<=n;k++)
				 for(m=i;m<=j;m++)
					 b[k]+=a[m][k];
				 h=getmax(n,b);
				 if(h>mmax)
					 mmax=h;
		 }
		 printf("%ld\n",mmax);

    
     return 0;  
 }  


	

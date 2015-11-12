#include <stdio.h>
void f(int *a,int n)
{
	int i,begin,end,c,j;c=0;
	for(i=1;i<=n;i++)
	   if(a[i]!=0)
	   {
		   begin=i;
		   end=a[i];a[i]=0;
		   while(begin!=end)
		   {
			   j=end;
			   end=a[j];
			   a[j]=0;
		   }
		   c++;
	   }
	   
	   printf("%d\n",n-c);
}

int main()
{
	int i,n,t,a[10005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		f(a,n);
	}

	             
	return 0;
}

    
	
			   
   



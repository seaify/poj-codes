#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
     return(*(int *)a-*(int *)b);
}
void f(int *a,int n)
{   int i,j,c;
	qsort(a+1,n,sizeof(a[1]),cmp);c=0;
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
		{
			if(a[j]==2*a[i])
				c++;
			else if(a[j]>2*a[i])
				break;
		}
		printf("%d\n",c);
}

int main()
{
	int i,a[105],c;
	while(1)
	{
		memset(a,0,sizeof(a));c=0;
		for(i=1; ;i++)
		{
			scanf("%d",&a[i]);
		     if(a[i]==0)
			 {
				 f(a,i-1);
				 break;
			 }
			 if(a[i]==-1)
			 {c=1;break;}
		}
		if(c)
			break;
		
	}
	return 0;
}

    
   



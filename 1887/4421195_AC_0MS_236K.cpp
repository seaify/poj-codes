#include<stdio.h>
#include<string.h>
int time=1,f[45000],a[45000];
void solve(int n)
{
	int len,j,mid,left,right;
	len=1;f[len]=a[1];
	for(j=2;j<=n;j++)
		if(a[j]<f[len])
		{
			len++;
			f[len]=a[j];
		}
		else
		{
			left=1;
			right=len-1;
			while(left<=right)
			{		
				mid=(left+right)/2;
				if(a[j]>=f[mid])
				   right=mid-1;
				else
				  left=mid+1;
			}	
			f[left]=a[j];
		}
		printf("Test #%d:\n",time++);
		printf("  maximum possible interceptions: %d\n\n",len);
}
int main()
{
	int i=1;
	while(EOF!=scanf("%d",&a[i]))
	{
		if(a[1]==-1)
			break;
		if(a[i]==-1)
		{
			solve(i-1);
			i=1;
		    continue;
		}
		i++;
	}
	return 0;
}


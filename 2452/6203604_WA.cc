#include<stdio.h>
#include<math.h>

int a[50005];
int n,ans;

void dfs(int x,int y)
{
	int i,mid,min,ls,rs;
	if(x>=y)
		return ;
    
    ls=200000;
    rs=-1;
	for(i=x;i<=y;i++)
    {
        if(a[i]>rs)
           rs=a[i],mid=i;
        if(a[i]<ls)
           ls=a[i],min=i; 
    }
    
    if(mid-min>0&&mid-min>ans)
         ans=mid-min; 

	dfs(x,mid-1);
	dfs(mid+1,y);
	
}

int main()
{
	int i,x;

	while(EOF!=scanf("%d",&n))
	{
	    for(i=1;i<=n;i++)
		   scanf("%d",&a[i]);
	   	  
		ans=-1;
		dfs(1,n);
		printf("%d\n",ans);
	}
	
	return 0;
}


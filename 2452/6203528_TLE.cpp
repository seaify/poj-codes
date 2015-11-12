#include<stdio.h>
#include<math.h>
const int maxn=50005;
int min[maxn][18],max[maxn][18],p[20];
int pos[110000];
int n,ans;

void init()
{
	int i,j,m;
	m=int(log((double)n)/log(2.0));
	for(i=1;i<=m;i++)
		for(j=n+1-p[i];j>=1;j--)
		{
			max[j][i]=max[j][i-1]>max[j+p[i-1]][i-1]?max[j][i-1]:max[j+p[i-1]][i-1];
			min[j][i]=min[j][i-1]<min[j+p[i-1]][i-1]?min[j][i-1]:min[j+p[i-1]][i-1];
		}
}

int RMQ(int i,int j,int k)
{
	int m,a,b;
	m=int(log((double)(j-i+1))/log(2.0));
	a=max[i][m]>max[j-p[m]+1][m]?max[i][m]:max[j-p[m]+1][m];
	b=min[i][m]<min[j-p[m]+1][m]?min[i][m]:min[j-p[m]+1][m];
	if(k==1)
		return pos[a];
	return pos[b];
}

/*void dfs(int x,int y)
{
	int mid,min;
	if(x>=y)
		return ;
    
	min=RMQ(x,y,0);


	mid=RMQ(x,y,1);

	if(mid-min>ans)
		ans=mid-min;

	dfs(x,mid-1);
	dfs(mid+1,y);
	
}*/

void solve()
{
	int len,i,j;

	len=n-1;
   	while(len>=1)
	{
		 i=1;
         while(i+len<=n)
		 {
			 j=i+len;
			 if(RMQ(i,j,0)==i&&RMQ(i,j,1)==j)
			 {
				 printf("%d\n",len);
				 return ;
			 }
			 i++;
		 }
		 len--;
	}

	printf("-1\n");
}

int main()
{
	int i,x;

	for(i=0;i<=16;i++)
		p[i]=(1<<i);

	scanf("%d",&n);
//	{
	    for(i=1;i<=n;i++)
		{
		   scanf("%d",&x);
	   	   max[i][0]=min[i][0]=x;
		   pos[x]=i;
		}
	    init();
		solve();
		
	//	dfs(1,n);
	
//		printf("%d\n",ans);
//	}

	return 0;

}

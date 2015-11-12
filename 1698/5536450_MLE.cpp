#include<cstdio>
#include<cstdlib>
#include<cstring>
const int INF=1000000000;
int N,M;
int c[1600][1600],p[600][600];
int h[1600],vh[1600],augc,found,ans,total;
int m,n,T,D[600],W[600];

void aug( int x)
{
	int minh=n,augco=augc,i;
	if(x==n-1)
	{
		found=1;
		ans+=augc;
		return ;
	}
	for(i=0;i<n;++i)
		if(c[x][i]>0)
		{
			if(h[i]+1==h[x])
			{
				if(c[x][i]<augc)
					augc=c[x][i];
				aug(i);
				if(h[0]>=n)
					return ;
				if(found)
					break;
				augco=augc;
			}
			if(h[i]<minh)
				minh=h[i];
		}
    if(!found)
	{
		vh[h[x]]--;
		if(vh[h[x]]==0)
			h[0]=n;
		h[x]=minh+1;
		vh[h[x]]++;
	}
	else
	{
		c[x][i]-=augc;
		c[i][x]+=augc;
	}
}

void SAP()
{
	memset(h,0,sizeof(h));
	memset(vh,0,sizeof(vh));
	vh[0]=n; 
	ans=0;
	while(h[0]<n)
	{
       found=0;
	   augc=INF;
	   aug(0);
	}
	if(ans==total)
		printf("Yes\n");
	else
		printf("No\n");
}

int main()
{
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		 m=0;total=0;
	     scanf("%d",&N);
		 for(i=1;i<=N;++i)
		 {
			 for(j=1;j<=7;++j)
				 scanf("%d",&p[i][j%7]);
			 scanf("%d %d",&D[i],&W[i]);
			 total+=D[i];
			 W[i]*=7;
			 if(W[i]>=m)
				 m=W[i];
		 }
		 memset(c,0,sizeof(c));
		 n=m+N+2;
		 for(i=1;i<=m;++i)
		 {
			 c[0][i]=1;
			 for(j=1;j<=N;++j)   /////构图....
				 if(i<=W[j]&&p[j][i%7])
				 {
					 c[i][j+m]=1;
				 }
		 }
		 for(i=1;i<=N;++i)
			 c[i+m][n-1]=D[i];
		 SAP();
	}
	return 0;
}

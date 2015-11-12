#include<cstdio>
#include<cstdlib>
#include<cstring>
const int INF=1000000000;
int N,M,B;
int c[1100][1100],p[1100][30],v[30];
int h[1100],vh[1100],augc,found,total,ans;
int left,mid,right,beg,end,n;

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

int SAP()
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
    if(ans==N)
	     return 1;
	return 0;
}

void init()
{
	int i,j;
	memset(c,0,sizeof(c));
	for(i=1;i<=B;++i)
		c[i+N][N+B+1]=v[i];
	for(i=1;i<=N;++i)
		c[0][i]=1;
	for(i=1;i<=N;++i)
		for(j=1;j<=B;++j)
			if(p[i][j]>=beg&&p[i][j]<=end)
				c[i][j+N]=1;
}

int main()
{
	int i,j,x,flag;
    while(EOF!=scanf("%d %d",&N,&B))
	{
        for(i=1;i<=N;++i)
		{
			for(j=1;j<=B;++j)
			{
				scanf("%d",&x);
				p[i][x]=j;         ///rank.....
			}
		}
		for(i=1;i<=B;++i)
             scanf("%d",&v[i]);
		n=N+B+2;
		left=1;right=B;
		while(left<=right)
		{
			mid=(left+right)/2;
            flag=0;
			for(beg=1;beg+mid-1<=B;++beg)  ///mid为区间大小....
			{
			   end=beg+mid-1;
			   init();
			   if(SAP())
			   {
				   flag=1;
				   break;
			   }
			}
			if(flag)
				right=mid-1;
			else
				left=mid+1;
		}
        printf("%d\n",left);
	}
	return 0;
}
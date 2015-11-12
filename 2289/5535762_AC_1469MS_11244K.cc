#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
using namespace std;
const int INF=1000000000;
int N,M;
int c[1600][1600],p[600];
int h[1600],vh[1600],augc,found,ans;
char a[10000];
bool T[1100][500];
int beg,end,mid,total,n;

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
	int i,j,minv;
    memset(c,0,sizeof(c));
	for(i=1;i<=N;++i)
		c[0][i]=1;
	for(i=1;i<=N;++i)
		for(j=1;j<=M;++j)
			if(T[i][j])
				c[i][j+N]=1;
	for(i=1;i<=M;++i)
	{
        minv=mid;
		if(p[i]<minv)
			minv=p[i];
		c[i+N][N+M+1]=minv;
	}
}

int main()
{
	int i,x;
	char ch[20];
	while(EOF!=scanf("%d %d",&N,&M))
	{
		if(N==0&&M==0)
			break;
		memset(p,0,sizeof(p));
		memset(T,false,sizeof(T));   
		for(i=1;i<=N;++i)
		{
			scanf("%s ",ch);
			gets(a);
			stringstream s(a);    ////下标从0开始....
			while(s>>x)
			{
				x++;
				p[x]++;   /////顶点容量....
				T[i][x]=true;
			}
		}
		beg=1;end=N;
		n=N+M+2;
		while(beg<=end)
		{
			mid=(beg+end)/2;
			init();
			if(SAP())
				end=mid-1;
			else
				beg=mid+1;
		}
		printf("%d\n",beg);
	}
	return 0;
}

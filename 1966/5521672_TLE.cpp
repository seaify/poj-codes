#include<cstdio>
#include<cstring>
#include<vector>
const int INF=900000000;  //
using namespace std;
int N,M,c[600][600],f[600][600],sum;
int augc,ans,S,T,found,h[600],vh[600],q[90000000];
struct node
{
	int x,y;
};
node e[5100];
bool flag[600][600],tag[600];
vector < int > g[600];

void aug(int x)
{
   int i,minh=2*N,augco=augc;
   if(x==T)
   {
	   found=1;
	   ans+=augc;
	   return ;
   }
   for(i=0;i<2*N;++i)
	   if(c[x][i]>0)
	   {
		   if(h[i]+1==h[x])
		   {
			   if(c[x][i]<augc)
				   augc=c[x][i];
			   aug(i);
			   if(h[S]>=2*N)
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
			 h[S]=2*N;
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
	 vh[0]=2*N;   //从0开始计数...
	 ans=0;
	 while(h[S]<2*N)
	 {
		 found=0;
		 augc=INF;
		 aug(S);
	 }
}

int main()
{   
	int x,y,i,j,test;
	char ch;
	while(EOF!=scanf("%d %d",&N,&M))
	{
		memset(f,0,sizeof(f));
        memset(flag,true,sizeof(flag));  //从0开始...,可能刚开始就不连通...
		for(i=0;i<N;++i)   //
			f[i][i+N]=1;
		for(i=1;i<=M;++i)
		{
		    while(EOF!=scanf("%c",&ch)&&ch!='(');
			scanf("%d,%d",&x,&y);
			while(EOF!=scanf("%c",&ch)&&ch!=')');
			if(x==y)
				continue;
			if(flag[x][y])
			{
			    f[x+N][y]=INF;
				f[y+N][x]=INF;
				flag[x][y]=false;
				flag[y][x]=false;
			}
		}
		test=1;
		for(i=0;i<N;++i)         //判断是否为双向连通图...
			for(j=0;j<N;++j)
				if(i!=j&&flag[i][j])
				{
					test=0;
					break;
				}
        if(test)
		{
			printf("%d\n",N);
			continue;
		}
		sum=0;
		for(S=N;S<2*N;++S)
			for(T=0;T<N;++T)
		    if(S!=N+T&&flag[S-N][T])
			{
				memcpy(c,f,sizeof(f));
		        SAP();
				if(ans>sum)
					sum=ans;
			}
		printf("%d\n",sum);
	}
	return 0;
}
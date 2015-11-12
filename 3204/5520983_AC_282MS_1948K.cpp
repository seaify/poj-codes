#include<cstdio>
#include<cstring>
const int INF=1000000000;  //
int N,M,c[600][600],sum;
int augc,ans,found,h[600],vh[600],q[90000000];
struct node
{
	int x,y;
};
node e[5100];
bool flag[600][600],tag[600];

void aug(int x)
{
   int i,minh=N,augco=augc;
   if(x==N-1)
   {
	   found=1;
	   ans+=augc;
	   return ;
   }
   for(i=0;i<N;++i)
	   if(c[x][i]>0)
	   {
		   if(h[i]+1==h[x])
		   {
			   if(c[x][i]<augc)
				   augc=c[x][i];
			   aug(i);
			   if(h[0]>=N)
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
			 h[0]=N;
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
	 vh[0]=N;   //从0开始计数...
	 ans=0;
	 while(h[0]<N)
	 {
		 found=0;
		 augc=INF;
		 aug(0);
	 }
}

int bfs()
{
	int beg,end,i,j;
	memset(tag,false,sizeof(tag));
	tag[0]=true;
	beg=0;
	end=1;
	q[0]=0;
	for(i=beg;i<end;++i)
	{
		for(j=0;j<N;++j)
			if(!tag[j]&&c[q[i]][j]>0)
			{
				tag[j]=true;
				q[end++]=j;
				if(j==N-1)
					return 1;
			}
	}
    return 0;
}

int main()
{   
	int x,y,v,i;
	while(EOF!=scanf("%d %d",&N,&M))
	{
		memset(c,0,sizeof(c));
		if(N==0||M==0)
		{
			printf("0\n");
			continue;
		}
		for(i=1;i<=M;++i)
		{
			scanf("%d %d %d",&x,&y,&v); ///考虑重边....	
			e[i].x=x;
			e[i].y=y;
			if(x==y)
				continue;
			c[x][y]+=v;
		}
		SAP();
		memset(flag,false,sizeof(flag));
		sum=0;
		for(i=1;i<=M;++i)
		{
			x=e[i].x;
			y=e[i].y;
			if(x==y||c[x][y]>0)
				continue;
			if(flag[x][y])
			{
				++sum;
				continue;
			}
			c[x][y]=1;
			if(bfs())
			{
				flag[x][y]=true;
				++sum;
			}
			c[x][y]=0;
		}
		printf("%d\n",sum);
	}
	return 0;
}
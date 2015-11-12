#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
const int INF=1000000000;
int i,j,n,m,last[22000],d[22000],f[22000],set[22000],tot,cnt,t;
int left,right,mid,T,A,B,ADD;
bool flag[22000],tag[1100][1100];
vector< int > a[22000],b[22000],c[22000];

struct node
{
	int x,y;
};
node e[10000],ch[10],S[10000],D[10000];

void DFS_visit(int i)
{
  flag[i]=false;
  ++t;
  d[i]=t;
  for( int k=0;k!=a[i].size();++k)
     if(flag[a[i][k]])
         DFS_visit(a[i][k]);
  ++t;
  f[i]=t;
  last[++tot]=i;
}

void dfs(int i)
{
  flag[i]=false;
   for( int k=0;k!=b[i].size();++k)
     if(flag[b[i][k]])
         dfs(b[i][k]);
  set[i]=tot;
}

int opp(int x)
{
	if(x<=n)
		return x+n;
	return x-n;
}

int check()
{
  int t1,t2,i,j;
  for(i=1;i<=2*n;++i)
	  a[i].clear(),b[i].clear();
  //memset(tag,true,sizeof(tag));
  
  for(i=1;i<=A;++i)    ////不相同时
  {
      t1=D[i].x;
	  t2=D[i].y;

	  a[t1].push_back(t2+n);  ///t1 和 t2 
	  b[t2+n].push_back(t1);

	  a[t2].push_back(t1+n);
	  b[t1+n].push_back(t2);  //t1+n 和 t2+n

	  a[t1+n].push_back(t2);
	  b[t2].push_back(t1+n);

	  a[t2+n].push_back(t1);
	  b[t1].push_back(t2+n);

  }

  for(i=1;i<=B;++i)   ///相同.....
  {
      t1=S[i].x;
	  t2=S[i].y;

	  a[t1].push_back(t2);////t1 和 t2+n
	  b[t2].push_back(t1);
  
	  a[t2+n].push_back(t1+n);
	  b[t1+n].push_back(t2+n); //t2 和 t1+n

	  a[t2].push_back(t1);
	  b[t1].push_back(t2);

	  a[t1+n].push_back(t2+n);
	  b[t2+n].push_back(t1+n);
  }
  for(i=1;i<n;++i)
     for(j=i+1;j<=n;++j)
	 {
		 if(d[i]+d[j]>mid)
		 {
			 a[i].push_back(j+n);
			 b[j+n].push_back(i);

			 a[j].push_back(i+n);
			 b[i+n].push_back(j);
		 }
		 if(d[i]+d[j+n]+ADD>mid)
		 {
			 a[i].push_back(j);
			 b[j].push_back(i);

			 a[j+n].push_back(i+n);
			 b[i+n].push_back(j+n);

		 }
		 if(d[i+n]+d[j]+ADD>mid)
		 {
			 a[i+n].push_back(j+n);
			 b[j+n].push_back(i+n);

			 a[j].push_back(i);
			 b[i].push_back(j);
		 }
		 if(d[i+n]+d[j+n]>mid)
		 {
			 a[i+n].push_back(j);
			 b[j].push_back(i+n);

			 a[j+n].push_back(i);
			 b[i].push_back(j+n);
		 }
	 }

  memset(flag,true,(2*n+1)*sizeof(flag[1]));
  t=0;tot=0;
  for(i=1;i<=2*n;++i)
    if(flag[i])
        DFS_visit(i);
  memset(flag,true,(2*n+1)*sizeof(flag[1]));
  tot=0;
  for(i=2*n;i>=1;--i)
     if(flag[last[i]])
     {
       ++tot;
       dfs(last[i]);
     }
  for(i=1;i<=n;++i)
	  if(set[i]==set[i+n])
		  return 0;
  return 1;
}
int main()
{
	int i,answer,v;
    while(EOF!=scanf("%d %d %d",&n,&A,&B))
	{
		for(i=1;i<=2;++i)
			scanf("%d %d",&ch[i].x,&ch[i].y);
		for(i=1;i<=n;++i)
			scanf("%d %d",&e[i].x,&e[i].y);
		for(i=1;i<=A;++i)
			scanf("%d %d",&D[i].x,&D[i].y);
		for(i=1;i<=B;++i)
			scanf("%d %d",&S[i].x,&S[i].y);
		ADD=abs(ch[1].x-ch[2].x)+abs(ch[1].y-ch[2].y);
		//printf("%d\n",ADD);
		for(i=1;i<=n;++i)
		{
           d[i]=abs(e[i].x-ch[1].x)+abs(e[i].y-ch[1].y);
		   d[i+n]=abs(e[i].x-ch[2].x)+abs(e[i].y-ch[2].y);
		  // printf("%d %d\n",d[i],d[i+n]);
		}
		left=INF;right=0;
		for(i=1;i<2*n;++i)
			for(j=i+1;j<=2*n;++j)
			{
				if(j-i==n)
					continue;
				if(i<=n&&j<=n)
					v=d[i]+d[j];
				else if(i>n&&j>n)
					v=d[i]+d[j];
				else
					v=d[i]+d[j]+ADD;
				if(v>right)
					right=v;
				if(v<left)
					left=v;
			}
		answer=0;
		//printf("%d %d\n",left,right);
		while(left<=right)
		{
			mid=(left+right)/2;
			if(check())
			{
				answer=1;
				right=mid-1;
			}
			else
				left=mid+1;
		}
		if(answer)
		     printf("%d\n",left);
		else
			 printf("-1\n");
	}
    return 0;
}



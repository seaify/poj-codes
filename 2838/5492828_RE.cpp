#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int INF=1000000000;
int N,Q,test,x,y,x1,y1,ans,D[1100][1100];
bool flag[1100];
struct node
{
	char ch;
	int y,v;
};
node f,queue[21000];
vector < node >  e[1100];
vector < int > T[1100][1100];
typedef vector < node > ::iterator INT;
void dfs(int x)
{
	int i;
	flag[x]=false;
	if(y==x)
	{
	    test=1;
		return ;
	}
	for(i=0;i<e[x].size();++i)
   	  if(!test&&flag[e[x][i].y])
		{
			dfs(e[x][i].y);
			if(test)
			{  
				if(e[x][i].v<ans)
				{
				   ans=e[x][i].v; 
				   x1=x;
				   y1=e[x][i].y;
				}
				return ;
			}
		}
   return ;
}

void add(int x,int y ,int v)
{
       f.y=y;f.v=v;
	   e[x].push_back(f);
	   f.y=x;
	   e[y].push_back(f);
}

void del(int x,int y,int v)
{
      INT it;
	  for(it=e[x].begin();it!=e[x].end();++it)
	  {
          f=*it;
		  if(f.y==y&&f.v==v)
		  {
			 it=e[x].erase(it);
			 break;
		  }
	  }
	  for(it=e[y].begin();it!=e[x].end();++it)
	  {
		  f=*it;
		  if(f.y==x&&f.v==v)
		  {
			  it=e[y].erase(it);
			  break;
		  }
	  }
	  return ;
}	  


int main()
{
	int i,j,t1,t2;
	char ch;
	while(EOF!=scanf("%d %d",&N,&Q))   ////边必须包含权值。。。
	{
		 for(i=1;i<=N;++i)
		 {
            e[i].clear();
			for(j=1;j<=N;++j)
				T[i][j].clear();
		 }
		 memset(D,-1,sizeof(D));
		 for(i=1;i<=Q;++i)
		 {
			 scanf("%c %d %d",&queue[i].ch,&queue[i].y,&queue[i].v);
			 if(queue[i].ch=='D')
			 {
				 t1=queue[i].y;
				 t2=queue[i].v;
			     T[t1][t2].push_back(i);
				 T[t2][t1].push_back(i);
			 }
		 }
         for(i=1;i<=Q;++i)
		 {
			 ch=queue[i].ch;
			 x=queue[i].y;
			 y=queue[i].v;
			 if(ch=='I')
			 {
				 memset(flag,true,sizeof(flag));
				 test=0;ans=INF;
				 dfs(x);
				 if(test)
				 {
                    if(ans>=T[x][y][D[x][y]+1])
						break;
					else if(ans<T[x][y][D[x][y]+1])
					{
						++D[x][y];
						++D[y][x];
						add(x,y,T[x][y][D[x][y]]);
						del(x1,y1,ans);
						--D[x1][y1];
						--D[y1][x1];
					}
				 }
				 else
				 {
					 ++D[x][y];
					 ++D[y][x];
					 add(x,y,T[x][y][D[x][y]]);
				 }
			 }
			 else if(ch=='D')
			 {
				 del(x,y,T[x][y][D[x][y]]);
				 --D[x][y];
				 --D[y][x];
			 }
			 else
			 {
				 memset(flag,true,sizeof(flag));
				 test=0;
				 dfs(x);
				 if(test)
					 printf("Y\n");
				 else
					 printf("N\n");
			 }
		 }
	}
	return 0;
}	
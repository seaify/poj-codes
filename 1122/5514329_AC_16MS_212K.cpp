#include<cstdio>
#include<cstring>
#include<sstream>
using namespace std;
const int INF=100000000;
int N,S,tot,top,d[100],path[100],map[100][100],v[100],ans[100];
bool flag[100],tag[100];
char a[1000];

void dijkstra()
{
   int i,j,x,minv;
   memset(path,-1,sizeof(path));
   memset(flag,true,sizeof(flag));
   for(i=1;i<=N;++i)
	   d[i]=INF;
   d[S]=0;
   for(i=1;i<=N;++i)
   {
	   minv=INF;x=-1;
       for(j=1;j<=N;++j)
		   if(flag[j]&&d[j]<minv)
			   x=j,minv=d[j];
	   if(x==-1)
		   return ;
	   flag[x]=false;
	   if(tag[x])
		   ans[++tot]=x;
	   for(j=1;j<=N;++j)
		   if(flag[j]&&d[x]+map[x][j]<d[j])
			   d[j]=d[x]+map[x][j],path[j]=x;
   }
}

void output(int x)
{
	if(x==S)
        printf("%d\n",x);
	else
		printf("%d\t",x); 
	if(path[x]!=-1)
        output(path[x]);
}

int main()
{
	int i,j,x;
	while(EOF!=scanf("%d",&N))
	{
		for(i=1;i<=N;++i)
			for(j=1;j<=N;++j)
			{
				scanf("%d",&map[j][i]);
				if(map[j][i]==-1)
					map[j][i]=INF;
			}
		while(getchar()!='\n');
		gets(a);  ///可能需要加getchar()
		stringstream s(a);
		top=0;
		tot=0;
		memset(tag,false,sizeof(false));
		while(s>>x)
		{
          v[++top]=x;
		  if(top!=1)
		  {
			  if(x!=v[1])
			      tag[x]=true;
			  else
				  ans[++tot]=x;
		  }
		}
		S=v[1];
		dijkstra();
		printf("Org\tDest\tTime\tPath\n");
		for(i=1;i<=tot;++i)
		{
			printf("%d\t%d\t%d\t",ans[i],S,d[ans[i]]);
			output(ans[i]);
		}
	}
	return 0;
}
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

const int INF=400;

vector < int > v[151];

int N,K,root,result;
int f[151][151],g[151];

void dfs(int x)
{
    int i,j,c,y;
    for(c=1;c<=K;c++)
		f[x][c]=INF;
    f[x][1]=0;
    for(c=0;c<v[x].size();c++)
    {
		y=v[x][c];
        dfs(y);
		for(i=1;i<=K;i++)
			g[i]=f[x][i]+1<INF?f[x][i]+1:INF;
        for(i=1;i<=K;i++)
			for(j=1;j+i<=K;j++)
			{
				if(f[x][i]+f[y][j]<g[j+i])
					g[j+i]=f[x][i]+f[y][j];
			}
			for(i=1;i<=K;i++)
				f[x][i]=g[i];
    }

    if(x==root)
	{
		if(f[x][K]<result)
		    result=f[x][K];
	}
	else if(f[x][K]+1<result)
		result=f[x][K]+1;
}

int main()
{  
    int i,x,y;
    while(EOF!=scanf("%d %d",&N,&K))
    {
                                              
		root=(N*(N+1))/2;
		for(i=1;i<N;i++)
		{
            scanf("%d %d",&x,&y);
			root-=y;
			v[x].push_back(y);
		}
	
		result=INF;
		dfs(root);
		printf("%d\n",result);	           
    }
    return 0;
}


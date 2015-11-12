#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int N=26;
int map[1100][1100],in[1100],out[1100],mark[1100],pos[1000],c[1000][1000];
int i,j,T,M,x,y,flag,start,cnt,len,minx,total,last[1000];
vector < string > edge[30][30];
vector < string > e[30];
char a[30];
void dfs(int cur)
{
   int i;
   mark[cur]=1;
   for(i=1;i<=total;++i)
   {
	  j=last[i];
      if(map[cur][j]&&mark[j]==0)
		  dfs(j);
   }
}
void DFS(int cur)
{
	int i,j,k;
	for(i=0;i<e[cur].size();++i)//合理地选择方式。。。,存储的都是下标。。。
	{
		k=e[cur][i].size();
		j=e[cur][i][k-1]-'a'+1;
		if(map[cur][j]>0)
		{
			--map[cur][j];
			DFS(j);
		}
	}
	out[++cnt]=cur;//加入的是实际。。。
}
void output()
{
	int i,j,k,x,y;
	for(i=1;i<=total;++i)
		for(j=1;j<=total;++j)
		{
			x=last[i],y=last[j];
			sort(edge[x][y].begin(),edge[x][y].end());
		}
   memset(c,0,sizeof(c));
 //  for(i=cnt;i>=1;--i)
//			printf("%d ",out[i]);
  // printf("\n");
  // printf("%d\n",cnt);
//   printf("%d %d %d %d\n",edge[1][1].size(),edge[1][2].size(),edge[2][1].size(),edge[2][2].size());
   memset(c,0,sizeof(c));
   for(i=cnt;i>=3;--i)
   {
        k=c[out[i]][out[i-1]];
	//	printf("%d %d\n",out[i],out[i-1]);
	//	printf("%d %d\n",i,k);
			
        cout<<edge[out[i]][out[i-1]][k]<<".";
        ++c[out[i]][out[i-1]];
   }
   k=c[out[2]][out[1]];
   
   cout<<edge[out[2]][out[1]][k]<<endl;
   
}
int main()
{
	int k;
    scanf("%d",&T);
    while(T--)
	{
		scanf("%d",&M);
		memset(map,0,sizeof(map));
		memset(in,0,sizeof(in));
		memset(mark,0,sizeof(mark));
		memset(pos,false,sizeof(pos));
		for(i=1;i<=N;++i)
		{
		   e[i].clear();
           for(j=1;j<=N;++j)
               edge[i][j].clear();
		}
		start=30;
		while(M--)
		{
		   scanf("%s",a);
           k=strlen(a);
           i=a[0]-'a'+1;//下标从0出发。。。。 
           j=a[k-1]-'a'+1;
           ++in[j],--in[i];//入度。。。。 
           ++map[i][j];
           edge[i][j].push_back(a);
		   e[i].push_back(a);
           pos[i]=true;pos[j]=true;
		    if(i<start)
				start=i;
		}  
		total=0;
		for(i=1;i<=26;++i)
			if(pos[i])
				last[++total]=i;
		dfs(start);//判断连通性。。
		flag=1;x=0;y=0;
		for(i=1;i<=total;++i)
		{
			j=last[i];
			if(!mark[j])
			{
				flag=0;
				break;
			}
		    else if(in[j]==-1)
			{
				++x;
				start=j;
			}
			else if(in[j]==1)
				++y;
		}
	    if(!(x==y&&x<=1))
			flag=0;
	//	printf("%d %d\n",x,y);
		if(flag==0)
		{
			printf("***\n");
			continue;
		}
		for(i=1;i<=total;++i)
		{
			j=last[i];
            sort(e[j].begin(),e[j].end());
		}
		cnt=0;
		DFS(start);
		output();
	}
   return 0;
}



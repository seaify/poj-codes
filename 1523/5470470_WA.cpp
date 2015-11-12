#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector < int > e[1100],q;
int n,m,tot,lab[1100],son[1100],d[1100],pos[1100],total;
bool flag[1100][1100],tag[1100],answer[1100];

int minx(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

void dfs(int cur,int p)
{
	int i,y;
    lab[cur]=son[cur]=++tot;
	for(i=0;i<e[cur].size();++i)
	{
		y=e[cur][i];
		if(lab[y]==-1)   ////树边
		{
			dfs(y,cur);
			son[cur]=minx(son[cur],son[y]);
			if(!tag[cur])
				continue;
			if(cur==1)
			{
				if(son[y]>lab[cur])
				{
					tag[1]=false;
					++total;
				}
			}
			else if(son[y]>=lab[cur])
			{
				  tag[cur]=false;
				  ++total;
			}
		}
		else if(y!=p)
			son[cur]=minx(son[cur],lab[y]);
	}
}

int main()
{
	int i,j,x,y,t1,t2,n,T=0;
	while(EOF!=scanf("%d",&x))
	{
		if(x==0)
			break;	
		n=0;
		memset(flag,true,sizeof(flag));
	    memset(d,0,sizeof(d));
		memset(pos,0,sizeof(pos));
		for(i=1;i<=1100;++i)
			e[i].clear();  
		if(!d[x])
		{
			d[x]=++n;
			pos[n]=x;
		}
		while(1)            ////利用d[y]作实际索引下标.....
		{
		   scanf("%d",&y);
		   if(y==0)
			   break;
		   if(!d[y])
		   {
			   d[y]=++n;
			   pos[n]=y;
		   }
		   t1=d[x];t2=d[y];
		   if(flag[t1][t2])
			{
				e[t1].push_back(t2);
				e[t2].push_back(t1);
				flag[t1][t2]=flag[t2][t1]=false;
			}
		   scanf("%d",&x);
		   if(x==0)
			   break;
		   if(!d[x])
		   {
			   d[x]=++n;
			   pos[n]=x;
		   }
		}
		tot=0;total=0;
		memset(lab,-1,sizeof(lab));
		memset(son,-1,sizeof(son));
	    memset(tag,true,sizeof(tag));
		dfs(1,-1);
		printf("Network #%d\n",++T);
		if(total==0)
			printf("  No SPF nodes\n");
		else
		{
	          /*	for(i=1;i<=n;++i)
			              printf("%d %d\n",lab[i],son[i]);*/
	        for(i=1;i<=n;++i)
				if(!tag[i])
				{
					memset(answer,false,sizeof(answer));
				//	answer[son[i]]=true;
					tot=0;
                    for(j=1;j<=n;++j)
						if(j!=i&&!answer[son[j]])
						{
                           answer[son[j]]=true;
						   ++tot;
						}
					printf("SPF node %d leaves %d subnets\n",pos[i],tot);

				}
		}
	}
	return 0;
}


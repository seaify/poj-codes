#include<cstdio>
#include<queue>
using namespace std;
int T,L,op,C,S,ans[100],w[30];
int flag[2000000];
struct tree
{
    int state;
	int pay;
	friend bool operator < ( tree a ,tree b)
	{
		if(a.pay>b.pay)
			return 1;
		return 0;
	}
};

tree D,E;
priority_queue < tree ,vector <tree> > q;

struct node
{
	char a[21];
	int cost;
};

node P[40];

int up(int state ,int x)
{
	 int j,cnt,k,v;
	 cnt=0;
	 k=1;
     for(j=L-1;j>=0;j--)
	 {
		 v=0;
		 if(state&k)
			 v=1;
		 if(P[x].a[j]=='N')
			 cnt+=v*k;
		 else if(P[x].a[j]=='F')
			 cnt+=k-v*k;
		 else if(P[x].a[j]=='S')
			 cnt+=k;
		 k*=2;
	 }
	 return cnt;
}

int bfs()
{
	 int i;
     while(!q.empty())
		 q.pop();
	 D.state=S;
	 D.pay=0;
	 q.push(D);
	                     ////如果不手写堆的话，不能用标记数组判重...
	 memset(flag,-1,sizeof(flag));
	 flag[D.state]=0;

	 while(!q.empty())
	 {
		 D=q.top();
		 q.pop();
		 if(D.state==T)
			 return D.pay;
		 if(D.pay>flag[D.state])
			 continue;
		 for(i=1;i<=op;++i)
		 {
			 E.state=up(D.state,i);
			 E.pay=D.pay+P[i].cost;
			 if(flag[E.state]!=-1&&E.pay>flag[E.state])
				 continue;
			 flag[E.state]=E.pay;
			 q.push(E);
		 }
	 }
	 return -1;
}

int main()
{
	int i,j,k,Case;
	scanf("%d",&Case);
	while(Case--)
	{
		scanf("%d %d %d",&L,&op,&C);
		for(i=1;i<=op;++i)
			scanf("%s %d",P[i].a,&P[i].cost);
		for(j=1;j<=C;j++)
		{
			scanf("%s %s",P[35].a,P[36].a);  //先求出状态..
			S=0; k=1;
			for(i=L-1;i>=0;i--)
			{
				S+=(P[35].a[i]-'0')*k;
				k*=2;
			}
			T=0; k=1;
			for(i=L-1;i>=0;i--)
			{
				T+=(P[36].a[i]-'0')*k;
				k*=2;
			}
		    ans[j]=bfs();
		}
		for(j=1;j<C;++j)
			if(ans[j]!=-1)
				printf("%d ",ans[j]);
			else
				printf("NP ");
		if(ans[C]!=-1)
			printf("%d\n",ans[C]);
		else
			printf("NP\n");
	}
	return 0;
}
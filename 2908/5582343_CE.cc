#include<cstdio>
#include<queue>
using namespace std;
int T,L,op,C,S,ans[100],w[30];
int flag[1600000];
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
	int f,s,t;
	int cost;
};

node P[40];


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
			 E.state=((D.state^P[i].f)|P[i].s)&P[i].t;
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
	int i,j,Case;
	scanf("%d",&Case);
	while(Case--)
	{
		scanf("%d %d %d",&L,&op,&C);
		for(i=1;i<=op;++i)
		{
			scanf("%s %d",P[i].a,&P[i].cost);
			P[i].f=0;
			P[i].s=0;
			P[i].t=0x7ffffff;
			for(j=0;j<L;j++)
			{
				if(P[i].a[j]=='F')
					P[i].f+=(1<<(L-j-1));
				else if(P[i].a[j]=='S')
					P[i].s+=(1<<(L-j-1));
				else if(P[i].a[j]=='C')
					P[i].t-=(1<<(L-j-1));
			}
		}
		for(j=1;j<=C;j++)
		{
			scanf("%s %s",P[35].a,P[36].a);  //先求出状态..
			S=0; 
			for(i=0;i<L;i++)
				S+=(P[35].a[i]-'0')*(1<<(L-i-1));
			T=0; 
			for(i=0;i<L;i++)
				T+=(P[36].a[i]-'0')*(1<<(L-i-1));
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
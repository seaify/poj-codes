#include<cstdio>
#include<cstring>
const __int64 INF=100000000000000;
int n,m;
int first[5100],p[5100],h[5100],vh[5100];
bool flag[5100];
int tot,found,cnt;
__int64 total,augc;

struct node
{
	int x,y,next;
	__int64 f,c;
};
node e[800000];

void add(int x,int y,__int64 c)
{
    e[++tot].x=x;
	e[tot].y=y;
	e[tot].f=0;
	e[tot].c=c;
	e[tot].next=first[x];
	first[x]=tot;
}

void aug(int x)
{
	int minh=n,y,tmp;
	__int64 augco=augc;
	if(x==n-1)
	{
		found=1;
		total-=augc;   ///
		return ;
	}
	tmp=first[x];
    for( ;tmp!=-1;tmp=e[tmp].next)
	{
		if(e[tmp].c>e[tmp].f)
		{
            y=e[tmp].y;
			if(h[y]+1==h[x])
			{
				if(e[tmp].c-e[tmp].f<augc)
					augc=e[tmp].c-e[tmp].f;
				aug(y);
				if(h[0]>=n)
					return ;
				if(found)
					break;
				augc=augco;
			}
			if(h[y]<minh)
				minh=h[y];
		}
	}
	if(!found)
	{
		vh[h[x]]--;
		if(vh[h[x]]==0)
			h[0]=n;
		h[x]=minh+1;
	    vh[h[x]]++;
	}
	else
	{
		e[tmp].f+=augc;
		e[tmp^1].f-=augc;
	}
}

void SAP()
{
    memset(h,0,sizeof(h));
	memset(vh,0,sizeof(vh));
	vh[0]=n;
	while(h[0]<n)
	{
		found=0;
		augc=INF;
		aug(0);
	}
}

void dfs(int x)
{
	 int tmp,y;
     flag[x]=true;
	 cnt++;
	 tmp=first[x];
	 while(tmp!=-1)
	 {
		 y=e[tmp].y;
		 if(!flag[y]&&e[tmp].c>e[tmp].f)
			 dfs(y);
		 tmp=e[tmp].next;
	 }
}

int main()
{
	int i,x,y;
	while(EOF!=scanf("%d %d",&n,&m))
	{
		for(i=0;i<=n+1;i++)
			first[i]=-1;
		total=0;
		tot=-1;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&p[i]);
			if(p[i]>0)
			{
                add(0,i,p[i]);
				add(i,0,0);
				total+=p[i];
			}
			else
			{
				add(i,n+1,-p[i]);		
				add(n+1,i,0);
			}
		}
		while(m--)
		{
			scanf("%d %d",&x,&y);
			add(x,y,INF);
			add(y,x,0);
		}
		n=n+2;
		SAP();
		memset(flag,false,sizeof(flag));
		cnt=-1;
		dfs(0);
		printf("%d %I64d\n",cnt,total);
	}
	return 0;
}
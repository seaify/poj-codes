#include<cstdio>
#include<cstring>
const int INF=1000000000;
int n,m;
int first[51000],p[51000],h[51000],vh[51000];
bool map[300][300];
int tot,found,cnt;
int total,augc,ans,T;

struct node
{
	int x,y,next;
	int f,c;
};
node e[100000];

void add(int x,int y,int c)
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
	int augco=augc;
	if(x==n-1)
	{
		found=1;
		ans+=augc;   
		return ;
	}
    for(tmp=first[x] ;tmp!=-1;tmp=e[tmp].next)  ////
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
	int i;
    memset(h,0,sizeof(h));
	memset(vh,0,sizeof(vh));
	vh[0]=n;
	ans=0;
	while(h[0]<n)
	{
		found=0;
		augc=INF;
		aug(0);
	}
	printf("Case %d: %d\n",++T,n-ans-2);
}

void insert(int x,int y,int c)
{
	add(x,y,c);
	add(y,x,0);
}

int main()
{
	int i,j,x,y,c;
	T=0;
	while(EOF!=scanf("%d %d %d",&n,&total,&m))
	{
		if(n==0&&total==0&&m==0)
		     break;
		for(i=0;i<=n+total+1;i++)
			first[i]=-1;
		tot=-1;
		memset(map,true,sizeof(map));
		for(i=1;i<=n;i++)
		    insert(0,i,1);
		for(i=1;i<=total;i++)
		    insert(i+n,n+total+1,1);
		while(m--)
		{
			scanf("%d %d",&x,&y);
			map[x][y]=false;
		}
		for(i=1;i<=n;i++)
		   for(j=1;j<=total;j++)
		       if(map[i][j])
		           insert(i,j+n,1);
		n=n+total+2;
		SAP();
	}
	return 0;
}


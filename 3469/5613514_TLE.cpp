#include<cstdio>
#include<cstring>
const int INF=1000000000;
int n,m;
int T[51000],first[51000],p[51000],h[51000],vh[51000];
bool flag[51000];
int tot,found,cnt;
int total,augc,ans;

struct node
{
	int x,y,next;
	int f,c;
};
node e[600000];

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
		ans+=augc;   ///
		return ;
	}
    for(T[x] ;T[x]!=-1;T[x]=e[T[x]].next)  ////当前弧优化..... 
	{
		tmp=T[x];
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
	T[x]=first[x];
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
	//	e[tmp^1].f-=augc;
	}
}

void SAP()
{
	int i;
    memset(h,0,sizeof(h));
	memset(vh,0,sizeof(vh));
	vh[0]=n;
	ans=0;
	for(i=0;i<n;i++)
	     T[i]=first[i];
	while(h[0]<n)
	{
		found=0;
		augc=INF;
		aug(0);
	}
	printf("%d\n",ans);
}



int main()
{
	int i,x,y,c;
	while(EOF!=scanf("%d %d",&n,&m))
	{
		for(i=0;i<=n+1;i++)
			first[i]=-1;
		tot=-1;
		for(i=1;i<=n;++i)
		{
		    scanf("%d %d",&x,&y);
			add(0,i,x);
		//	add(i,0,0);
			add(i,n+1,y);
		//	add(n+1,i,0); 
		}
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&c);
			add(x,y,c);
			add(y,x,c);
		}
		n=n+2;
		SAP();
	}
	return 0;
}

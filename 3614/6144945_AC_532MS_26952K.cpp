#include<cstdio>
#include<cstring>
const int INF=1000000000;
int n,m;
int first[5100],h[5100],vh[5100];
int tot,found,cnt;
int total,augc,ans,T;
int x[5100],y[5100],p[5100];

struct node
{
	int x,y,next;
	int f,c;
};
node e[9000000];

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
	printf("%d\n",ans);
}

void insert(int x,int y,int c)
{
	add(x,y,c);
	add(y,x,0);
}

int main()
{
	int i,j,c;

    while(EOF!=scanf("%d %d",&n,&total))
	{
	
		for(i=0;i<=n+total+1;i++)
			first[i]=-1;
		tot=-1;	
		for(i=1;i<=n;i++)
		{
            scanf("%d %d",&x[i],&y[i]);
		    insert(0,i,1);
        }
        
		for(i=1;i<=total;i++)
		{
            scanf("%d %d",&p[i],&c);
		    insert(i+n,n+total+1,c);
        }

		for(i=1;i<=n;i++)
		   for(j=1;j<=total;j++)
		       if(x[i]<=p[j]&&p[j]<=y[i])
		           insert(i,j+n,1);
		n=n+total+2;
		SAP();
	}
	return 0;
}

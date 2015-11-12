#include<stdio.h>

const int INF=10000000;
#define min(a,b) a<b?a:b;

int n,M,v,tot;
int a[100000],T[1000010];

struct node
{
	int a,b,ls,rs,lmax;
};
node tree[3*1000010];

int init(int a,int b)
{
	int cur=tot,mid;
	tree[cur].a=a;
	tree[cur].b=b;
	tree[cur].lmax=INF; //不存在..
	if(a==b)
	{
		tree[cur].ls=tree[cur].rs=-1;
		return cur;
	}
	mid=(a+b)/2;
	++tot;
	tree[cur].ls=init(a,mid);
	++tot;
	tree[cur].rs=init(mid+1,b);
	return cur;
}

void update(int root,int v)
{
	int ls,rs,mid;
    if(tree[root].a==tree[root].b)   //被插入时肯定不存在..
	{
		tree[root].lmax=v;
		return ;
	}

	ls=tree[root].ls;
	rs=tree[root].rs;
	mid=(tree[root].a+tree[root].b)/2;
	if(v<=mid)
		update(ls,v);
	else
		update(rs,v);
    
	tree[root].lmax=min(tree[ls].lmax,tree[rs].lmax);
}

int dfs(int root,int x,int y)
{
	int ls,rs,mid;


    if(x<=tree[root].a&&tree[root].b<=y||tree[root].lmax==INF)
	         return tree[root].lmax;
	
	ls=tree[root].ls;
	rs=tree[root].rs;
	mid=(tree[root].a+tree[root].b)/2;

	if(y<=mid)
		 return dfs(ls,x,y);
	else if(x>mid)
		 return dfs(rs,x,y);
    else
		 return min(dfs(ls,x,y),dfs(rs,x,y));
}

int main()
{
	char ch[10];
	int i,c,t,X,TT=0,left,right,flag,result,ans;

    tot=1;
	init(0,500000);

	while(EOF!=scanf("%d",&M)&&M)
	{
		
		for(i=0;i<=1600000;i++)
			tree[i].lmax=INF;
		n=0;
		
		printf("Case %d:\n",++TT);

		for(t=1;t<=M;t++)
		{
             scanf("%s %d",ch,&X);
			 if(ch[0]=='A')
			 {
				 if(n==0)
				 {
					 printf("-1\n");
					 continue;
				 }
				 result=100000000;
				 ans=0;
				
				 if(X<=5000)
				 {
					 for(i=n;i>=1;i--)
						 if((a[i]%X)<result)
						 {
							 result=a[i]%X;
							 ans=i;
							 if(result==0)
								 break;
						 }
					 printf("%d\n",ans);
				 }
				 else
				 {
                     left=0;
					 right=X-1;
					 
				     while(left<=500000)
					 {
						 if(right>=500000);
                             right=500000;
                         v=dfs(1,left,right);
						 if(v!=INF)
						 {
							 c=v%X;
							 if(c<result||(c==result&&T[v]>ans))
							 {
						        ans=T[v];
							    result=v%X;
							 }
						 }
                         left+=X;
						 right+=X;
					 }
					 printf("%d\n",ans);
				 }

			 }
			 else
			 {
				 scanf("%d",&X);
				 a[++n]=X;
				 update(1,X);
				 T[X]=n;
			 }
		}
		printf("\n");
	}
	return 0;
}
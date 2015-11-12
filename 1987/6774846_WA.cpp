#include<stdio.h>
#include<algorithm>
using namespace std;

int n,N,K,pp,tot,fuck,result,len;
int hh[100000],flag[100000],size[100000],first[100000],ans[100000][3];

struct node
{
	int x,y,next,value;
};
node e[200000];

void add(int x,int y,int value)
{
	++tot;
	e[tot].x=x;
	e[tot].y=y;
	e[tot].value=value;
	e[tot].next=first[x];
	first[x]=tot;
}

void ok(int x,int dis,int p)
{
	int y,big=0,tmp;
	N++;
	hh[N]=dis;
	size[x]=1;
	tmp=first[x];
	while(tmp!=-1)
	{
		y=e[tmp].y;
		if(flag[y]==0||y==p)
		{
			tmp=e[tmp].next;
			continue;
		}
        ok(y,dis+e[tmp].value,x);
		size[x]+=size[y];
		if(size[y]>big)
			big=size[y];

		tmp=e[tmp].next;
	}
	if(len-size[x]>big)
		big=len-size[x];
    if(big<fuck)
	{
		fuck=big;
		pp=x;
	}
}


int dfs(int x,int total,int dis)
{
	int i,y,dx,tmp,son,root;

	fuck=n;
	N=0;
	len=total;
	ok(x,0,-1);
	root=pp;
	N=0;
	ok(root,0,-1);

	sort(hh+1,hh+total+1);        ////  同样可以处理叶子节点..,但可能不只需要标记根节点..
	ans[root][1]=ans[root][2]=0;
	for(i=total;i>1;i--)	
	{
		  dx=upper_bound(hh+1,hh+i,K-hh[i])-hh;
          ans[root][1]+=dx-1;
		  dx=upper_bound(hh+1,hh+i,K-hh[i]-2*dis)-hh;
		  ans[root][2]+=dx-1;
	}
	ans[root][0]=ans[root][1];

	tmp=first[root];
	flag[root]=0;

	while(tmp!=-1)
	{
		y=e[tmp].y;
		if(flag[y]==0)
		{
            tmp=e[tmp].next;
			continue;
		}
		son=dfs(y,size[y],e[tmp].value);          //子树之间互不相交，标记不影响..

		ans[root][0]+=ans[son][0]-ans[son][2];

		tmp=e[tmp].next;
	}
	return root;
}

int main()
{
	int i,x,y,root,value;
    char ch[10];
	while(EOF!=scanf("%d %d",&n,&x))
	{
   if(n==0&&K==0)
break;
		for(i=1;i<=n;i++)
			first[i]=-1,flag[i]=1;
		tot=0;
        for(i=1;i<n;i++)
		{
			scanf("%d %d %d %s",&x,&y,&value,ch);
			add(x,y,value);
			add(y,x,value);
		}
		scanf("%d",&K);

		root=dfs(1,n,0);

		printf("%d\n",ans[root][0]);
	}
	return 0;
}
#include<stdio.h>

const int INF=2000000000;
#define min(a,b) a<b?a:b;

int N,M,K,tot;
int d[1100],first[1100],flag[1100],q[9000000];

struct node
{
	int x,y,v,next;
};
node e[30000];

void add(int x,int y,int v)
{
	++tot;
	e[tot].x=x;
	e[tot].y=y;
	e[tot].v=v;
	e[tot].next=first[x];
	first[x]=tot;
}


int SPFA(int mid)
{
	int i,j,x,y,v,beg,end,tmp;

	for(i=1;i<=N;i++)
		d[i]=INF,flag[i]=0;

	beg=1;
	end=1;
	q[1]=1;
	d[1]=0;
	flag[1]=1;  ///为1表示加入队列..

	for(;beg<=end;beg++)
	{
		x=q[beg];
		flag[x]=0; //出队列..
	//	if(x==N)
	//		return d[N]<=K;
        tmp=first[x];
		while(tmp!=-1)
		{
			y=e[tmp].y;
			if(e[tmp].v<=mid)
				v=0;
			else
				v=1;
			if(d[x]+v<d[y])
			{
				d[y]=d[x]+v;
				if(flag[y]==0)
				{
		           flag[y]=1;
				   q[++end]=y;
				}
			}
			tmp=e[tmp].next;
		}
	  }

	return d[N]<=K;
   
}

int main()
{
	int i,j,c,x,y,left,mid,right;
	while(EOF!=scanf("%d %d %d",&N,&M,&K))
	{
		  for(i=1;i<=N;i++)
			  first[i]=-1;
          tot=0;
          while(M--)
		  {
			  scanf("%d %d %d",&x,&y,&c);
			  add(x,y,c);
			  add(y,x,c);
		  }

		  left=0;
		  right=1000000;
		  while(left<=right)
		  {
			  mid=(left+right)/2;
			  if(SPFA(mid))
				  right=mid-1;
			  else
				  left=mid+1;
		  }
		  if(left>1000000)
			  printf("-1\n");
		  else
              printf("%d\n",left);
	}
}
#include<cstdio>
#include<cstring>
const int INF=100000000;
int N,M,S,T,total,c[210][210];
int left,right,mid;
struct node 
{
	int x,y,v;
};
node e[100000];

int h[410],vh[10],augc,found,ans;

void init()
{
	int i,x,y;
	memset(c,0,sizeof(c));
    for(i=1;i<=M;++i)
	{
		x=e[i].x;
		y=e[i].y;
		if(e[i].v<=mid)
		{
			c[x][y]++;
			c[y][x]++;
		}
	}
}

void aug(int x)
{
	int minh=N,augco=augc,i;
	if(x==N)
	{
		found=1;
		ans+=augc;
		return ;
	}
	for(i=1;i<=N;++i)
		if(c[x][i]>0)
		{
			if(h[i]+1==h[x])
			{
				if(c[x][i]<augc)
					augc=c[x][i];
				aug(i);
				if(h[1]>=N)
					return ;
				if(found)
					break;
				augc=augco;
			}
			if(h[i]<minh)
				minh=h[i];
		}
	if(!found)
	{
		vh[h[x]]--;
		if(vh[h[x]]==0)
			h[1]=N;
		h[x]=minh+1;
		vh[h[x]]++;
	}
	else
	{
		c[x][i]-=augc;
		c[i][x]+=augc;
	}
}

int SAP()
{
	memset(h,0,sizeof(h));
	memset(vh,0,sizeof(vh));
	vh[0]=N;
	ans=0;
	while(h[1]<N)
	{
        found=0;
		augc=INF;
		aug(1);
	}
	if(ans>=total)
		return 1;
    return 0;
}

int main()
{
	int i;
	while(EOF!=scanf("%d %d %d",&N,&M,&total))
	{                          
		  left=INF;right=0;     ///可能存在重边...
		  for(i=1;i<=M;++i)
		  {
			  scanf("%d %d %d",&e[i].x,&e[i].y,&e[i].v);
			  if(e[i].v<left)
				  left=e[i].v;
			  if(e[i].v>right)
				  right=e[i].v;
		  }
		  while(left<=right)
		  {
			  mid=(left+right)/2;
			  init();
			  if(SAP())
				  right=mid-1;
			  else
				  left=mid+1;
		  }
		  printf("%d\n",left);
	}
	return 0;
}
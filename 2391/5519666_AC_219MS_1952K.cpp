#include<cstdio>
#include<cstring>
const __int64 INF=1000000000000;
int p[1000],N,M,sum,c[410][410];
__int64 map[1000][1000],left,right,mid;
int S[1000],T[1000],h[1000],vh[1000],xv[1000],yv[1000],found,augc,ans,total;
int vx[1000],vy[1000];

void init()
{
	int i,j;
	memset(c,0,sizeof(c));
    for(i=1;i<=N;++i)
	{
		if(vx[i]>0)
		      c[2*N+1][i]=vx[i];
		if(vy[i]>0)
		      c[i+N][2*N+2]=vy[i];
	}
	for(i=1;i<=N;++i)
		for(j=1;j<=N;++j)
		{
			if(map[i][j]<=mid)
				c[i][j+N]=10000000;
		}
}

void aug(int x)
{
   int i,minh=2*N+2,augco=augc;
   if(x==2*N+2)
   {
	   ans+=augc;
	   found=1;
	   return ;
   }
   for(i=1;i<=2*N+2;++i)
	   if(c[x][i]>0)
       {
		   if(h[x]==h[i]+1)
		   {
			   if(c[x][i]<augc)
				   augc=c[x][i];
			   aug(i);
			   if(h[2*N+1]>=2*N+2)
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
		   h[2*N+1]=2*N+2;
	   h[x]=minh+1;
	   vh[h[x]]++;
   }
   else
   {
	   c[x][i]-=augc;
	   c[i][x]+=augc;
   }
}

int test()
{
	memset(h,0,sizeof(h));
	memset(vh,0,sizeof(vh));
	vh[0]=2*N+2;
	ans=0;
	while(h[2*N+1]<2*N+2)
	{
		found=0;
		augc=10000000;
		aug(2*N+1);
	}
	if(ans>=total)
		return 1;
	return 0;
}

int main()
{
	int i,j,k,x,y,flag;
	__int64 v;
	while(EOF!=scanf("%d %d",&N,&M))
	{
		sum=0;
		flag=1;
		total=0;
		for(i=1;i<=N;++i)  ///构图
		{
			scanf("%d %d",&vx[i],&vy[i]); //注意判断溢出....,可能都为0....
			total+=vx[i];
			sum+=vx[i]-vy[i];
			if(vx[i]>vy[i])
				flag=0;
		}
		for(i=1;i<=N;++i)
		{
			for(j=1;j<=N;++j)
				map[i][j]=INF;
			map[i][i]=0;
		}
		while(M--)
		{
			scanf("%d %d %I64d",&x,&y,&v);
			if(v<map[x][y])
				map[x][y]=map[y][x]=v;
		}
		if(sum>0)
		{
			printf("-1\n");
			continue;
		}
		if(flag)
		{
			printf("0\n");
			continue;
		}
		for(k=1;k<=N;++k)
          for(i=1;i<=N;++i)
			  for(j=1;j<=N;++j)
				  if(map[i][k]!=INF&&map[k][j]!=INF&&map[i][k]+map[k][j]<map[i][j])
					  map[i][j]=map[i][k]+map[k][j];
	    left=INF;right=0;
		for(i=1;i<=N;++i)
		{
			for(j=i+1;j<=N;++j)
				if(map[i][j]!=INF)
				{
					if(map[i][j]<left)
						left=map[i][j];
					if(map[i][j]>right)
						right=map[i][j];
				}
		}
		flag=0;
		while(left<=right)
		{
			mid=(left+right)/2;
			init();
			if(test())
			{
				flag=1;
				right=mid-1;
			}
			else
				left=mid+1;
		}
        if(flag)
		     printf("%I64d\n",left);
		else
			printf("-1\n");
	}
	return 0;
}
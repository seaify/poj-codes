#include<cstdio>
#include<cstring>
const __int64 INF=1100000000;
int p[210],c[210][210],N,M,sum;
__int64 map[210][210],left,right,mid;
int S[210],T[210],h[210],vh[210],xv[210],yv[210],found,augc,ans,total;

void init()
{
	int i,j,x,y;
	memset(c,0,sizeof(c));
	for(i=1;i<=S[0];++i)
		c[0][S[i]]=p[S[i]];
	for(j=1;j<=T[0];++j)
		c[T[j]][N]=-p[T[j]];
	for(i=1;i<=S[0];++i)
		for(j=1;j<=T[0];++j)
		{
			x=S[i];
			y=T[j];
			if(map[x][y]<=mid)
				c[x][y]=p[x];
		}
}

void aug(int x)
{
   int i,minh=N+2,augco=augc;
   if(x==N)
   {
	   ans+=augc;
	   found=1;
	   return ;
   }
   for(i=0;i<=N;++i)
	   if(c[x][i]>0)
       {
		   if(h[x]==h[i]+1)
		   {
			   if(c[x][i]<augc)
				   augc=c[x][i];
			   aug(i);
			   if(h[0]>=N+1)
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
		   h[0]=N+1;
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
	vh[0]=N+1;ans=0;
	while(h[0]<N+1)
	{
		found=0;
		augc=INF;
		aug(0);
	}
	if(ans>=total)
		return 1;
	return 0;
}

int main()
{
	int i,j,k,x,y,v,flag;
	while(EOF!=scanf("%d %d",&N,&M))
	{
		sum=0;flag=1;
		S[0]=0;T[0]=0;total=0;
		for(i=1;i<=N;++i)  ///构图
		{
			scanf("%d %d",&x,&y); //注意判断溢出....,可能都为0....
			p[i]=x-y;   //点的容量...
			if(p[i]>0)
			{
				flag=0;
				S[++S[0]]=i;
				total+=p[i]; 
			}
			else if(p[i]<0)
				T[++T[0]]=i;  //构图一部分....
			sum+=p[i];
		}
		for(i=1;i<=N;++i)
		{
			for(j=1;j<=N;++j)
				map[i][j]=INF;
			map[i][i]=0;
		}
		while(M--)
		{
			scanf("%d %d %d",&x,&y,&v);
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
		left=200*INF;
		right=0;
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
	  //  printf("%I64d %I64d\n",left,right);
	//	left=110;
		N++;
		while(left<=right)
		{
			mid=(left+right)/2;
			init();
			if(test())
				right=mid-1;
			else
				left=mid+1;
		}
		printf("%I64d\n",left);
	}
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<cstring>
const int INF=1000000000;
int N,M,T;
int c[210][210],in[210],out[210];
int h[210],vh[210],augc,found,total,ans;

void aug( int x)
{
	int minh=N,augco=augc,i;
	if(x==N-1)
	{
		found=1;
		ans+=augc;
		return ;
	}
	for(i=0;i<N;++i)
		if(c[x][i]>0)
		{
			if(h[i]+1==h[x])
			{
				if(c[x][i]<augc)
					augc=c[x][i];
				aug(i);
				if(h[0]>=N)
					return ;
				if(found)
					break;
				augco=augc;
			}
			if(h[i]<minh)
				minh=h[i];
		}
    if(!found)
	{
		vh[h[x]]--;
		if(vh[h[x]]==0)
			h[0]=N;
		h[x]=minh+1;
		vh[h[x]]++;
	}
	else
	{
		c[x][i]-=augc;
		c[i][x]+=augc;
	}
}

void SAP()
{
	memset(h,0,sizeof(h));
	memset(vh,0,sizeof(vh));
	vh[0]=N; 
	ans=0;
	while(h[0]<N)
	{
       found=0;
	   augc=INF;
	   aug(0);
	}
	if(ans==total)
		printf("possible\n");
	else
		printf("impossible\n");
}

int main()
{
	int i,x,y,d;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		memset(c,0,sizeof(c));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		while(M--)
		{
			scanf("%d %d %d",&x,&y,&d);  ///下标从1开始....
			in[y]++; 
			out[x]++;
			if(!d)
			{
			   c[x][y]++;	
			}
		}
	    for (i=1;i<=N;i++) 
            if ((in[i]+out[i]) % 2 || abs(in[i]-out[i]) % 2) 
                break; 
		if(i<=N)     
		{
			printf("impossible\n");
			continue;
		}           
		total=0;             //分别引入新的源点和汇点....
        for(i=1;i<=N;++i)
			if(in[i]>out[i])
			{
				c[i][N+1]=(in[i]-out[i])/2;
				total+=c[i][N+1];
			}
			else if(in[i]<out[i])
			{
				c[0][i]=(out[i]-in[i])/2;
			}
		N+=2;
        SAP();
	}
	return 0;
}
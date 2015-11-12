#include<cstdio>
#include<cstdlib>
#include<cstring>
const int INF=1000000000;
const double eps=1e-8;
int N,M,T,n,top;
int c[210][210],f[210][210];
int h[210],vh[210],augc,found,total,ans,s[210],t[210],q[210];
double  x[110],y[110], dis;

void aug( int x)
{
	int minh=n,augco=augc,i;
	if(x==T)
	{
		found=1;
		ans+=augc;
		return ;
	}
	for(i=0;i<n;++i)
		if(c[x][i]>0)
		{
			if(h[i]+1==h[x])
			{
				if(c[x][i]<augc)
					augc=c[x][i];
				aug(i);
				if(h[0]>=n)
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
			h[0]=n;
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
	vh[0]=n; 
	ans=0;
	while(h[0]<n)
	{
       found=0;
	   augc=INF;
	   aug(0);
	}
	if(ans==total)
		q[++top]=T-1;
}

int main()
{
	int i,j,Case;
	double v;
	scanf("%d",&Case);
	while(Case--)
	{
		scanf("%d %lf",&N,&dis);
	    for(i=1;i<=N;++i)
            scanf("%lf %lf %d %d",&x[i],&y[i],&s[i],&t[i]);
		memset(f,0,sizeof(f));
		total=0;
		for(i=1;i<=N;++i)    
		{
			f[0][i]=s[i];
			f[i][i+N]=t[i];
			total+=s[i];
		}
		dis*=dis;
		for(i=1;i<=N;++i)
	 	   for(j=i+1;j<=N;++j)
			  {
				 v=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				 if(v+eps<=dis)
				 {
                   f[i+N][j]=INF;
				   f[j+N][i]=INF;
				 }
			  }
	   n=2*N+1;
	   top=0;
       for(T=1;T<=N;++T)
	   {
		   memcpy(c,f,sizeof(f));
           SAP();
	   }
	   if(top==0)
		   printf("-1\n");
	   else
	   {
		   for(i=1;i<top;++i)
			   printf("%d ",q[i]);
		   printf("%d\n",q[top]);
	   }
	}
	return 0;
}

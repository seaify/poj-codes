#include<cstdio>
#include<cstring>
#include<cmath>
const double INF=900000000;  //
int N,M,sum,top,size;
int S,T,found,h[500],vh[500];
double c[500][500],augc,ans;


void aug(int x)
{
   int i,minh=size;
   double augco=augc;
   if(x==T)
   {
	   found=1;
	   ans+=augc;
	   return ;
   }
   for(i=0;i<size;++i)
	   if(c[x][i]>0)
	   {
		   if(h[i]+1==h[x])
		   {
			   if(c[x][i]<augc)
				   augc=c[x][i];
			   aug(i);
			   if(h[S]>=size)
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
			 h[S]=size;
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
	 vh[0]=size;   //从0开始计数...
	 ans=0;
	 while(h[S]<size)
	 {
		 found=0;
		 augc=INF;
		 aug(S);
	 }
}

int main()
{   
	int i,j,k,time;
	double x;
	scanf("%d",&time);
	while(time--)
	{
		scanf("%d %d %d",&N,&M,&k);
		size=N+M+2;
       	S=0;
		T=size-1;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
				c[i][j]=0;
		for(i=1;i<=N;i++)
		{
			scanf("%lf",&x);
			x=log(x);
			c[S][i]=x;
		}
		for(i=1;i<=M;i++)
		{
			scanf("%lf",&x);
			x=log(x);
			c[i+N][T]=x;
		}
		while(k--)
		{
			scanf("%d %d",&i,&j);
			c[i][j+N]=INF;
		}
		SAP();
	    printf("%.4lf\n",exp(ans));
	}
	return 0;
}



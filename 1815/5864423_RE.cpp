#include<cstdio>
#include<cstring>
const int INF=900000000;  //
int N,M,a[210][210],c[210][210],f[210][210],sum,top;
int augc,ans,S,T,found,h[210],vh[210],q[210];


void aug(int x)
{
   int i,minh=2*N,augco=augc;
   if(x==T)
   {
	   found=1;
	   ans+=augc;
	   return ;
   }
   for(i=1;i<=2*N;++i)
	   if(c[x][i]>0)
	   {
		   if(h[i]+1==h[x])
		   {
			   if(c[x][i]<augc)
				   augc=c[x][i];
			   aug(i);
			   if(h[S]>=2*N)
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
			 h[S]=2*N;
		 h[x]=minh+1;
		 vh[h[x]]++;
	 }
	 else
	 {
		 c[x][i]-=augc;
		 c[i][x]+=augc;
	 }
}

void copy()
{
	 int i,j;
     for(i=1;i<=2*N;i++)
		 for(j=1;j<=2*N;j++)
			 c[i][j]=f[i][j];
}

void SAP()
{
     memset(h,0,sizeof(h));
	 memset(vh,0,sizeof(vh));
	 vh[0]=2*N;   //从0开始计数...
	 ans=0;
	 while(h[S]<2*N)
	 {
		 found=0;
		 augc=INF;
		 aug(S);
	 }
}

int main()
{   
	int i,j,flow;
	while(EOF!=scanf("%d %d %d",&N,&S,&T))
	{
		memset(f,0,sizeof(f));
		for(i=1;i<=N;++i)   //从s'到t即可...
			f[i][i+N]=1;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				scanf("%d",&a[i][j]);
		if(a[S][T])
		{
			printf("NO ANSWER!\n");
			continue;
		}
        for(i=1;i<N;i++)
			for(j=i+1;j<=N;j++)
				if(a[i][j])
				{
					f[i+N][j]=INF;
					f[j+N][i]=INF;
				}
		S+=N;
		copy();
	    SAP();
		flow=ans;
		top=0;
	//	printf("%d\n",flow);
		for(i=1;i<=N&&flow;i++)
		{
             if(i==S||i==T)
				 continue;
			 copy();
			 c[i][i+N]=f[i][i+N]=0;
			 SAP();
			 if(ans<flow)
			 {
				 flow=ans;
				 q[++top]=i;
			 }
			 else
			     f[i][i+N]=1;
		}
		printf("%d\n",top);
		for(i=1;i<top;i++)
			printf("%d ",q[i]);
		if(top)
		      printf("%d\n",q[top]);
	}
	return 0;
}


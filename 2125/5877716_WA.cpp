#include<cstdio>
#include<cstring>
const int INF=900000000;  //
int N,M,sum,top,size;
int S,T,found,h[500],vh[500],a[500],in[500],flag[500];
int c[500][500],augc,ans,tmp;
char b[500];

void aug(int x)
{
   int i,minh=size,augco=augc;
    
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
	 ans=tmp;
	 while(h[S]<size)
	 {
		 found=0;
		 augc=INF;
		 aug(S);
	 }
	 printf("%d\n",ans);
}

int main()
{   
	int i,j,x,tot;
	while(EOF!=scanf("%d %d",&N,&M))
	{
	    size=2*N+2;
		S=0;
		T=2*N+1;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
				c[i][j]=0;
        
		for(i=1;i<=N;i++)
		{
			scanf("%d",&x); 
			c[i+N][T]=x;
			in[i]=0;
			flag[i]=0;
		}

		for(i=1;i<=N;i++)
		{
			scanf("%d",&x);
			c[S][i]=x;
		}

		while(M--)
		{
			scanf("%d %d",&i,&j);
			if(i==j)
			{
				flag[i]=1;
				continue;
			}
			in[i]=1;
			c[i][j+N]=INF;
		}

		tmp=0;
        tot=0;
		for(i=1;i<=N;i++)
		{
			j=c[S][i];
			if(in[i]==0&&flag[i])
			{
				a[++tot]=i;
				b[tot]='-';
				if(c[i+N][T]<j)
				{
					j=c[i+N][T];
					b[tot]='+';
				}	
			
				tmp+=j;
			     
			}
				
		}
		SAP();
		
      

		for(i=1;i<=N;i++)
		{
			if(c[S][i]==0)
			{
			    a[++tot]=i;
				b[tot]='-';  //-
			}

			if(c[i+N][T]==0)
			{
				a[++tot]=i;
				b[tot]='+'; //+
			}

		//	printf("%d %d\n",c[S][i],c[i+N][T]);

		}

		printf("%d\n",tot);
		for(i=1;i<=tot;i++)
			printf("%d %c\n",a[i],b[i]);

	    
	}
	return 0;
}


#include<cstdio>
#include<cstdlib>
#include<cstring>
const int INF=1000000000;

int N,M,T,n,top;
int c[5100][5100];
int h[5100],vh[5100],augc,found,total,ans;
int x[5100],y[5100],q[5100];


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
	
	printf("%d\n",ans);

}

int main()
{
    int cal,C,L,i,j;
    while(EOF!=scanf("%d %d",&C,&L))
    {
         memset(c,0,sizeof(c));
         
         n=C+L+2;
         T=n-1;
         for(i=1;i<=C;i++)
         {
            scanf("%d %d",&x[i],&y[i]);
            c[0][i]=1;
         }
      
         for(i=1;i<=L;i++)
         {
            scanf("%d %d",&q[i],&cal);
            c[i+C][T]=cal;
         }
         
         for(i=1;i<=C;i++)
           for(j=1;j<=L;j++)
              if(x[i]<=q[j]&&q[j]<=y[i])
                  c[i][C+j]=1;
                  
         SAP(); 
            
            
         
    } 
	
	return 0;
}

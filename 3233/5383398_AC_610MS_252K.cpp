#include<cstdio>
#include<cstring>
int a[100][100],cnt[1000],temp[1000],c[100][100],N,K,M,top;
int b[100][100],l[100][100];

void mul(int x[100][100],int y[100][100],int t)
{
	  int z[100][100],i,j,k;
      for(i=0;i<2*N;++i)
		  for(j=0;j<2*N;++j)
		  {
			  z[i][j]=0;
			  for(k=0;k<2*N;++k)
				  z[i][j]=(z[i][j]+x[i][k]*y[k][j])%M;
		  }
	 for(i=0;i<2*N;++i)
	 {
		 for(j=0;j<2*N;++j)
		 {
			 if(t==1)
				 c[i][j]=z[i][j];
			 else
				 a[i][j]=z[i][j];
		 }
	 }
}

void solve()
{
	int i,j;
	while(K)
	{
		if(K&1)
			mul(c,a,1);
		mul(a,a,2);
		K>>=1;
	}
	for(i=0;i<N;++i)
	{
		for(j=N;j<2*N-1;++j)
			if(j-i==N)
                printf("%d ",(c[i][j]-1+M)%M);
			else
				printf("%d ",c[i][j]);
		if(i==N-1)
		    printf("%d\n",(c[i][2*N-1]-1+M)%M);
		else
			printf("%d\n",c[i][2*N-1]);
	}
}

int main()
{
	int i,j;
	while(EOF!=scanf("%d %d %d",&N,&K,&M))
	{
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		for(i=0;i<N;++i)
			for(j=0;j<N;++j)
			{
				scanf("%d",&a[i][j]);
				a[i][j]=a[i][j]%M;////初始化
			}
        for(i=0;i<N;++i)
			a[i][i+N]=1,c[i][i]=1;
		for(i=N;i<2*N;++i)
			a[i][i]=1,c[i][i]=1;
		++K;
		solve();
	}
	return 0;
}
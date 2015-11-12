#include<cstdio>
#include<cstring>
int a[31][31],cnt[1000],temp[1000],ans[31][31],test[31][31],v[31][31],N,K,M,top;
int b[31][31];

void mul(int x[31][31],int y[31][31],int t)
{
	  int c[31][31],i,j,k;
      for(i=0;i<N;++i)
		  for(j=0;j<N;++j)
		  {
			  c[i][j]=0;
			  for(k=0;k<N;++k)
				  c[i][j]=(c[i][j]+x[i][k]*y[k][j])%M;
		  }
	 for(i=0;i<N;++i)
		 for(j=0;j<N;++j)
		 {
			 if(t==1)
				 v[i][j]=c[i][j];
			 else
				 b[i][j]=c[i][j];
		 }
}

void solve(int x,int t)
{
	int i,j;
	memset(v,0,sizeof(v));////单位矩阵
	for(i=0;i<N;++i)
		v[i][i]=1;
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			b[i][j]=a[i][j];
	while(x)
	{
		if(x&1)
			mul(v,b,1);
		mul(b,b,2);
		x>>=1;
	}
	if(t==1)
	{
		for(i=0;i<N;++i)
			++v[i][i];
	}
}

int main()
{
	int i,j,k,it;
	while(EOF!=scanf("%d %d %d",&N,&K,&M))
	{
		for(i=0;i<N;++i)
			for(j=0;j<N;++j)
			{
				scanf("%d",&a[i][j]);
				test[i][j]=a[i][j]=a[i][j]%M;////初始化
			}
        top=0;
		while(K)/////K
		{
			temp[++top]=K;
			if(K&1)
				K=K-1;
			else
				K>>=1;
		}
		j=0;
		for(i=top;i>=1;--i)
             cnt[++j]=temp[i];
	//	for(i=1;i<=top;++i)
	//		printf("%d\n",cnt[i]);
		for(it=2;it<=top;++it)
		{
			if(cnt[i]&1)//test存储上次计算出的结果
			{
				solve(N,0);//结果保存在v[31][31]中
				for(i=0;i<N;++i)
			   	  for(j=0;j<N;++j)
				  {
					  ans[i][j]=(test[i][j]+v[i][j])%M;
				  }
			}
			else
			{
				solve(N/2,1);
				for(i=0;i<N;++i)
					for(j=0;j<N;++j)
					{ 
                       ans[i][j]=0;
					   for(k=0;k<N;++k)
							ans[i][j]=(ans[i][j]+test[i][k]*v[k][j])%M;
					}
			}
			for(i=0;i<N;++i)
				for(j=0;j<N;++j)
					test[i][j]=ans[i][j];
		}
		for(i=0;i<N;++i)
		{
			for(j=0;j<N-1;++j)
                printf("%d ",ans[i][j]);
			printf("%d\n",ans[i][N-1]);
		}

	}
	return 0;
}
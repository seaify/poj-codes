#include<cstdio>
#include<cstring>
__int64 a[110][110],b[110][110],c[110][110];///64位乘法。。。。
int N,M,K;

void mul(__int64 x[110][110],__int64 y[110][110],int t)
{
	 int i,j,k;
	 memset(c,0,sizeof(c));
     for(i=0;i<=N;++i)
		for(k=0;k<=N;++k) 
			if(x[i][k])
			   for(j=0;j<=N;++j)
			       if(y[k][j])
					 c[i][j]+=x[i][k]*y[k][j];
	 if(t==1)
		 memcpy(a,c,sizeof(c));
	 else
		 memcpy(b,c,sizeof(c));
     return ;
}

void solve()     ////a为基数。。。。
{
	 int i;
     memset(b,0,sizeof(b));
	 for(i=0;i<=N;++i)
		 b[i][i]=1;
	 while(M)
	 {
		 if(M&1)
			 mul(b,a,2);
		 mul(a,a,1);
		 M>>=1;
	 }
	 for(i=0;i<N-1;++i)
		 printf("%I64d ",b[N][i]);
	 printf("%I64d\n",b[N][N-1]);
}

int main()
{
	int i,j,k;
	char ch[5];
	while(EOF!=scanf("%d %d %d",&N,&M,&K))
	{
		  if(N==0&&M==0&&K==0)
			  break;
          memset(a,0,sizeof(a));
		  for(i=0;i<=N;++i)
			  a[i][i]=1;
		  while(K--)
		  {
              scanf("%s",ch);
			  if(ch[0]=='g')
			  {
				  scanf("%d",&i);
				  i--;
				  memset(b,0,sizeof(b));
				  for(j=0;j<=N;++j)
					  b[j][j]=1;
				  b[N][i]=1;
				  mul(a,b,1);
			  }
			  else if(ch[0]=='s')
			  {
				  scanf("%d %d",&i,&j);
				  i--;j--;
				  memset(b,0,sizeof(b));
				  for(k=0;k<=N;++k)
				  {
					  if(k!=i&&k!=j)
						  b[k][k]=1;
					  else if(k==i)
						  b[k][j]=1;
					  else
                          b[k][i]=1;
				  }
				  mul(a,b,1);
			  }
			  else
			  {
				  scanf("%d",&i);
				  i--;
				  memset(b,0,sizeof(b));
				  for(k=0;k<=N;++k)
					    b[k][k]=1;
				  b[i][i]=0;
				  mul(a,b,1);
			  }
		  }
		  solve();
	}
	return 0;
}
#include<cstdio>
#include<cstring>
int a[10][10],b[10][10],c[10][10],f[10],N,M;

void mul(int x[10][10],int y[10][10],int t)
{
	int i,j,k;
	memset(c,0,sizeof(c));
    for(i=0;i<6;++i)
	  for(k=0;k<6;++k)
          if(x[i][k])
			  for(j=0;j<6;++j)
				  if(y[k][j])
					  c[i][j]=(c[i][j]+x[i][k]*y[k][j])%M;
	if(t==1)
		memcpy(b,c,sizeof(c));
	else
		memcpy(a,c,sizeof(c));
}

void solve()
{
   int sum,i;
   N=N-1;
   memset(b,0,sizeof(b));
   for(i=0;i<6;++i)
	   b[i][i]=1;
   while(N)
   {
	   if(N&1)
		   mul(b,a,1);
	   mul(a,a,2);
	   N>>=1;
   }
   sum=0;
   for(i=0;i<6;++i)
	   if(i!=2)
	   sum=(sum+b[0][i])%M;
   printf("%d\n",sum);
}

int main()
{
	int i;
	while(EOF!=scanf("%d %d",&N,&M))
	{
		if(N==0&&M==0)
			break;
		memset(a,0,sizeof(a));
		for(i=0;i<6;++i)
			a[0][i]=1,a[i][0]=1,a[i][5-i]=1;
		a[0][2]=0,a[2][0]=0;
		solve();
	}
	return 0;
}
#include<cstdio>
#include<cstring>
int a[10][10],b[10][10],c[10][10],N;

void mul(int x[10][10],int y[10][10],int t)
{
	int i,j,k;
	memset(c,0,sizeof(c));
    for(i=0;i<6;++i)
	  for(k=0;k<6;++k)
          if(x[i][k])
			  for(j=0;j<6;++j)
				  if(y[k][j])
					  c[i][j]=c[i][j]+x[i][k]*y[k][j];
	if(t==1)
		memcpy(b,c,sizeof(c));
	else
		memcpy(a,c,sizeof(c));
}

void solve()
{
   __int64 sum;
   int i;
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
   sum=b[0][1]+b[0][3]+b[0][4]+b[0][5];
   printf("%I64d\n",sum);
}

int main()
{
	int i;
	while(EOF!=scanf("%d",&N))
	{
		if(N==-1)
			break;
		if(N==0||N==1)
		{
			printf("%d\n",1-N);
			continue;
		}
		memset(a,0,sizeof(a));
		for(i=0;i<6;++i)
		{
			a[i][5-i]=1;
			if(i%2)
				a[0][i]=1,a[i][0]=1;
		}
		solve();
	}
	return 0;
}

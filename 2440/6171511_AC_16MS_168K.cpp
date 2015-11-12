#include<cstdio>
#include<cstring>
int a[10][10],b[10][10],c[10][10],f[10],N,M;

void mul(int x[10][10],int y[10][10],int t)
{
	int i,j,k;
	memset(c,0,sizeof(c));
    for(i=0;i<5;++i)
	  for(k=0;k<5;++k)
          if(x[i][k])
			  for(j=0;j<5;++j)
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
   if(N<=4)
   {
      printf("%d\n",f[N]);
      return ;
   }
   
   N=N-4;
   memset(b,0,sizeof(b));
   for(i=0;i<5;++i)
	   b[i][i]=1;
   while(N)
   {
	   if(N&1)
		   mul(b,a,1);
	   mul(a,a,2);
	   N>>=1;
   }
   
   /*for(i=0;i<5;i++)
   {
    // for(j=0;j<5;j++)
    //    printf("%d ",a[i][j]);
     printf("%d ",b[0][i]);
  //   printf("\n");
   }
   printf("\n");*/
   
   sum=(9*b[0][0]+6*b[0][1]+4*b[0][2]+2*b[0][3]+b[0][4])%M; 

   printf("%d\n",sum);
}

int main()
{
	int i;
	
	M=2005;
	
	f[0]=1;
	f[1]=2;
	f[2]=4;
	f[3]=6;
	f[4]=9;
	
	while(EOF!=scanf("%d",&N))
	{
		
		memset(a,0,sizeof(a));
		
		a[0][0]=a[0][2]=a[0][3]=1;
		a[1][0]=a[2][1]=a[3][2]=a[4][3]=1;
		
		solve();
	}
	return 0;
}


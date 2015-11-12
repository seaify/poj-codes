#include<stdio.h>
#include<string.h>
#include<math.h>
const int INF=100000000;
int m,n,x[3100],y[3100],lx[3100],ly[3100],link[3100];
int minx,value[52][2600],p[100][100];
int find(int cur)
{
 int i;
 x[cur]=true;
 for(i=1;i<=n;i++)
 {
   if(!y[i]&&lx[cur]+ly[i]==value[cur][i])
   {
	 y[i]=true;
	 if(link[i]==-1||find(link[i]))
	 {
		link[i]=cur;
		return 1;
	 }
   }
 }
 return 0;
}
int KM()
{
  int i;
  memset(link,-1,sizeof(link));
  for (i=1; i <=n; i++) 
    { 
        while (1) 
        { 
            memset(x, 0, sizeof(x)); 
            memset(y, 0, sizeof(y)); 
            if (find(i)) break; 
            int j, k, min = INF; 
            for (j = 1; j <= n; j++) 
                if (x[j]) 
                    for (k = 1; k <= n; k++) 
                        if (!y[k]) 
                            min= min< lx[j] + ly[k] -value[j][k]?min:lx[j] + ly[k] - value[j][k]; 
            if (!min) break; 
            for (j = 1; j<=n; j++) 
            { 
                if (x[j]) lx[j] -= min; 
                if (y[j]) ly[j] += min; 
            } 
        } 
    } 
  int res = 0; 
    for (i = 1; i <= n; i++) 
            res += value[link[i]][i]; 
    return res; 
}
int main()
{
    int i,j,N,M,T,k,cost;
  	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		for(i=1;i<=N;++i)
			for(j=1;j<=M;++j)
				scanf("%d",&p[i][j]);
		memset(value,0,sizeof(value));
		for(i=1;i<=N;++i)         
			for(j=1;j<=M;++j)
				for(k=1;k<=N;++k)     ////指的是倒数第k个任务....
                     value[i][(j-1)*N+k]=-k*p[i][j];   //费用
  	   n=M*N;     ///总共的点数...
       for (i = 1; i<=n; i++) 
        { 
            lx[i] = -INF, ly[i] = 0; 
            for (j = 1; j <= n; j++) 
            { 
                lx[i] = lx[i]>value[i][j]?lx[i]:value[i][j]; 
            } 
        } 
        cost=-KM(); 
		printf("%.6lf\n",double(cost)/double(N));
  }
  return 0;
}

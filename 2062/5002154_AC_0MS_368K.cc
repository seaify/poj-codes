#include<stdio.h>
#include<string.h>
#include<math.h>
const int INF=100000000;
int m,n,x[101],y[101],lx[101],ly[101],link[101];
int minx,value[110][110],p1[200],p2[200];
char a[100][10],b[100][10];
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
int solve(int i,int j)
{
   if(p1[a[i][0]]<p1[b[j][0]])
         return 1;
   else if(p1[a[i][0]]>p1[b[j][0]])
         return 0;
   else 
   {
      if(p2[a[i][1]]<p2[b[j][1]])
           return 1;
      else 
           return 0;
   }
}
int main()
{
  int i,j,T;
  for(i=2;i<=9;++i)
      p1[i+'0']=i;
  p1['T']=10;p1['J']=11;p1['Q']=12;p1['K']=13;p1['A']=14;
  p2['C']=1;p2['D']=2;p2['S']=3;p2['H']=4;
  scanf("%d",&T);
  while(T--)
  {
   scanf("%d",&n);
   for(i=1;i<=n;++i)
       scanf("%s",a+i);
   for(i=1;i<=n;++i)
       scanf("%s",b+i); 
   memset(value,0,sizeof(value));
   for(i=1;i<=n;++i)
     for(j=1;j<=n;++j)
        value[i][j]=solve(i,j);
   for (i = 1; i<=n; i++) 
        { 
            lx[i] = -INF, ly[i] = 0; 
            for (j = 1; j <= n; j++) 
            { 
                lx[i] = lx[i]>value[i][j]?lx[i]:value[i][j]; 
            } 
        } 
   printf("%d\n",KM());
  }
  return 0;
}

#include<stdio.h>
#include<string.h>
const int maxn=1010;
const int INF=100000000;
int map[maxn][maxn],e[maxn][maxn],d[maxn],sum[maxn];
bool flag[maxn];
int x,m,n;
void dijkstra()
{
    int i,j,minv,s;
    memset(flag,false,sizeof(flag));
    for(i=1;i<=n;++i)
        d[i]=INF;
    d[x]=0;
	for(i=1;i<=n;i++)
	{
	  minv=INF;s=-1;
	  for(j=1;j<=n;j++)
		  if(!flag[j]&&d[j]<minv)
		  {
			  s=j;
			  minv=d[j];
		  }
     if(s==-1)
       break;
	 flag[s]=true;
	 for(j=1;j<=n;j++)
		 if(!flag[j]&&d[s]+map[s][j]<d[j])
		    d[j]=d[s]+map[s][j];
	} 
	for(i=1;i<=n;++i)
	   sum[i]+=d[i];
}
int main()
{
  int cnt,value,i,j;
  while(EOF!=scanf("%d %d %d",&n,&m,&x))
  {
	for(i=1;i<=n;++i)
	{
       for(j=1;j<=n;++j)
           map[i][j]=INF,e[i][j]=INF;
       map[i][i]=0,e[i][i]=0,sum[i]=0;
    }
	while(m--)
	{
	   scanf("%d%d%d",&i,&j,&value);
	   if(value<map[i][j])
	   {
         map[i][j]=value;
         e[j][i]=value;
       }
	}
	dijkstra();
	for(i=1;i<=n;++i)
	  for(j=1;j<=n;++j)
	      map[i][j]=e[i][j];
    dijkstra();
    cnt=0;
    for(i=1;i<=n;++i)
       if(i!=x&&sum[i]>cnt)
          cnt=sum[i];
    printf("%d\n",cnt);
  }
  return 0;
}

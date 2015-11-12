#include<stdio.h>
#include<string.h>
const int maxn=1010;
const int INF=100000000;
int map[maxn][maxn],d[maxn];
bool flag[maxn];
int m,n;
void dijkstra()
{
    int i,j,minv,s;
    memset(flag,false,sizeof(flag));
    for(i=1;i<=n;++i)
        d[i]=INF;
    d[1]=0;
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
	 if(flag[n])
	   break;
	 for(j=1;j<=n;j++)
		 if(!flag[j]&&d[s]+map[s][j]<d[j])
		    d[j]=d[s]+map[s][j];
	} 
}
int main()
{
  int cnt,value,i,j;
  while(EOF!=scanf("%d %d",&n,&m))
  {
	for(i=1;i<=n;++i)
	{
       for(j=1;j<=n;++j)
           map[i][j]=INF;
       map[i][i]=0;
    }
	while(m--)
	{
	   scanf("%d%d%d",&i,&j,&value);
	   if(value<map[i][j])
          map[i][j]=map[j][i]=value;
	}
	dijkstra();
    printf("%d\n",d[n]);
  }
  return 0;
}

#include<stdio.h>
#include<string.h>
const int maxn=1010;
const int INF=1000002;
int map[maxn][maxn],d[maxn];
bool flag[maxn];
int main()
{
  int i,j,t,time,k,x,m,n,max,value;
  scanf("%d",&t);
  time=0;
  while(t--)
  {
	scanf("%d%d",&n,&m);
	memset(map,0,sizeof(map));
	while(m--)
	{
	  scanf("%d%d%d",&i,&j,&value);
      map[j][i]=map[i][j]=value;
	}
	for(i=2;i<=n;i++)
	{
	 flag[i]=false;
	 d[i]=map[1][i];
	}
	d[1]=INF;flag[1]=true;
	for(i=1;i<n;i++)
	{
	  max=0;
	  for(j=2;j<=n;j++)
		  if(!flag[j]&&d[j]>max)
		  {
			  x=j;
			  max=d[j];
		  }
	 flag[x]=true;
	 if(flag[n])
		 break;
	 for(j=2;j<=n;j++)
		 if(!flag[j])
		 { 
			 k=max<map[x][j]?max:map[x][j];
			 d[j]=d[j]>k?d[j]:k;
		 }	
	} 
    printf("Scenario #%d:\n",++time);
	printf("%d\n\n",d[n]);
  }
  return 0;
}
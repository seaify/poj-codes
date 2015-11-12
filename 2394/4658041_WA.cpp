#include<stdio.h>
#include<string.h>
const int maxn=510;
const int INF=35000000;
int map[maxn][maxn],min[maxn],x[maxn];
bool flag[maxn];
int main()
{
  int i,j,f,p,m,c,k,s;
  scanf("%d%d%d%d",&f,&p,&c,&m);
  memset(map,INF,sizeof(map));
  memset(flag,false,sizeof(flag));
  for(k=1;k<=p;k++)
  {
	  scanf("%d%d%d",&i,&j,&s);
	  map[i][j]=s;
	  map[j][i]=s;
  }
  for(i=2;i<=f;i++)
	  min[i]=map[1][i];
  min[1]=0;flag[1]=true;
  for(i=2;i<=f;i++)
  {
	k=INF;
	for(j=2;j<=f;j++)
	  if(!flag[j]&&min[j]<k)
	  {
		s=j;
		k=min[j];
	  }
	flag[s]=true;
	for(j=2;j<=f;j++)
		if(!flag[j]&&k+map[s][j]<min[j])
		{
			min[j]=k+map[s][j];
		}
  } 
  k=0;
  for(i=1;i<=c;i++)
  {
	  scanf("%d",&j);
	  if(map[1][j]<=m)
		  x[++k]=i;
  }
  printf("%d\n",k);
  for(i=1;i<=k;i++)
	  printf("%d\n",x[i]);
 return 0;
}

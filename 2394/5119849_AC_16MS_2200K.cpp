#include<stdio.h>
#include<string.h>
const int maxn=1010;
const int INF=100000002;
int map[maxn][maxn],d[maxn],pos[maxn],out[maxn];
bool flag[maxn];
int main()
{
  int i,j,t,k,C,sum,x,m,n,min,value;
  while(EOF!=scanf("%d%d%d%d",&n,&m,&C,&sum))
  {
	for(i=1;i<=n;++i)
	{
	  for(j=1;j<=n;++j)
	       map[i][j]=INF;
      map[i][i]=0;
    }
	while(m--)
	{
	  scanf("%d %d %d",&i,&j,&value);
	  if(value<map[i][j])
          map[i][j]=map[j][i]=value;
	}
	for(i=1;i<=C;++i)
	    scanf("%d",&pos[i]);
	for(i=2;i<=n;i++)
	{
	 flag[i]=false;
	 d[i]=map[1][i];
	}
	d[1]=0;
	for(i=1;i<n;i++)
	{
	  min=INF;x=-1;
	  for(j=2;j<=n;j++)
		  if(!flag[j]&&d[j]<min)
		  {
			  x=j;
			  min=d[j];
		  }
     if(x==-1)
         break;
	 flag[x]=true;
	 for(j=2;j<=n;j++)
		 if(!flag[j]&&d[x]+map[x][j]<d[j])
               d[j]=d[x]+map[x][j];
	} 
	j=0;
	for(i=1;i<=C;++i)
	   if(d[pos[i]]<=sum)
	      out[++j]=i;
    printf("%d\n",j);
    for(i=1;i<=j;++i)
       printf("%d\n",out[i]);  
  }
  return 0;
}

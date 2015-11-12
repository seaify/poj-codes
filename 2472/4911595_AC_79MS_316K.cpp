#include<stdio.h>
#include<string.h>
const int maxn=110;
const double eps=1e-9;
double map[maxn][maxn],d[maxn],last,max,value;
bool flag[maxn];
int main()
{
  int i,j,k,m,n,x;
  while(EOF!=scanf("%d%d",&n,&m))
  {
	if(n==0)
	    break;
	memset(map,0,sizeof(map));
	while(m--)
	{
	  scanf("%d%d%lf",&i,&j,&value);
      map[j][i]=map[i][j]=value/100.0;
	}
	for(i=2;i<=n;i++)
	{
	 flag[i]=false;
	 d[i]=map[1][i];
	}
	last=1.0;
	for(i=1;i<n;i++)
	{
	  max=0;
	  for(j=2;j<=n;j++)
		  if(!flag[j]&&d[j]-max>eps)
		  {
			  x=j;
			  max=d[j];
		  }
	 flag[x]=true;
	 last*=max;
	 if(flag[n])
		 break;
	 for(j=2;j<=n;j++)
		 if(!flag[j]&&d[j]+eps<d[x]*map[x][j])
		 { 
		
			 d[j]=d[x]*map[x][j];
		 }	
	} 
	d[n]*=100;
	printf("%.6lf percent\n",d[n]);
  }
  return 0;
}

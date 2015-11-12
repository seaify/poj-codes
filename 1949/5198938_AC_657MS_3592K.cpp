#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector < int > v[10005];
int n,i,j,k,d[11000],sum[11000],maxw,temp;
int main()
{
  while(EOF!=scanf("%d",&n))
  {
	  for(i=1;i<=n;++i)
		  v[i].clear(),sum[i]=0;
	  for(i=1;i<=n;++i)
	  {
		 scanf("%d%d",&d[i],&j);
		 while(j--)
		 {
		    scanf("%d",&k);
			v[i].push_back(k);
		 }
	  }
	  sum[1]=d[1];maxw=d[1];
	  for(i=2;i<=n;++i)
	  {
		  k=0;
		  for(j=0;j<v[i].size();++j)
		  {
			  temp=v[i][j];
			  if(sum[temp]>=k)
				  k=sum[temp];
		  }
		  sum[i]=k+d[i];
		  if(sum[i]>maxw)
			  maxw=sum[i];
	  }
	  printf("%d\n",maxw);
  }
  return 0;
}
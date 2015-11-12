#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector< int > a[10000];
int n,m,ans,c[110000];

void dfs(int cur)
{
	int i,j,v,T,flag;
	if(cur==n)
	{
		ans=1;
		return ;
	}
	if(c[cur]||c[cur+n])
	{
		dfs(cur+1);
		return ;
	}
	for(j=0;j<=1;++j)
	{
	  T=cur+j*n;
	  flag=1;
	  for(i=0;i<a[T].size();++i)
	  {
	   	v=a[T][i];
		if(c[v]==1)
		{
			flag=0;
			break;
		}
	  }
	  if(flag)
	  {
		  c[T]=1;
	      dfs(cur+1);
		  if(ans)
			  return ;
		  c[T]=0;
	  }
	}
}

void output()
{
	int i;
	if(ans==0)
	{
		printf("bad luck\n");
		return ;
	}
	for(i=0;i<2*n;++i)
		printf("%d ",c[i]);
	printf("\n");
	ans=c[0];
    for(i=1;i<n-1;++i)
	{
		if(c[i]==ans)
			printf("%dw ",i);
		else
			printf("%dh ",i);
	}
	if(c[n-1]==ans)
		printf("%dw\n",n-1);
	else
		printf("%dh\n",n-1);
}
int main()
{
    char ch1[5],ch2[5];
	int i,j;
    while(EOF!=scanf("%d %d",&n,&m))
    {
      if(n==0&&m==0)
            break;
	  for(i=0;i<2*n;++i)
		  a[i].clear();
	  for(i=0;i<n;++i)
	  {
		  a[i].push_back(i+n);
		  a[i+n].push_back(i);
	  }
	  while(m--)
	  {
		  scanf("%s %s",ch1,ch2);
		  i=ch1[0]-'0';
		  j=ch2[0]-'0';
		  if(ch1[1]=='h')
			  i+=n;
		  if(ch2[1]=='h')
			  j+=n;
		  a[i].push_back(j);
		  a[j].push_back(i);
	  }
	  memset(c,0,sizeof(c));
	  ans=0;
	  c[0]=1;
      dfs(1);
	  output();
   }
   return 0;
}



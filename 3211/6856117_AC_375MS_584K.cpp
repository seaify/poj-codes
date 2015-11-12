#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int INF=100010;
#define min(a,b) a<b?a:b;
#define max(a,b) a>b?a:b;

map<string,int> word;
vector<int> V[20];

int m,n,sum[20];
int f[INF];

int solve(int x)
{
    int i,j,y,tmp;
	for(i=0;i<=INF;i++)
		f[i]=0;
	f[0]=1;
	for(i=0;i<V[x].size();i++)
	{
		y=V[x][i];
		for(j=INF-y;j>=0;j--)
			if(f[j])
				f[j+y]=1;
	}
	tmp=sum[x];
	for(i=0;i<=INF;i++)
		if(f[i])
		{
           j=max(i,sum[x]-i);
		   tmp=min(tmp,j);
		}
	return tmp;
}

int main()
{
	int i,x,result;
	char ch[100];

	while(EOF!=scanf("%d %d",&m,&n))
	{
		 if(m==0&&n==0)
			 break;
		 for(i=1;i<=m;i++)
		 {
             scanf("%s",ch);
			 word[ch]=i;
			 V[i].clear();
			 sum[i]=0;
		 }
		 for(i=1;i<=n;i++)
		 {
			 scanf("%d %s",&x,ch);
             V[word[ch]].push_back(x);
			 sum[word[ch]]+=x;
		 }
		 result=0;
		 for(i=1;i<=m;i++)
		     result+=solve(i);
		 printf("%d\n",result);
	}
	return 0;
}
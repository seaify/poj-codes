#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=40000;
int h[maxn];
int SA[maxn],Rank[maxn],nRank[maxn];
int n,m,op,num[maxn],len,mid;

int maxx(int a,int b)
{
	if(a<b)
		return b;
	return a;
}

int minx(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

int cmp(int a,int b)
{
	return num[a]<num[b];
}

int cmp2(int a,int b)
{
	if(nRank[a]!=nRank[b])
		return nRank[a]<nRank[b];
	else
		return nRank[a+len]<nRank[b+len];
}

void suffixArray()
{
   int i;
   
   for(i=0;i<n;i++)
	   SA[i]=i;
     
   sort(SA,SA+n,cmp);

   for(i=1,Rank[SA[0]]=0;i<n;i++)
   {
	   Rank[SA[i]]=Rank[SA[i-1]];
	   if(num[SA[i]]!=num[SA[i-1]])
		   Rank[SA[i]]++;
   }

   for(len=1;len<n;len<<=1)
   {
	   memcpy(nRank,Rank,sizeof(int)*n);
	   sort(SA,SA+n,cmp2);
	   for(i=1,Rank[SA[0]]=0;i<n;i++)
	   {
		   Rank[SA[i]]=Rank[SA[i-1]];
		   if(nRank[SA[i]]!=nRank[SA[i-1]]||nRank[SA[i]+len]!=nRank[SA[i-1]+len])
			   Rank[SA[i]]++;
	   }
   }
}


void lcp()
{
  int i,j,k;
  for(i=0,k=0;i<n;i++)
  {
    if(Rank[i]==0)
       h[Rank[i]]=0;
   else
   {  
       j=SA[Rank[i]-1];
      while(num[i+k]==num[j+k])
         k++;
       h[Rank[i]]=k;
       if(k>0)
           k--;
   }
  }
}


int check()
{
	int i,ls,rs;

    ls=20000;
	rs=0;

	for(i=1;i<n;i++)
	{
		if(h[i]>=mid)
		{
             rs=maxx(rs,maxx(SA[i-1],SA[i]));
			 ls=minx(ls,minx(SA[i-1],SA[i]));

			 if(rs-ls>=mid)
				 return 1;
		}
		else
		{
			ls=20000;
			rs=0;
		}
	}

	return 0;

}

void solve()
{
	
	int left=3,right=n/2,ans;


	while(left<=right)
	{
		mid=(left+right)/2;
		if(check())
			left=mid+1,ans=mid;
		else
			right=mid-1;
	}
	if(ans>=4)
	      printf("%d\n",ans+1);
	else
		printf("0\n");
}


int main()
{
	int i,last,x;
    while(EOF!=scanf("%d",&n))
	{	 
		if(n==0)
			break;
		scanf("%d",&last);
		n--;
        for(i=1;i<=n;i++)
		{
		     scanf("%d",&x);
			 num[i-1]=x-last+100;
			 last=x;
		}

	    memset(nRank,-1,sizeof(nRank));
		memset(Rank,-1,sizeof(Rank));
        suffixArray();
        lcp();
		solve();
	}
      return 0;
}


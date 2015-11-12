#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=110000;
int h[maxn];
int SA[maxn],Rank[maxn],nRank[maxn],l[maxn],r[maxn];
int n,m,rank,num[maxn],len,size;

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

int minx(int a,int b)
{
	if(a<b)return a;
	return b;
}

int maxx(int a,int b)
{
	if(a>b)
		return a;
	return b;
}


void solve()
{
    int i,sum;
	l[0]=0;
	for(i=1;i<n;i++)        /////左边...
		if(SA[i]<size)
		{
			if(SA[i-1]>size)
				l[i]=h[i];
			else
				l[i]=minx(l[i-1],h[i]);
		}

   r[n-1]=0;

   for(i=n-2;i>=0;i--)
        if(SA[i]<size)
		{
             if(SA[i+1]>size)
				 r[i]=h[i+1];
			 else
				 r[i]=minx(r[i+1],h[i+1]);
				 
		}

   sum=0;

  for(i=0;i<n;i++)
	  if(SA[i]<size&&maxx(l[i],r[i])==rank)
		  sum++;

   printf("%d\n",sum);


}


int main()
{
	int i;
    while(EOF!=scanf("%d %d %d",&n,&m,&rank))
	{	 
        for(i=0;i<n;i++)
		     scanf("%d",&num[i]);
		num[n]=-1;
		for(i=1;i<=m;i++)
			 scanf("%d",&num[n+i]);
		size=n;
		n=n+m+1;

	    memset(nRank,-1,sizeof(nRank));
		memset(Rank,-1,sizeof(Rank));
        suffixArray();
        lcp();
		solve();
	}
      return 0;
}


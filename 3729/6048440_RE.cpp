#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=410000;
int h[maxn];
int *SA,*nSA,*nRank,*Rank,l[maxn],r[maxn],cnt[15000],mem[4][maxn];
int n,m,ord,num[maxn],size;

void suffixArray()
{
  int i,j;
  memset(cnt,0,sizeof(cnt));
  Rank=mem[1];
  SA=mem[0];
  nRank=mem[3];
  nSA=mem[2];
  for(i=0;i<n;i++)   
    cnt[num[i]]++;
  for(i=1;i<=11000;i++)
    cnt[i]+=cnt[i-1];
  for(i=n-1;i>=0;i--)
    SA[--cnt[num[i]]]=i;              
  Rank[SA[0]]=0;  
  for(i=1;i<n;i++)
    {
    Rank[SA[i]]=Rank[SA[i-1]];                
    if (num[SA[i]]!=num[SA[i-1]])
      Rank[SA[i]]++;
    }
  for(j=1;j<n&&Rank[SA[n-1]]!=n-1;j<<=1)
    {
    for(i=0;i<n;i++)
      cnt[Rank[SA[i]]]=i+1;                                        
    for(i=n-1;i>=0;i--)
      if (SA[i]>=j)
        nSA[--cnt[Rank[SA[i]-j]]]=SA[i]-j;
    for(i=n-j;i<n;i++)
      nSA[--cnt[Rank[i]]]=i;
    nRank[nSA[0]]=0;  
    for(i=1;i<n;i++)
      {
      nRank[nSA[i]]=nRank[nSA[i-1]];
      if (Rank[nSA[i]]!=Rank[nSA[i-1]]||Rank[nSA[i]+j]!=Rank[nSA[i-1]+j])
        nRank[nSA[i]]++;                
      }        
    swap(nSA,SA);
    swap(nRank,Rank);  
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
	  if(SA[i]<size&&maxx(l[i],r[i])==ord)
		  sum++;

   printf("%d\n",sum);


}


int main()
{
	int i;
    while(EOF!=scanf("%d %d %d",&n,&m,&ord))
	{	 
		for(i=0;i<n;i++)
		{
		     scanf("%d",&num[i]);
		     num[i]+=2;
		}
		num[n]=1;
		for(i=1;i<=m;i++)
		{
			 scanf("%d",&num[n+i]);
			 num[n+i]+=2;
		}
		num[n+m+1]=0;
		size=n;
		n=n+m+2;
        suffixArray();
        lcp();
		solve();
	}
      return 0;
}




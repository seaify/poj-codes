#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXN=100010*2;
char str[MAXN];
int c[MAXN],h[MAXN],mem[3][MAXN],n,len1,len2;
int *SA,*nSA,*nRank,*Rank;
void suffixArray()
{
  int i,k;
  memset(c,0,sizeof(c));
  for(i=0;i<n;i++)
	  c[str[i]]++;
  for(i=1;i<200;i++)
	  c[i]+=c[i-1];
  SA=mem[0];nSA=mem[1];Rank=mem[2];
  for(i=0;i<n;i++)
	  SA[--c[str[i]]]=i;
  for(Rank[SA[0]]=0,i=1;i<n;i++)
  {
   	 Rank[SA[i]]=Rank[SA[i-1]];
	 if(str[SA[i]]!=str[SA[i-1]])
		 Rank[SA[i]]++;
  }
  for(k=1;k<n&&Rank[SA[n-1]]<n-1;k*=2)
  {
	 for(i=0;i<n;i++)
		 c[Rank[SA[i]]]=i;
	 for(i=n-1;i>=0;i--)
	     if(SA[i]>=k)
			 nSA[c[Rank[SA[i]-k]]--]=SA[i]-k;
	for(i=n-k;i<n;i++)
		nSA[c[Rank[i]]]=i;
	nRank=SA,SA=nSA;
	for(nRank[SA[0]]=0,i=1;i<n;i++)
	{
	   nRank[SA[i]]=nRank[SA[i-1]];
	   if(Rank[SA[i]]!=Rank[SA[i-1]]||Rank[SA[i]+k]!=Rank[SA[i-1]+k])
		   nRank[SA[i]]++;
	}
	nSA=Rank,Rank=nRank;
  }
}
int lcp()
{
  int i,j,k,res;
  for(i=0,k=0;i<n;i++)
  {
	 if(Rank[i]==0)
		 h[Rank[i]]=0;
	 else
	 {		
		j=SA[Rank[i]-1];
		while(str[i+k]==str[j+k])
			k++;
		h[Rank[i]]=k;
		if(k>0)
			k--;
	 }
  }
  res=0;
  for(i=1;i<n;i++)
  {
	if((SA[i]<len1)!=(SA[i-1]<len1))
		if(h[i]>res)
			res=h[i];
  }
  return res;
}
void go()
{
  scanf("%s",str);
  len1=strlen(str);
  str[len1++]=2;
  scanf("%s",str+len1);
  len2=strlen(str+len1);
  n=len1+len2;
  str[n++]=1;
  suffixArray();
  printf("%d\n",lcp());
}
int main()
{
  go();
  return 0;
}

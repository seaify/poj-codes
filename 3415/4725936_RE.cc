#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
const int MAXN=100010;
char str[MAXN];
int c[MAXN],h[MAXN],mem[3][MAXN],n;
int min[MAXN][20],p[22],i,j,len1,len2;
int *SA,*nSA,*nRank,*Rank;
 struct Stack
{
  bool flag;
  int index;
};
Stack stack[2*MAXN];
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
void init()
{
 int m;
 for(i=0;i<=18;i++)
	   p[i]=(1<<i);
 for(i=1;i<=n;i++)
	 min[i][0]=h[i-1];
 m=int(log((double)n)/log(2.0));
 for(i=1;i<=m;i++)
   for(j=n+1-p[i];j>=1;j--)
   {
	   min[j][i]=min[j][i-1]<min[j+p[i-1]][i-1]?min[j][i-1]:min[j+p[i-1]][i-1];
   }
}
int RMQ(int i,int j)
{
 int m,a;
 if(i==j)
	 return n-i;
 i=Rank[i-1]+1;
 j=Rank[j-1]+1;
 if(i>j)
 {
    a=i;
	i=j;
	j=a;
 }
 i++;
 m=int(log((double)(j-i+1))/log(2.0));
 a=min[i][m]<min[j-p[m]+1][m]?min[i][m]:min[j-p[m]+1][m];
 return a;
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
		while(str[i+k]==str[j+k])
			k++;
		h[Rank[i]]=k;
		if(k>0)
			k--;
	 }
  }
}
int main()
{
  int t,length;__int64 sum;
  while(EOF!=scanf("%d",&t))
  {
  if(t==0)
	  break;
  //memset(str,0,sizeof(str));
  scanf("%s",str);
  len1=strlen(str);
  length=len1;
  str[len1++]=2;
  scanf("%s",str+len1);
  len2=strlen(str+len1);
  n=len1+len2;
  str[n++]=1;
  suffixArray();
  lcp();
  init();
  /*for(i=1;i<len1;i++)
  {
	for(j=len1+1;j<n;j++)
		printf("%d ",RMQ(i,j));
	printf("\n");
  }*/
  for(i=2;i<n;i++)
  {
	stack[i-1].index=SA[i]+1;
	if(stack[i-1].index>=len1+1)
		stack[i-1].flag=true;
	else
		stack[i-1].flag=false;
  }
  length=2*length;sum=0;
  for(i=1;i<length;i++)
  {
    j=i+1;
	while(j<=length&&RMQ(stack[i].index,stack[j].index)>=t)
	{
		if(stack[i].flag!=stack[j].flag)
		   sum+=RMQ(stack[i].index,stack[j].index)-t+1;
		j++;
	}
  }
  printf("%I64d\n",sum);
  }
  return 0;
}

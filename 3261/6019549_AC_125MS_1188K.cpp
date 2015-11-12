#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=100000;
int h[maxn];
int SA[maxn],Rank[maxn],nRank[maxn];
int n,m,op,num[maxn],len,mid;

int cmp(int a,int b)
{
	return num[a]<num[b];
}

int cmp2(int a,int b)
{
	if(nRank[a]!=nRank[b])
		return nRank[a]<nRank[b];
	else
	{
	//	if(a+len>=n)
	//		return 1;
	//	if(b+len>=n)
	//		return 0;
		return nRank[a+len]<nRank[b+len];
	}
}

void debug()
{
   int i;
   printf("SA数组为:\n");
   for(i=0;i<n;i++)
       printf("%d ",SA[i]);
   printf("\n"); 

     printf("Rank数组为:\n"); 
   for(i=0;i<n;i++)
       printf("%d ",Rank[i]);
       
   printf("\n\n");
    
   /*printf("h数组为:\n"); 
   for(i=0;i<n;i++)
       printf("%d ",h[i]);
       
   printf("\n\n");
   */
     
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

   //debug();

   for(len=1;len<n;len<<=1)
   {
	   memcpy(nRank,Rank,sizeof(Rank));
	   sort(SA,SA+n,cmp2);
	   for(i=1,Rank[SA[0]]=0;i<n;i++)
	   {
		   Rank[SA[i]]=Rank[SA[i-1]];
		   if(nRank[SA[i]]!=nRank[SA[i-1]]||nRank[SA[i]+len]!=nRank[SA[i-1]+len])
			   Rank[SA[i]]++;
	   }
	 //  debug();
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
	int i,c=0;

	for(i=0;i<n;i++)
	{
		if(h[i]>=mid)
			c++;
		else
			c=0;
		if(c+1>=op)
			return 1;
	}
	return 0;
}

void solve()
{
	int left=1,right=n,ans;

	while(left<=right)
	{
		mid=(left+right)/2;
		if(check())
			left=mid+1,ans=mid;
		else
			right=mid-1;
	}
	printf("%d\n",ans);
}


int main()
{
	int i;

   // freopen("check.txt","r",stdin);
   // freopen("1.txt","w",stdout);
    while(EOF!=scanf("%d %d",&n,&op))
	{	 
        for(i=0;i<n;i++)
		     scanf("%d",&num[i]);
	    memset(nRank,-1,sizeof(nRank));
		memset(Rank,-1,sizeof(Rank));
        suffixArray();
        lcp();
	//	debug();
		solve();
	}
      return 0;
}


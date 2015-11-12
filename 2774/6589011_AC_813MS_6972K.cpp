#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[120000];
int c[210000],beg[1210000],x[210000],y[210000],no[210000];
int a[210000],b[210000],Rank[210000],SA[210000],nRank[210000];
int flag[210000],h[210000],len[10];

int cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void radix_sort(int *x,int n)     ///0<=no[i]<=n,且no值唯一,并非最终所求结果...
{
	int i,m;
    m=n>255?n:255;                       	/////按no值排序,故n<=100000;
    for(i=0;i<=m;i++)
		c[i]=0;
	for(i=1;i<=n;i++)
		c[b[i]=x[no[i]]]++;
	for(i=1;i<=m;i++)
		c[i]+=c[i-1];
	for(i=n;i>=1;i--)
		SA[c[b[i]]--]=no[i];  ////位置..
	for(i=1;i<=n;i++)
		no[i]=SA[i];   //SA值唯一..
}    

void lcp(int *r,int n)
{
	int i,j,k=0,res;
	for(i=1;i<=n;)
	{
		if(k>=1)
			k--;
		j=SA[Rank[i]-1];
		while(r[i+k]==r[j+k])
			k++;
		h[Rank[i++]]=k;
	}
	res=0;
	for(i=2;i<=n;i++)
		if((SA[i]<=len[1])!=(SA[i-1]<=len[1]))
			res=res>h[i]?res:h[i];
	printf("%d\n",res);
}

void da(int *r,int n)   //////并不需要末尾由0结尾....
{
	 int i,j,p;
	 for(i=1;i<=n;i++) no[i]=i;
     radix_sort(r,n);
	 for(Rank[SA[1]]=1,i=2,p=2;i<=n;i++)
		 Rank[SA[i]]=cmp(r,SA[i-1],SA[i],0)?p-1:p++;

	 for(j=1;j<n;j*=2)           ///Rank值需要保证从1计数,才可以保证第二关键字为0时最小.
	 {
		 for(i=1;i<=n;i++)
			 x[i]=Rank[i],y[i]=i+j>n?0:Rank[i+j];
		 for(i=1;i<=n;i++) no[i]=i;
		 radix_sort(y,n);
		 radix_sort(x,n);
		 for(nRank[SA[1]]=1,i=2,p=2;i<=n;i++)
			 nRank[SA[i]]=cmp(Rank,SA[i-1],SA[i],j)?p-1:p++;
		 for(i=1;i<=n;i++)
			 Rank[i]=nRank[i];
		 if(p>n)
			 break;
	 }
	 lcp(r,n);
}



int main()
{
	int i,j,n=0;
	for(i=1;i<=2;i++)
	{
		scanf("%s",s+1);
	    len[i]=strlen(s+1);
		s[len[i]+1]='\0';
		for(j=1;j<=len[i];j++)
			a[++n]=s[j]-'a'+20;
		if(i==1)
			a[++n]=2;
	}
	a[n+1]=0;
	da(a,n);
}
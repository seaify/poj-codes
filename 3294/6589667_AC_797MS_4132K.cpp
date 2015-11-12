#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[1200];
int c[120000],beg[120000],x[120000],y[120000],no[120000];
int a[120000],b[120000],Rank[120000],SA[120000],nRank[120000];
int flag[120000],h[120000],m,KK;

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
	int i,j,k=0;
	for(i=1;i<=n;)
	{
		if(k>=1)
			k--;
		j=SA[Rank[i]-1];
		while(r[i+k]==r[j+k])
			k++;
		h[Rank[i++]]=k;
	}
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

int calc(int x)
{
	int left=1,mid,right=m;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(x==beg[mid])
			 return mid;
        else if(x<beg[mid])
			 right=mid-1;
		else
			 left=mid+1;
	}
	return right;
}

int check(int len,int n)  ////在判断是否存在时，记录下解...
{
	int i,dis,sum=0,group=0,*result;

	for(i=1;i<=m;i++)
		flag[i]=0;
	h[n+1]=0;

	for(i=1;i<=n+1;i++)  ////确保最后一个组被计算.
	{
		if(h[i]<len)
		{
		    group++;	
			if(sum>=KK)
	           return 1;
			sum=0;
		}
		
		dis=calc(SA[i]);

		if(flag[dis]<group)
			sum++;
		flag[dis]=group;
	}
	return 0;
}

void output(int len,int n)
{
	int i,j,dis,cc,sum=0,group=0,*result;

	for(i=1;i<=m;i++)
		flag[i]=0;
	h[n+1]=0;

	for(i=1;i<=n+1;i++)  ////确保最后一个组被计算.
	{
		if(h[i]<len)
		{
		    group++;	
			if(sum>=KK)
			{
                 cc=SA[i-1];
				 for(j=0;j<len;j++)
					 printf("%c",a[cc+j]+'a'-120);
				 printf("\n");
			}
			sum=0;
		}
		
		dis=calc(SA[i]);

		if(flag[dis]<group)
			sum++;
		flag[dis]=group;
	}
}


int main()
{
	int i,j,n,dd,len;
	int left,mid,right;

	while(EOF!=scanf("%d",&m)&&m)
	{
		 n=0;right=0;KK=m/2+1;
         for(j=1;j<=m;j++)  ///
		 {
			 scanf("%s",s+1);
			 beg[j]=n+1;
		     len=strlen(s+1);
			 right=len>right?len:right;
		 	 for(i=1;i<=len;i++)
			     a[++n]=s[i]-'a'+120;
			 if(j<m)
				 a[++n]=m-j;
		 }
		 a[n+1]=0;
		 da(a,n);

		 left=0;
		 while(left<=right)
		 {
			 mid=(left+right)/2;
			 if(check(mid,n))   //////
				 left=mid+1;
			 else
				 right=mid-1;
		 }
            
         if(right>=1)
			 output(right,n);
		 else
			 printf("?\n");
		 printf("\n");

	}
}
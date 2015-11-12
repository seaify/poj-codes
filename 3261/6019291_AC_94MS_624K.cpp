#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_value=20001;
int m[max_value];
int sa[max_value],lstsa[max_value];
int rank[max_value],lstrank[max_value];
int h[max_value];
int pow,n,op,mid;
int cmp1(const void * a,const void *b)
{
		const int * x = (const int *)a;
		const int * y = (const int *)b;

		return m[*x]-m[*y];
}
int cmp2(const void * a,const void  * b)
{
		const int * x= (const int *)a;
		const int * y = (const int *)b;

		if(lstrank[*x]!=lstrank[*y])
				return lstrank[*x]-lstrank[*y];
		else
				return lstrank[*x+pow]-lstrank[*y+pow];
}
void suffix_array(int n)
{
		int i=0;
		int j = 0;
		//caculate sa and rank when pow = 1;
		for(i=1;i<=n;i++)
				sa[i]=i;
		qsort(sa,n,sizeof(int),cmp1);

		for(i=1,j=0;i<=n;i++)
		{
				if(i==1 || m[sa[i]]!=m[sa[i-1]])//when there are some continous-muti,e."aabbbaa",they have the same rank
						j++;
				rank[sa[i]]=j;
		}

		//caculate sa and rank when pow<<1 using lstrank and lstsa
		for(pow=1;pow<=n;pow<<=1)//pow<<1
		{
				memcpy(lstsa,sa,sizeof(int)*n);
				memcpy(lstrank,rank,sizeof(int)*n);
				qsort(sa,n,sizeof(int),cmp2);
				for(i=1,j=0;i<=n;i++)
				{
						if(i==1 || cmp2(&sa[i],&sa[i-1])!=0)
								j++;
						rank[sa[i]]=j;
				}
		}
}
//cal the LCS between rank-adjacent suff
//h[i] is the LCS between suff(sa[i]) and suff(sa[i-1])
//h[rank[i]] is the LCS between suff(i) and suff(sa[[rank[i]-1])
//h[rank[i]]>=h[rank[i-1]]-1
//that means "the LCS between the suff(i) and suff(sa[rank[i]-1])" is at least "the LCS between the suff(i-1) and suff(sa[rank[i]-1])-1"
//so to calculate h[rank[i]], firstly calculate h[rank[i-1]] 
void cal_height(int n )
{
	int i=0,j=0,k=0;
	for(i=1;i<=n;i++)
	{
			if(rank[i]==1)
			{
					h[rank[i]]=k=0;
			}
			else
			{
					if(k>0) k--;//sub the first 'char' of suff(i-1) is the suff(i)
					j = sa[rank[i]-1];
					for(;m[i+k]==m[j+k];k++);//start from k, the cmp before k has been done when calculating h[rank[i-1]]
					h[rank[i]] = k;
			}
	}	
}
/*
*判断是，根据排好序的后缀，根据不同的“后缀的前缀”，sa分成多个组，每个组内都可能出现重复“前缀”，于是判断每个组长度为len重复出现的次数。当遇到一个新的组时，令c=1,重新开始。
例如:12323231,当n=8,k=2，len=2时，
1
1 2 3 2 3 2 3 1

2 3 1
2 3 2 3 1
2 3 2 3 2 3 1

3 1 
3 2 3 1
3 2 3 2 3 1
上述就可以分为三组，其中第二组和第三组中都出现了符合条件的重复串。
*/
//k表示次数，len表示当前测试长度


int check()
{
	int i,c=0;

	for(i=1;i<=n;i++)
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
	int k;
//	freopen("check.txt","r",stdin);
   // freopen("ans.txt","w",stdout);
	while(EOF!=scanf("%d %d",&n,&k))
    { 

	int i = 0;
	memset(sa,0,sizeof(sa));
	memset(rank,0,sizeof(rank));
	memset(lstsa,0,sizeof(lstsa));
	memset(lstrank,0,sizeof(lstrank));
	memset(h,0,sizeof(h));
	memset(m,0,sizeof(m));
	for(i=1;i<=n;i++)
			scanf("%d",&m[i]);
	suffix_array(n);
	cal_height(n);
	op=k;
	solve();
	
}
	return 0;
}


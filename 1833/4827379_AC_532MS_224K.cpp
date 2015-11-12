#include <vector>
#include <algorithm>
#include<stdio.h>
using namespace std ;
int t,n,k,value;
int main()
{
    scanf("%d",&t);
	while(t--)
	{
	 vector< int > ivec;
	 scanf("%d%d",&n,&k);
	 while(n--)
	 {
	   scanf("%d",&value);
       ivec.push_back(value);
	 } 
	 vector< int > ::iterator start=ivec.begin(),end=ivec.end(),it;
	 while(k--)
	 {
	   next_permutation(start, end);
	 }
	 end=end-1;
	 for(it = start; it != end; it++)
        printf("%d ",*it);
	 printf("%d\n",*it);
	}
	return 0;
}
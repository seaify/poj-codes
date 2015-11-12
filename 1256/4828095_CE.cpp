#include <algorithm>
#include<stdio.h>
using namespace std ;
int n,t;
char x[20];
int cmp(char a,char b)
{
  if(tolower(a)==tolower(b))
	  return  a<b;
  return tolower(a)<tolower(b);
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
	scanf("%s",x);
	n=strlen(x);
	sort(x,x+n);
	printf("%s\n",x);
	while(next_permutation(x,x+n,cmp))
	{
	  printf("%s\n",x);
	}
  }
  return 0;
}


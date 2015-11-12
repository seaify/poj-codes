#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int s[100002],n,i;
 
 int cmp(const void *a, const void *b)
 {
      return(*(int *)a-*(int *)b);
 }
 
 int main()
 {
	 char str[4];
      scanf("%d",&n);
      for(i=1;i<=n;i++)	
		  scanf("%d",&s[i]); 
	 qsort(s+1,n,sizeof(s[1]),cmp);
	 scanf("%s",str);
	 scanf("%d",&n); 
     while(n--)
	  {
		  scanf("%d",&i);
		  printf("%d\n",s[i]);
	  }
     
      return(0);
 }

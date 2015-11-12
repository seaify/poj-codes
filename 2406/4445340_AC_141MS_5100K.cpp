#include<stdio.h>
#include<string.h>
const int max=1000002;
int m,next[max],k;
char s[max];
int init()
{
  int i=1,j=0;next[1]=0;
  while(i<=m)
  {
   if(j==0||s[i]==s[j])
   {
    ++i;
    ++j;
    if(s[i]!=s[j])
     next[i]=j;
    else
     next[i]=next[j];
   }
   else
    j=next[j];
  }
  return next[m+1]-1;
}
int main()
{
while(EOF!=scanf("%s",s+1))
{   
   m=strlen(s+1);
   if(m==1&&s[1]=='.')
	   break;
   k=init();
   if(m%(m-k)==0)
	   printf("%d\n",m/(m-k));
   else
	   printf("1\n");
}
return 0;
}

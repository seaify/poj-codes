#include<stdio.h>
#include<string.h>
const int max=1000002;
int next[max];
char s[max];
int main()
{
int n,k,i,j,c,t;
t=1;
 while(EOF!=scanf("%d",&n)&&n)
 {   
   scanf("%s",s+1);
   printf("Test case #%d\n",t++);
   i=1;j=0;next[1]=0;
   for(k=2;k<=n;k++)
   {
	//flag=true;
	while(i<=k)
   {
    if(j==0||s[i]==s[j])
    {
    ++i;
    ++j; 
	if(i==k+1)
		 c=j;
    else if(s[i]!=s[j])
        next[i]=j;
    else
     next[i]=next[j];
    }
    else
      j=next[j]; 
   }

   c--;
   if(c&&(k%(k-c)==0))
	   printf("%d %d\n",k,k/(k-c));
   }
   printf("\n");
 }
return 0;
}



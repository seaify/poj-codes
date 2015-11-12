#include<stdio.h>
#include<string.h>
const int maxn=1000005;
int next[maxn];
char s[maxn],x[maxn];
int main()
{
int n,k,i,j,c,t,temp;
t=1;
 while(EOF!=scanf("%d",&n)&&n)
 {   
   memset(s,0,sizeof(s));
   memset(x,0,sizeof(s));
   scanf("%s",s+1);
   printf("Test case #%d\n",t++);
   x[1]=s[1];i=1;j=0;next[1]=0;
   for(k=2;k<=n;k++)
   {
   x[k]=s[k];
   while(i<=k)
   {
    if(j==0||x[i]==x[j])
    {
    ++i;
    ++j; 
    if(x[i]!=x[j])
        next[i]=j;
    else
        next[i]=next[j];
    }
    else
       j=next[j]; 
	if(i==k)
	{
	   temp=j;
	}		
   }
   i--;j=temp;
   c=next[k+1]-1;
   if(c&&(k%(k-c)==0))
	   printf("%d %d\n",k,k/(k-c));
   }
   printf("\n");
 }
return 0;
}



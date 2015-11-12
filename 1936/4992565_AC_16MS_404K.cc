#include<stdio.h>
#include<string.h>
char a[110000],b[110000];
int i,n,flag,m,j;
int main()
{
    while(EOF!=scanf("%s%s",a+1,b+1))
    {
       n=strlen(a+1);
       m=strlen(b+1);
       j=1;
       for(i=1;i<=m;++i)
       {
          if(b[i]==a[j])
              ++j;
       } 
       if(j==n+1)
          printf("Yes\n");
       else
          printf("No\n"); 
    }
    return 0;
}

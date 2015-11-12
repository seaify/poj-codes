#include<stdio.h>
#include<string.h>
int main()
{
long i,k,base[35],sum;
char skew[35];
base[0]=1;
for(i=1;i<31;i++)
base[i]=2*base[i-1]+1;
while(1)
{
scanf("%s",skew);
if(strcmp(skew,"0")==0)
break;
sum=0;
k=strlen(skew);
for(i=0;i<strlen(skew);i++)
{
k--;
sum+=(skew[i]-'0')*base[k];
}
printf("%ld\n",sum);
}
return 0;
}
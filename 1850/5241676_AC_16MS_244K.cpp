#include<stdio.h>
#include<string.h>
int f[100][100],sum[100],a[100];
char temp[100];
int i,j,k,n,flag,last;
void init()
{
	memset(f,0,sizeof(f));
	memset(sum,0,sizeof(sum));
	for(i=1;i<=26;++i)
		f[i][1]=1;
	for(j=2;j<=10;++j)
		for(i=1;i<=27-j;++i)
			for(k=i+1;k<=28-j;++k)
				f[i][j]+=f[k][j-1];
	for(j=1;j<=10;++j)
		for(i=1;i<=27-j;++i)
			sum[j]+=f[i][j];
}
int main()
{
   init();
   while(EOF!=scanf("%s",temp))//假设没有空格。。
   {
	   n=strlen(temp); 
	   flag=1;
	   for(i=0;i<n;++i)
	   {
		   a[i+1]=temp[i]-'a'+1;
		   if(temp[i]<'a'||temp[i]>'z')
			   flag=0;
	   }
	   for(i=1;i<n;++i)
		   if(a[i+1]-a[i]<=0)
		   {
			   flag=0;
			   break;
		   }
	   if(flag==0)
	   {
		   printf("0\n");
		   continue;
	   }
	   last=1;
	   for(i=1;i<n;++i)
		   last+=sum[i];
	   for(i=1;i<=n;++i)
		   for(j=a[i-1]+1;j<=a[i]-1;++j)
			   last+=f[j][n-i+1];
		printf("%d\n",last);
   }
   return 0;
}
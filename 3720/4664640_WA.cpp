#include<stdio.h>
#include<string.h>
bool flag[1000];
int count[110][11],sum[110][11],stack[110];
void divide(int n)
{
  int i,k,top;
  memset(flag,false,sizeof(flag));
  top=0;k=1;
  while(10*k<n)
 {
   stack[++top]=0;
   k=k*10;
   flag[k]=true;
 }
  k=10*k;
  flag[1]=true;
 while(1)
 { 
  stack[++top]=k/n;
   k=k%n;
   flag[k]=true;
   if(flag[k])
	 break;
   k=k*10;
  }
  for(i=1;i<=top;i++)//只计算了1次
	  count[n][stack[i]]++;
}
void init()
{
 int i,j,c;
 memset(count,0,sizeof(count));
 memset(sum,0,sizeof(sum));
 for(i=2;i<=100;i++)
 {
	j=i;c=0;
	while(j%2==0)
	{
		j=j/2;
        c++;
	}
	while(j%5==0)
	{
		j=j/5;
		c--;
	}
	if(j==1)//如果只含约数2和5
	{
	  if(c>0)
	    count[i][5]=1;
	  else if(c==0)
		count[i][1]=1;
	  else
		count[i][2]=1;
	}
	else
		divide(i);
 }
 for(j=0;j<=9;j++)
	 sum[2][j]=count[2][j];
 for(i=3;i<=100;i++)
  for(j=0;j<=9;j++)
	sum[i][j]=sum[i-1][j]+count[i][j];
}
int main()
{
 int x,y;
 init();
 while(EOF!=scanf("%d%d",&x,&y))
 {
  printf("%d\n",sum[x][y]);
 }
 return 0;
}
#include<stdio.h>
#include<string.h>
bool flag[1000];
int count[110][11],sum[110][11],stack[110];
void divide(int n)
{
  int i,k,top;
  memset(flag,false,sizeof(flag));
  top=-1;k=1;
  while(1)
  { 
   stack[++top]=k/n;
   k=k%n;
   if(k==0||flag[k])
	 break;
   flag[k]=true;
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
    divide(i);
 for(j=0;j<=9;j++)
	 sum[2][j]=count[2][j];
 for(i=3;i<=100;i++)
 {
  for(j=0;j<=9;j++)
  {
	  sum[i][j]=sum[i-1][j]+count[i][j];
  }
 }
}
int main()
{
 int x,y,i;
 init();
 while(EOF!=scanf("%d%d",&x,&y))
 {
   printf("%d\n",sum[x][y]);
 }
 return 0;
}
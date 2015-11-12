#include<stdio.h>
#include<string.h>
#include<math.h>
int sum[10][10],f[18][10][10][10][10],i,j,k;
int a[10][10],b,c;
double cnt;
int count(int x0,int y0,int x1,int y1)
{
 int temp;
 temp=sum[x1][y1]-sum[x1][y0-1]-sum[x0-1][y1]+sum[x0-1][y0-1];
 temp=temp*temp;
 return temp;
}
int main()
{
 int temp,min;
 int x1,x2,y1,y2,n;
 scanf("%d",&n);
 for(i=1;i<=8;i++)
  for(j=1;j<=8;j++)
	  scanf("%d",&a[i][j]);
 memset(sum,0,sizeof(sum));
 for(i=1;i<=8;i++)
 {
   for(j=1;j<=8;j++)
   {
	   sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
	 
   }
 
 }
 for(x1=1;x1<=8;x1++)
	for(y1=1;y1<=8;y1++)
		for(x2=x1;x2<=8;x2++)
			for(y2=y1;y2<=8;y2++)
				f[0][x1][y1][x2][y2]=count(x1,y1,x2,y2);
 for(k=1;k<n;k++)
for(x1=1;x1<=8;x1++)
for(y1=1;y1<=8;y1++)
for(x2=x1;x2<=8;x2++)
for(y2=y1;y2<=8;y2++)
	{
     min=10000000;
	for(c=x1;c<x2;c++)
		{
		 temp=f[k-1][x1][y1][c][y2]+count(c+1,y1,x2,y2);
		 if(f[k-1][c+1][y1][x2][y2]+count(x1,y1,c,y2)<temp)
			 temp=f[k-1][c+1][y1][x2][y2]+count(x1,y1,c,y2);
		 if(temp<min)
			 min=temp;
		}
	for(b=y1;b<y2;b++)
	{
	  temp=f[k-1][x1][y1][x2][b]+count(x1,b+1,x2,y2);
	  if(f[k-1][x1][b+1][x2][y2]+count(x1,y1,x2,b)<temp)
		  temp=f[k-1][x1][b+1][x2][y2]+count(x1,y1,x2,b);
	  if(temp<min)
		  min=temp;
	}
	f[k][x1][y1][x2][y2]=min;
}
  cnt=sqrt(double(f[n-1][1][1][8][8]/double(n))-double((sum[8][8]/double(n)))*double((sum[8][8]/double(n))));
  printf("%.3lf\n",cnt);
 return 0;
}
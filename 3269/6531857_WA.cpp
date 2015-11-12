#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int sumx[11000],sumy[11000];

struct node
{
	int x,y;
};
node a[11000],b[11000];

int cmp1(node a,node b)
{
	return a.x<b.x;
}

int cmp2(node a,node b)
{
	return a.y<b.y;
}

int check(int x1,int x2,int y1,int y2)
{
	int i,sum;
	for(i=0;i<n&&a[i].x<=x2;i++)
	{
		if(a[i].x>=x1&&a[i].y>=y1&&a[i].y<=y2)
			sum++;
	}
	return sum;
}

int main()
{
	int i,c,num,result;
	while(EOF!=scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a[i].x,&a[i].y);
			b[i]=a[i];
		}
		sort(a,a+n,cmp1);
		sort(b,b+n,cmp2);
		sumx[0]=a[0].x;sumy[0]=b[0].y;
		for(i=1;i<n;i++)
			sumx[i]=sumx[i-1]+a[i].x,sumy[i]=sumy[i-1]+b[i].y;

		if(n&1)
		{
			c=(n+1)/2;
			num=check(a[c].x,a[c].x,b[c].y,b[c].y);
			result=(c-1)*a[c].x-sumx[c-1]+(sumx[n-1]-sumx[c]-(n-c)*a[c].x);
			result+=(c-1)*b[c].y-sumy[c-1]+(sumy[n-1]-sumy[c]-(n-c)*b[c].y);
			if(num)
				printf("%d 4\n",result);
			else
				printf("%d 1\n",result);
		}
		else
		{
			c=n/2;
            num=-check(a[c].x,a[c+1].x,b[c].y,b[c+1].y);
			num+=(a[c+1].x-a[c].x+1)*(b[c+1].y-b[c].y+1);
			result=(c-1)*a[c].x-sumx[c-1]+(sumx[n-1]-sumx[c]-(n-c)*a[c].x);
			result+=(c-1)*b[c].y-sumy[c-1]+(sumy[n-1]-sumy[c]-(n-c)*b[c].y);
			printf("%d %d\n",result,num);
		}
	}
	return 0;
}
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
	int i,sum=0;
	for(i=0;i<n&&a[i].x<=x2;i++)
	{
		if(a[i].x>=x1&&a[i].y>=y1&&a[i].y<=y2)
			sum++;
	}
	return sum;
}

int cost(int x,int y)
{
	int i,sum=0;
	for(i=0;i<n;i++)
		sum+=abs(x-a[i].x)+abs(y-b[i].y);
	return sum;
}

int main()
{
	int i,c,num,result;
	int v[10];

	//freopen("data","r",stdin);


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
		{
			sumx[i]=sumx[i-1]+a[i].x,sumy[i]=sumy[i-1]+b[i].y;
           // printf("%d %d\n",sumx[i],sumy[i]);
		}
		if(n&1)
		{
			c=(n+1)/2-1;
			num=check(a[c].x,a[c].x,b[c].y,b[c].y);
			result=cost(a[c].x,b[c].y);
			if(num)
			{
				v[0]=cost(a[c].x,b[c].y-1);
				v[1]=cost(a[c].x,b[c].y+1);
				v[2]=cost(a[c].x-1,b[c].y);
				v[3]=cost(a[c].x+1,b[c].y);

				for(i=0;i<4;i++)
					if(i==0||v[i]<c)
						c=v[i],num=1;
                    else if(v[i]==c)
						num++;

				printf("%d %d\n",result,num);
			}
			else
				printf("%d 1\n",result);
		}
		else
		{
			c=n/2-1;
            num=-check(a[c].x,a[c+1].x,b[c].y,b[c+1].y);
			num+=(a[c+1].x-a[c].x+1)*(b[c+1].y-b[c].y+1);
			
		    result=cost(a[c].x,b[c].y);

			printf("%d %d\n",result,num);
		}
	}
	return 0;
}
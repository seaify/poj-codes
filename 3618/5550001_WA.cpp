#include<stdio.h>
#include<algorithm>
using namespace std;
int a[51000],b[51000];
int left1,right1,left2,right2,cnt,N,T,sum;

int cmp(int a, int b)
{
	return a>b;
}

int get_min()
{
	int ans;
	if(left1>right1)
	{
		ans=abs(b[left2]-cnt);
		cnt=b[left2];
		++left2;
	}
	else if(left2>right2)
	{
		ans=abs(a[left1]-cnt);
		cnt=a[left1];
		++left1;
	}
	else if(abs(a[left1]-cnt)<abs(b[left2]-cnt))
	{
		ans=abs(a[left1]-cnt);
		cnt=a[left1];
		++left1;
	}
	else
	{
		ans=abs(b[left2]-cnt);
		cnt=b[left2];
		++left2;
	}
	return ans;
}

int main()
{
    int i,x;
	while(EOF!=scanf("%d %d",&T,&N))
	{
		left1=1;
		right1=0;
		left2=1;
		right2=0;
		sum=0;
		for(i=1;i<=N;++i)
		{
			scanf("%d",&x);
			if(x>0)
				a[++right1]=x;
			else if(x<0)
				b[++right2]=x;
			else
				++sum;
		}	
		if(right1>=1)
		     sort(a+1,a+right1+1);
		if(right2>=1)
		     sort(b+1,b+right2+1,cmp);
		cnt=0;
		while(T>0)
		{ 
			if(left1>right1&&left2>right2)
				break;
			x=get_min();
			if(T>=x)
			{
				sum++;
				T-=x;
			}
			else 
				break;
		}
		printf("%d\n",sum);
	}
	return 0;
}

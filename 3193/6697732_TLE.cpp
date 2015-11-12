#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string line;
vector<string> H;
vector<string>::iterator it;

int M,N,sum;

void check(string a)
{
	int left=0,right=M-1,mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a.compare(H[mid])>0)
			right=mid-1;
		else if(a.compare(H[mid])==0)
		{
			sum++;
			return ;
		}
		else
		{
			if(a.compare(0,a.size(),H[mid])==0)
			{
				sum++;
				return ;
			}
			else
				left=mid+1;
		}

	}
}

int main()
{
	int i;
	while(EOF!=scanf("%d %d",&M,&N))
	{
		H.clear();
		for(i=0;i<M;i++)
		{
			getline(cin,line);
			H.push_back(line);
		}
		sort(H.begin(),H.end());
	//	for(it=H.begin();it!=H.end();it++)
	//		cout<<*it<<endl;
		sum=0;
		while(N--)
		{
			getline(cin,line);
			check(line);
		}
		printf("%d\n",sum);
	}
}
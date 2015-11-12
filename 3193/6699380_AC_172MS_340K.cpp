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
			left=mid+1;
		else if(a.compare(H[mid])==0)
		{
			sum++;
			return ;
		}
		else
		{
			if(a.size()<H[mid].size())
			{
				if(H[mid].compare(0,a.size(),a)==0)
				{
					sum++;
					return ;
				}
			}
			right=mid-1;
		}
	}
}

int main()
{
	int i;
	while(EOF!=scanf("%d %d",&M,&N))
	{
		getchar();
		H.clear();
		H.resize(M);
		for(i=0;i<M;i++)
		{
			getline(cin,line);
//			cout<<line<<endl;
			H[i]=line;
		}
		sort(H.begin(),H.end());
		sum=0;
		while(N--)
		{
			getline(cin,line);
		//	cout<<line<<endl;
			check(line);
		}
		printf("%d\n",sum);
	}
}
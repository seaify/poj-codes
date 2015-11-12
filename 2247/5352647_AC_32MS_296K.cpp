#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string s;
int x[10000],a,b,c,d,i,n;

int minv(int a,int b,int c,int d)
{
	if(b<a)
		a=b;
	if(c<a)
		a=c;
	if(d<a)
		a=d;
	return a;
}
int main()
{
	x[1]=1;
	a=1,b=1,c=1,d=1;
	for(i=2;i<=5842;++i)
	{
        x[i]=minv(x[a]*2,x[b]*3,x[c]*5,x[d]*7);
		if(x[i]==x[a]*2)
				++a;
		if(x[i]==x[b]*3)
				++b;
		if(x[i]==x[c]*5)
				++c;
		if(x[i]==x[d]*7)
			    ++d;
	}
	while(EOF!=scanf("%d",&n))
	{
		if(n==0)
			break;
		if(n%10==1&&n%100!=11)
            s="st";
            else if(n%10==2&&n%100!=12)
            s="nd";
            else if(n%10==3&&n%100!=13)
            s="rd";
            else s="th";           
      cout<<"The "<<n<<s<<" humble number is "<<x[n]<<"."<<endl;
	}
	return 0;
}

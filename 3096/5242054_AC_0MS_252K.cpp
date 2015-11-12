#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
set <string> temp;
string a;
int solve()
{
	int i,j,n;
	string c(2,'0');
	n=a.size();
	for(i=1;i<n-1;++i)
	{
	   temp.clear();
	   for(j=0;j<=n-1-i;++j)
	   {
          c[0]=a[j],c[1]=a[i+j];
		  if(temp.count(c))
			  return 0;
		  temp.insert(c);
	   }
	}
	return 1;
}
int main()
{
	while(cin>>a)
	{
		if(a[0]=='*'&&a.size()==1)
			break;//vAAB is surprising.
//		AABB is NOT surprising.
		if(solve())
			cout<<a<<" "<<"is surprising."<<endl;
		else
			cout<<a<<" "<<"is NOT surprising."<<endl;
	}
	return 0;
}
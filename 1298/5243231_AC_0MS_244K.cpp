#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string test,word;
int i,n;
int main()
{
	while(cin>>test)
	{
		if(test=="ENDOFINPUT")
		    break;
		getchar();
		getline(cin,word);
		cin>>test;
		n=word.size();
		for(i=0;i<n;++i)
		{
			if(isupper(word[i]))
				word[i]=(word[i]-'A'+21)%26+'A';
			cout<<word[i];
		}
		cout<<endl;
	}
	return 0;
}
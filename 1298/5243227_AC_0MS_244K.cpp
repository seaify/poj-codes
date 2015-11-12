#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int i,n;
char test[1000],word[1000];
int main()
{
	while(EOF!=scanf("%s",test))
	{
		if(strcmp(test,"ENDOFINPUT")==0)
			break;
		getchar();
		gets(word);
	//	cin.clear();
	//	cin>>test;
		scanf("%s",test);
		n=strlen(word);
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
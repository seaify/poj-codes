#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;


string line,word;
int flag[400];

int main()
{
	int i,t;
    while(getline(cin,line))
    {
		  for(i='A';i<='Z';i++)
			     flag[i]=0;

		  flag['A']=1;
		  flag['E']=1;
		  flag['I']=1;
		  flag['O']=1;
		  flag['U']=1;

          for(i=0;i<line.length();i++)
			  if(line[i]!=' ')
			  {
                  if(line[i]>='A'&&line[i]<='Z')
				  {
					  if(flag[line[i]]==0)					 
						  flag[line[i]]=1; 
					  else
					  {
						  line.erase(i,1);
						  i--;
					  }
				  }
			  }

		  

		  istringstream stream(line);
		  t=1;
		  while(stream>>word)
		  {
			  if(t==1)
				  cout<<word;
			  else
			  {
			     if(word[0]>='A'&&word[0]<='Z')
				 {
				     cout<<" "<<word;
				 }
				 else
					 cout<<word;
			  }
			  t++;
		  }
		  cout<<endl;
    }
    
    return 0;
    
} 
 

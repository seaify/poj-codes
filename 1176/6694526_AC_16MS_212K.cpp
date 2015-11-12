#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

set<string> H;
set<string>::iterator it;

int N,C,op[1000],check[1000];

int main()
{
	int i,j,k,x,num;
	while(EOF!=scanf("%d %d",&N,&C))
	{
		for(i=1;i<=N;i++)
			check[i]=2;

		while(1)    //下标偏移1
		{
			scanf("%d",&x);  
			if(x==-1)
				break;
			check[x]=1;  //为1
		}
		while(1)
		{
			scanf("%d",&x);
			if(x==-1)
				break;
			check[x]=0;
		}

		H.clear();

        for(i=0;i<16;i++)
		{
			for(j=1;j<=N;j++)
				op[j]=1;

			num=0;
			for(j=0;j<4;j++)
				if(i&(1<<j))
				{
					++num;
					for(k=1;k<=N;k++)
						if(j==0)
							op[k]^=1;
					    else if(j==1&&(k&1))
							op[k]^=1;
					    else if(j==2&&(k&1)==0)
							op[k]^=1;
					    else if(j==3&&(k%3)==1)
							op[k]^=1;

            
			   }
		   if(C<num)
			   continue;
		   if((C&1)!=(num&1))
			   continue;
		   string word;
		   for(j=1;j<=N;j++)
			   if(check[j]==2||check[j]==op[j])
				   word+='0'+op[j];
		       else
				   break;

		   if(j==N+1)
			   H.insert(word);
		}

        for(it=H.begin();it!=H.end();it++)
			cout<<*it<<endl;

	}
	return 0;
}
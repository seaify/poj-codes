#include<stdio.h>
#include<string>
#include<iostream>
using std::string;
using std::cout;
using std::endl;
string map[102][102];
int i,j,k,n,p,d[102][102];
char s[102];
int main()
{
 scanf("%s",s+1);
 n=strlen(s+1);
 for(i=1;i<=n;i++)
	d[i][i-1]=0;//默认为空串
 for(i=1;i<=n;i++)
 {
	 d[i][i]=1;
	 if(s[i]=='('||s[i]==')')
		map[i][i]="()";
	 else
		map[i][i]="[]";
 }
 for(p=1;p<=n-1;p++)
  for(i=1;i<=n-p;i++)
  {
	j=i+p;string temp;
	d[i][j]=200;
	if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))
	{
		d[i][j]=d[i+1][j-1];
		temp=s[i]+map[i+1][j-1]+s[j];//可能s[i]不能与其相加
	}
	if(s[i]=='('&&d[i][j]>d[i+1][j]+1)
	{
		d[i][j]=d[i+1][j]+1;
		temp="()"+map[i+1][j];
	}
    if(s[i]=='['&&d[i][j]>d[i+1][j]+1)
	{
		d[i][j]=d[i+1][j]+1;
		temp="[]"+map[i+1][j];
	}
	if(s[j]==')'&&d[i][j]>d[i][j-1]+1)
	{
		d[i][j]=d[i][j-1]+1;
		temp=map[i][j-1]+"()";
	}
	if(s[j]==']'&&d[i][j]>d[i][j-1]+1)
	{
		d[i][j]=d[i][j-1]+1;
		temp=map[i][j-1]+"[]";
	}
	for(k=i;k<j;k++)
	   if(d[i][j]>d[i][k]+d[k+1][j])
	   {
		   d[i][j]=d[i][k]+d[k+1][j];
		   temp=map[i][k]+map[k+1][j];
	   }
	map[i][j]=temp;
  }
  cout<<map[1][n]<<endl;
 return 0;
}
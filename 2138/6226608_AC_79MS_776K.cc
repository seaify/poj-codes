#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string x[1100],tmp;
vector < int > v[1100];

char ch1[100],ch2[100];
int n,top,ans,big;

int cmp(string a,string b)
{
    return a.size()<b.size(); 
}

int test(string &a,string &b)
{
    int i=0,j=0;
    while(i<a.size()&&j<b.size())
    {
          if(a[i]==b[j])
              i++,j++;
          else
              j++;
    }
    if(i==a.size())
          return 1;
    return 0;
}

void dfs(int x,int depth)
{
     int i;
     if(v[x].size()==0&&depth>ans)
             ans=depth,big=x;
     for(i=0;i<v[x].size();i++)
           dfs(v[x][i],depth+1);
}



int main()
{
    int i,j,flag,c;
    
    while(EOF!=scanf("%d %s",&n,ch1))
    {
          string Q(ch1);
          top=-1;
          for(i=0;i<n;i++)
          {
              scanf("%s",ch2);
              string qq(ch2);
              if(qq.size()>=4||(qq.size()==3&&qq==Q))
                     x[++top]=qq;
          }
          
          sort(x,x+top+1,cmp);  ////top个元素..... 
          for(i=0;i<=top;i++)
              v[i].clear();
          
		  for(i=0;i<top;i++)
			  for(j=i+1;j<=top;j++)
			  {
                  if(x[j].size()>x[i].size()+1)
                       break;
                  if(x[j].size()==x[i].size())
                       continue;
				  if(test(x[i],x[j]))
					  v[i].push_back(j);
              }
              
          ans=-1;
              
          dfs(0,1);
          
          cout<<x[big]<<endl;
				  
          
    } 
    return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

int x[30];
int n,ans,size;

void dfs(int i,int sum)
{
    if(i==n||sum>=ans)
    {
       if(sum>=ans&&sum-ans<size)
          size=sum-ans;
       return ;
    } 
    dfs(i+1,sum+x[i]);
    dfs(i+1,sum);
}

int main()
{
    int i;
    
    while(EOF!=scanf("%d %d",&n,&ans))
    {
          for(i=0;i<n;i++)
             scanf("%d",&x[i]);
             
          size=30000000;
          dfs(0,0);
          
          printf("%d\n",size);    
    }
}

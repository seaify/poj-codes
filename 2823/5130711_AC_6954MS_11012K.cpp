#include<stdio.h>
#include<deque>
using namespace std;
const int maxn=1000005;
int a[maxn],N,K,l[maxn],r[maxn],ls,rs;  
deque < int > c,d;
void solve(int cur)
{
   int v,t,c1,d1;
   t=a[cur];
   while(!c.empty())
   {
	 v=a[c.back()];
     if(v<=t) 
        c.pop_back();
      else
        break;
   }
   c.push_back(cur);
   c1=c.front();
   if(cur-c.front()>=K)
       c.pop_front();
   if(cur>=K)
       r[++rs]=c.front();
   while(!d.empty())
   {
	  v=a[d.back()];
      if(v>=t)
        d.pop_back();
      else
        break;
   }
   d.push_back(cur);
   d1=d.front();
   if(cur-d.front()>=K)
       d.pop_front();
   if(cur>=K)
       l[++ls]=d.front();
}
int main()
{

   int i;
   while(EOF!=scanf("%d %d",&N,&K))
   {
       for(i=1;i<=N;++i)
          scanf("%d",&a[i]);
       c.clear();d.clear();
       ls=0;rs=0;
       for(i=1;i<=N;++i)
           solve(i);
       for(i=1;i<ls;++i)
           printf("%d ",a[l[i]]);
       printf("%d\n",a[l[ls]]);
       for(i=1;i<rs;++i)
           printf("%d ",a[r[i]]);
       printf("%d\n",a[r[rs]]);
   }
   return 0;
}

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
 void put(int x){
	if(x< 0){
		putchar('-');
		x = -x;
	}
	if(x == 0){
		putchar('0');
		return;
	}
	char s[20];
	int bas = 0;
	for(;x;x/=10)s[bas++] = x%10+'0';
	for(;bas--;)putchar(s[bas]);
	return;
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
	   {
           put(a[l[i]]);
		   printf(" ");
	   }
       put(a[l[ls]]);
	   printf("\n");
       for(i=1;i<rs;++i)
	   {
           put(a[r[i]]);
		   printf(" ");
	   }
       put(a[r[rs]]);
	   printf("\n");
   }
   return 0;
}

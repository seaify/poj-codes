#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=30000;
int a[300],c[300];
char ch[maxn];
int main()
{
 int i,x,out,len,sum;
 double last;
 while(EOF!=scanf("%s",ch))
 {
   if(strcmp(ch,"END")==0)
	   break;
   priority_queue < int > q;
   len=strlen(ch);sum=8*len;
   memset(c,0,sizeof(c));
   for(i=0;i<len;++i)
	   ++c[ch[i]];
   for(i=0;i<300;++i)
	   if(c[i])
		  q.push(-c[i]);
   if(q.size()==1)
   {
	   printf("%d %d 8.0\n",sum,len);
	   continue;
   }
   out=0;
   while(q.size()>1)
   {
	   x=-q.top();
	   q.pop();
	   x+=-q.top();
	   q.pop();
	   out+=x;
	   q.push(-x); 
   }
   last=double(sum)/double(out);
   printf("%d %d %.1lf\n",sum,out,last);
 }
return 0;
}




#include<stdio.h>
#include<queue>
using namespace std;
int i,n1,n2,value,n;
priority_queue < int > a,b;
__int64 sum;
int main()
{
   double cnt;
   while(EOF!=scanf("%d %d %d",&n1,&n2,&n))
   {
	  sum=0;
	  if(n1==0&&n2==0&&n==0)//每运行1次时,队列都清空了的。。
		   break;
      for(i=1;i<=n;++i)//a为较大堆，b较小堆。。
	  {
		 scanf("%d",&value);
		 sum+=value;
		 a.push(-value);//存储负值时越大越在队尾。。
		 if(a.size()>n1)
			 a.pop();
		 b.push(value);
		 if(b.size()>n2)
			 b.pop();
	  }
	  while(!a.empty())
	  {
		  sum+=a.top();
		  a.pop();
	  }
	  while(!b.empty())
	  {
		  sum-=b.top();
		  b.pop();
	  }
	  n=n-n1-n2;
      cnt=double(sum*1.0)/double(n);
	  printf("%.6lf\n",cnt);
   }
   return 0;
}
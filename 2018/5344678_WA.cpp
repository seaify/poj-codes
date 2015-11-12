#include<cstdio>
#include<deque>
using namespace std;
int a[110000],sum[110000],N,F,i,opt,last;

struct node
{
	int x,y;
};
node cnt,s,t;
deque < node > q;

int test()
{
	int v;
	if(q.size()<2)
		return 0;
	t=q.front();
	q.pop_front();
	s=q.front();
	v=(t.x-s.x)*(cnt.y-s.y)-(cnt.x-s.x)*(t.y-s.y);
	if(v>0)
	{
		q.push_front(t);
		return 0;
	}
	return 1;
}
int main()
{
	while(EOF!=scanf("%d %d",&N,&F))
	{
		sum[0]=0;opt=0;
		for(i=1;i<=N;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]>opt)
				opt=a[i];
			sum[i]=sum[i-1]+a[i];
		}
		if(F==1)
		{
			printf("%d\n",1000*opt);
			continue;
		}
		cnt.x=0,cnt.y=0;
		q.push_front(cnt);
		cnt.x=1,cnt.y=sum[1];
		q.push_front(cnt);
		opt=(1000*sum[F])/F;
		if((1000*sum[F+1])/(F+1)>opt)
			opt=(1000*sum[F+1])/(F+1);
	    if((1000*(sum[F+1]-sum[1]))/F>opt)
			opt=(1000*(sum[F+1]-sum[1]))/F;
		for(i=F+2;i<=N;++i)
		{
		    cnt.x=i-F,cnt.y=sum[i-F];
			while(test());
			q.push_front(cnt);
			s=q.back();q.pop_back();
			cnt.x=i,cnt.y=sum[i];//寻找最优值。。。。
			last=(1000*(cnt.y-s.y))/(cnt.x-s.x);
			while(!q.empty())
			{
               t=q.back();
			   if((1000*(cnt.y-t.y))/(cnt.x-t.x)>last)
				   last=(1000*(cnt.y-t.y))/(cnt.x-t.x),q.pop_back(),s=t;
			   else
			   {
				   q.push_back(s);
				   break;
			   }
			}
			if(last>opt)
				opt=last;
		}
		printf("%d\n",opt);
	}
	return 0;
}
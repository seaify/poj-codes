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
	if(q.size()<2)  ///没有点可以出队列了。。。
		return 0;
	t=q.front();
	q.pop_front();
	s=q.front();
	v=(t.x-s.x)*(cnt.y-s.y)-(cnt.x-s.x)*(t.y-s.y);
	if(v>=0)
	{
		q.push_front(t);
		return 0;
	}
	return 1;
}
int main()
{
	//freopen("in.txt","r",stdin);
//	freopen("out1.txt","w+",stdout);
//	int T=0;
	while(EOF!=scanf("%d %d",&N,&F))
	{
		q.clear();
		sum[0]=0;opt=0;
		for(i=1;i<=N;++i)
		{
			scanf("%d",&a[i]);
			a[i]=a[i]*1000;
			if(a[i]>opt)
				opt=a[i];
			sum[i]=sum[i-1]+a[i];
		}
		if(F==N)
		{
			printf("%d\n",sum[N]/N);
			continue;
		}
		if(F==1) //////故N>=2
		{
			printf("%d\n",opt);
			continue;
		}
		cnt.x=0,cnt.y=0;
		q.push_front(cnt);
		opt=sum[F]/F;
		cnt.x=1,cnt.y=sum[1];
		q.push_front(cnt);
		if(sum[F+1]/(F+1)>opt)
			opt=sum[F+1]/(F+1);
	    if((sum[F+1]-sum[1])/F>opt)
			opt=(sum[F+1]-sum[1])/F; /////为判断出单调性，必须先压入2个点。。。
		for(i=F+2;i<=N;++i)
		{
		    cnt.x=i-F,cnt.y=sum[i-F];  ///可能压入的点
			while(test());
			q.push_front(cnt);
			cnt.x=i,cnt.y=sum[i];//寻找最优值。。。。
		    last=0;
			if(q.size()==1)
			{
				last=(cnt.y-q.back().y)/(cnt.x-q.back().x);
				continue;
			}
			t=q.back();    ////此时必存在2个元素
			q.pop_back();
			s=q.back();
			while((cnt.y-t.y)/(cnt.x-t.x)<(cnt.y-s.y)/(cnt.x-s.x))  ////保证至少2个元素...,last不断的扩大。。直到碰到一个比它小或等于的
			{
			   t=q.back();
			   q.pop_back();
			   if(q.empty())
				   break;
			   s=q.back();
			}
			q.push_back(t);
			last=(cnt.y-t.y)/(cnt.x-t.x);
			if(last>opt)
				opt=last;
		}
		printf("%d\n",opt);
	}
	return 0;
}

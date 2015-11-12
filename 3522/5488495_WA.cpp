#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,tot,p[110],num[110];
struct node
{
	int x,y,c;
};
node e[11000];

int cmp( node a,node b)
{
	return a.c<b.c;
}

void Makeset(int x)
{
	p[x]=-1;
	num[x]=1;
}

int Find(int x)
{
    int r=x,q;
	while(p[r]!=-1)  ///找到根结点....
		r=p[r];
	while(x!=r)
	{
        q=p[x];
		p[x]=r;
		x=q;
	}
	return r;
}

void Union(int a,int b)
{
	int t1,t2;
	t1=Find(a);
	t2=Find(b);
	if(t1==t2)
		return ;
	--tot;
	if(num[t2]<=num[t1])
	{
		p[t2]=t1;
		num[t1]+=num[t2];
	}
	else
	{
		p[t1]=t2;
		num[t2]+=num[t1];
	}

}
int main()
{
	int i,j,test,big,ans;
	while(EOF!=scanf("%d %d",&n,&m))
	{
		for(i=0;i<m;++i)
            scanf("%d %d %d",&e[i].x,&e[i].y,&e[i].c);
		sort(e,e+m,cmp);
		ans=1000000;
		test=0;
		for(i=0;i<=m-n+1;++i)  ///枚举下界.....
		{
			tot=n;
			for(j=1;j<=n;++j)
				Makeset(j);
			big=-1;
			for(j=i;j<m;++j) 	///可能的边,kruscal
			   if(Find(e[j].x)!=Find(e[j].y))
			   {
                   Union(e[j].x,e[j].y);
				   if(e[j].c>big)
					   big=e[j].c;
				   if(tot==1)
				   {
					   test=1;
					   big-=e[i].c;
					   break;
				   }
			   }
			if(tot==1&&big<ans)
				ans=big;
		}
		if(test)
             printf("%d\n",ans);
		else
			 printf("-1\n");
	}
	return 0;
}
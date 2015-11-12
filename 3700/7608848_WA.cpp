#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;


const __int64 maxn=210000;
const __int64 INF=2000000000;

__int64 opN,nodeX,tot,cx,q[maxn];

map<__int64,__int64> HX;
map<__int64,__int64> H;
map<__int64,__int64> ::iterator it;

struct Node
{
	char a[10];
	__int64 x,y;
};
Node op[maxn],R[maxn];

struct node
{
	__int64 a,b,ls,rs,maxv;
};
node tree[3*maxn];

int init(int a,int b)
{
	int cur=tot,mid;

	tree[cur].a=a;
	tree[cur].b=b;
	tree[cur].maxv=0;
	if(a==b)
	{
		tree[cur].ls=tree[cur].rs=-1;
		return cur;
	}
	
	mid=(a+b)/2;

	++tot;
	tree[cur].ls=init(a,mid);

	++tot;
	tree[cur].rs=init(mid+1,b);

	return cur;
}

void update(int root,int x,int v)
{
    int a,b,mid,ls,rs;

	a=tree[root].a;
	b=tree[root].b;

	if(a==b)
	{ 
		tree[root].maxv=v;
		return ;
    }

	ls=tree[root].ls;
	rs=tree[root].rs;

	mid=(a+b)/2;

	if(x<=mid)
		 update(tree[root].ls,x,v);
	else
		 update(tree[root].rs,x,v);


	if(tree[ls].maxv>tree[rs].maxv)
	     tree[root].maxv=tree[ls].maxv;
	else
		 tree[root].maxv=tree[rs].maxv;
}

void query(int root,int x,int y,int v)  //比v大
{
    int a,b,ls,rs,mid;

	if(root==-1)
		return ;

	if(cx!=-1)
		return ;

	if(tree[root].maxv<=v)
		return ;

	a=tree[root].a;
	b=tree[root].b;

	if(y<a||x>b)
		return ;

	if(a==b)
	{
		cx=a;
		return ;
	}

	ls=tree[root].ls;
	rs=tree[root].rs;
	mid=(a+b)/2;
	if(y<=mid)
		 query(ls,x,y,v);
	else if(x>mid)
		 query(rs,x,y,v);
	else
	{
		 query(ls,x,y,v);
		 query(rs,x,y,v);
	}
}

int main()
{
	__int64 i,x,y,v,tmp,W=400000*INF,T=0;

	while(EOF!=scanf("%I64d",&opN))
	{
		if(opN==0)
			break;

		HX.clear();
		nodeX=0;  ///注意X必须从1开始，和线段树保持统一..

		for(i=0;i<opN;i++)
		{
			scanf("%s %I64d %I64d",op[i].a,&op[i].x,&op[i].y);
			x=op[i].x,y=op[i].y;
			if(HX.count(x)==0)
			{
				++nodeX;
				HX[x]=nodeX;
			}
		
		}

		for(it=HX.begin(),i=1;it!=HX.end();it++,i++)
		{
		   (*it).second=i;
		   q[i]=(*it).first;
		}

        if(T)printf("\n");

	
	    printf("Case %d:\n",++T);


		H.clear();  ///存储H[X]*MAXN+Y;
		H[-1]=0; //  为保证map非空...,重要

		tot=1;
		init(1,nodeX); //建树.

		for(i=0;i<opN;i++)
		{
			x=op[i].x,y=op[i].y;
			x=HX[x];
		//	printf("%I64d\n",x);
			v=x*INF+y;
			if(op[i].a[0]=='a')  //add
			{
                H[v]=v;
		        it=H.lower_bound(x*INF+INF);
				it--;
				tmp=(*it).second-x*INF;
				update(1,x,tmp);  ///
			}
			else if(op[i].a[0]=='r')
			{
				H.erase(v);

				
				it=H.lower_bound(x*INF+INF);  ///任何时候均正确
				it--;
			//	printf("yes %d\n",(*it).second);
				tmp=(*it).second-x*INF;
				if(tmp<=0)
					 update(1,x,0);
				else
				     update(1,x,tmp);
			}
			else
			{
                cx=-1;
				query(1,x+1,nodeX,y);
				if(cx==-1)
				{
					printf("-1\n");
					continue;
				}
				v=cx*INF+y;
                it=H.upper_bound(v);  //
				tmp=(*it).second;
				printf("%I64d %I64d\n",q[tmp/INF],tmp%INF);
			}
			//debug();
		}
	
	}
	return 0;
}
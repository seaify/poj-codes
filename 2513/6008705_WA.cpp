#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=510000;
int n,tot,size,total;
int p[maxn],num[maxn],in[maxn];
char a[12],b[12];

struct tree
{
	int id;
	int node[26];
};
tree q[1000000];

void Makeset(int x)
{
     p[x]=-1;
     num[x]=1;
} 

int Find(int x)//非递归压缩路径
{
     int r=x;
     while(p[r]!=-1)//找到根结点
         r=p[r];
     while(x!=r)
      {
          int q=p[x];
          p[x]=r;
          x=q;
      }
    return r;      
}     

int Union(int a,int b)
{

    int t1,t2;
    t1=Find(a);
    t2=Find(b);
    if(t1==t2)
		  return 0;
	total--;
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
    return 0;
}


void init()
{
	int i;
	++tot;
	q[tot].id=0;
    for(i=0;i<26;i++)
		q[tot].node[i]=0;
}

int insert(int p,char *s)
{
	int c=(*s)-'a';
	if(q[p].node[c])
		p=q[p].node[c];
	else
	{
		init();
		q[p].node[c]=tot;
		p=tot;
	}

	if(s[1])
		return insert(p,s+1);
	else
	{
		if(!q[p].id)
			q[p].id=++size;
		return q[p].id;
	}
	
}

int main()
{
	int i,t1,t2,flag;
	for(i=1;i<=500000;i++)
	{
		Makeset(i);
		in[i]=0;
	}

	total=500000;

	tot=0;
	size=0;
	init();

	while(EOF!=scanf("%s %s",a,b))
	{
        t1=insert(1,a);
		t2=insert(1,b);
		Union(t1,t2);
		in[t1]++;
		in[t2]++;
	}


	if(total+size-1!=500000)
	{
		printf("Impossible\n");
		return 0;
	}

	flag=0;

	for(i=1;i<=size;i++)	
		if(in[i]%2!=0)
			flag++;


	if(flag==0||flag==2)
		printf("Possible\n");
	else
		printf("Impossible\n");

	return 0;
}
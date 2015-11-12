#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int i,j,n,m,last[10000],d[10000],f[10000],set[10000],col[10000],tot,cnt,t;
bool flag[10000],tag[5000][5000];;
vector< int > a[10000],b[10000],c[10000],e[10000];
void DFS_visit(int i)
{
  flag[i]=false;
  ++t;
  d[i]=t;
  for( int k=0;k!=a[i].size();++k)
     if(flag[a[i][k]])
         DFS_visit(a[i][k]);
  ++t;
  f[i]=t;
  last[++tot]=i;
}
void dfs(int i)
{
  flag[i]=false;
   for( int k=0;k!=b[i].size();++k)
     if(flag[b[i][k]])
         dfs(b[i][k]);
  set[i]=tot;
}
void DFS()
{
  memset(flag,true,(2*n+1)*sizeof(flag[1]));
  t=0;tot=0;
  for(i=1;i<=2*n;++i)
    if(flag[i])
        DFS_visit(i);
  memset(flag,true,(2*n+1)*sizeof(flag[1]));
  tot=0;
  for(i=2*n;i>=1;--i)
     if(flag[last[i]])
     {
       ++tot;
       dfs(last[i]);
     }       
}
int opp(int x)
{
	if(x%2==0)
		return x-1;
	return x+1;
}

void solve()
{
	int i,j,t1,t2,x,maxv;
    for(i=1;i<=n;++i)
		if(set[2*i-1]==set[2*i])
		{
			printf("bad luck\n");
			return ;
		}
                ////构造新图,并且是正图...
	memset(tag,true,sizeof(tag));
	for(i=1;i<=2*n;++i)
		c[i].clear();
	for(i=1;i<=2*n;++i)
	{
		for(j=0;j<a[i].size();++j)
		{
			t1=set[i];
			t2=set[a[i][j]];
			if(t1!=t2&&tag[t1][t2])
			{
				tag[t1][t2]=false;
                c[t1].push_back(t2);
			}
		}
	}
	for(i=1;i<=2*n;++i)
	{
		a[i].clear();
		e[i].clear();
		a[i]=c[i];
	}
	memset(flag,true,(2*n+1)*sizeof(flag[1]));  ////对该图进行拓补排序....
    t=0;maxv=tot;tot=0;
    for(i=1;i<=maxv;++i)
       if(flag[i])
           DFS_visit(i);
	for(i=1;i<=2*n;++i)
		e[set[i]].push_back(i);
	memset(col,0,sizeof(col));  ////染色时只需看其反的是否已染过色。。
	for(i=1;i<=tot;++i)
	{
		t1=last[i];
		x=e[t1][0];
		t2=set[opp(x)];
		if(!col[t2])
		{
			col[t1]=1;
			col[t2]=2;
		}
	}
	t2=set[1];
	for(i=2;i<n;++i)
	{
		t1=set[2*i-1];
		if(col[t1]==col[t2])
			printf("%dw ",i-1);
		else
			printf("%dh ",i-1);
	}
	if(col[set[2*n-1]]==col[t2])
		printf("%dw\n",n-1);
	else
		printf("%dh\n",n-1);
}

int make_value(char ch[])
{
	int k,j,v,n;
	v=0;n=strlen(ch);k=1;
	for(j=n-2;j>=0;--j)
	{
          v+=(ch[j]-'0')*k;
		  k*=10;
	}
	return v;
}

int main()
{
    char ch1[5],ch2[5];
	int t;
    while(EOF!=scanf("%d %d",&n,&m))
    {
      if(n==0&&m==0)
            break;
      for(i=1;i<=2*n;++i)
      {
        a[i].clear();
        b[i].clear();
      }
	  a[1].push_back(2);
	  b[2].push_back(1);
      while(m--)
      {
        scanf("%s %s",ch1,ch2);
        i=make_value(ch1);
        j=make_value(ch2);
        ++i;++j;
		//printf("%d %d\n",i,j);
		if(i==j)
			continue;
		i=2*i;j=2*j;
	    if(i>j)
		{
		   t=i;
		   i=j;
		   j=t;
		}
       if(ch1[1]=='w') /////第i个group。。。。。
           i--;
       if(ch2[1]=='w')
           j--;
	   a[i].push_back(opp(j));
	   b[opp(j)].push_back(i);
	   a[j].push_back(opp(i));
	   b[opp(i)].push_back(j);   
     }
    DFS();
    solve();
   }
   return 0;
}


#include<cstdio>
#include<map>
#include<string>
using namespace std;
map < string ,int > q;
int T,n,m,tot;
int f[110],a[110][110],b[110][110],c[110][110];


void mul(int x[110][110],int y[110][110],int t)
{
	 int i,j,k;
     memset(c,0,sizeof(c));
	 for(i=0;i<n;i++)
	    for(k=0;k<n;k++)
		    if(x[i][k])
			{
                for(j=0;j<n;j++)
					if(y[k][j])
						c[i][j]+=x[i][k]*y[k][j];
			    c[i][j]=(c[i][j]&1);
			}
	 if(t==1)
		 memcpy(b,c,sizeof(c));
	 else
		 memcpy(a,c,sizeof(c));

}

void solve()
{
	int i,j,k,cnt;
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
		b[i][i]=1;
	m--;
	while(m)
	{
		if(m&1)
			mul(b,a,1);
		mul(a,a,2);
		m>>=1;
	}
	cnt=0;
	for(i=0;i<n;i++)
	{
		k=0;
		for(j=0;j<n;j++)
			k+=f[j]*b[j][i];
		if(k&1)
			cnt++;
	}
	printf("%d\n",cnt);
}

int main()
{
	char name[30];
	int i,j,x,y,v,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		q.clear();
		tot=-1;
	    for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				a[i][j]=0;
			a[i][i]=1;
		}
		for(i=0;i<n;i++)
		{
			scanf("%s %d %d",name,&v,&k);///last
			if(!q.count(name))
                 q[name]=++tot;
			x=q[name];
			f[x]=(v&1); ///
			while(k--)
			{
				scanf("%s",name);
				if(!q.count(name))
					q[name]=++tot;
				y=q[name];
				a[x][y]=(a[x][y]+1)&1;
			}
		}
		solve();
	}
	return 0;
}
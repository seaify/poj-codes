#include<cstdio>
#include<cstring>
const int INF=1000000000;
int map[110][110],test[110],d[110][110],d1[110][110],S,E,N,T,tot;
bool flag[1100];

void mul(int x[110][110],int map[110][110] )
{
	 int i,j,k;
	 for(k=1;k<=tot;++k)
       for(i=1;i<=tot;++i)
		 for(j=1;j<=tot;++j)
		 {
			 d1[i][j]=INF;
			 if(x[i][k]+map[k][j]<d1[i][j])
				 d1[i][j]=x[i][k]+map[k][j];
		 }
	 for(i=1;i<=tot;++i)
		 for(j=1;j<=tot;++j)
			 d[i][j]=d1[i][j];
}

void solve()
{
    while(N)
	{
		if(N&1)
			mul(d,map);
        mul(map,map);
		N>>=1;
	}
	printf("%d\n",d[S][E]);
}

void read_data()
{
	int i,j,v;
	tot=0;
	memset(flag,false,sizeof(flag));
	for(i=1;i<=100;++i)
		for(j=1;j<=100;++j)
				map[i][j]=INF;
    while(T--)
	{
		scanf("%d %d %d",&v,&i,&j);
        if(!flag[i])
		{
			test[i]=++tot;
			flag[i]=true;
		}
		if(!flag[j])
		{
			test[j]=++tot;
			flag[j]=true;
		}
		map[test[i]][test[j]]=v;
	//	map[test[j]][test[i]]=v;
	}
	S=test[S];E=test[E];
	for(i=1;i<=tot;++i)//w
		for(j=1;j<=tot;++j)
		  d[i][j]=map[i][j];
	N--;   
}

int main()
{
	while(EOF!=scanf("%d %d %d %d",&N,&T,&S,&E))
	{
		read_data();
		solve();
	}
	return 0;
}

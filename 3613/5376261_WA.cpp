#include<cstdio>
#include<cstring>
const int INF=1000000000;
int map[210][210],test[1100],d[210][210],d1[210][210],S,E,N,T,tot;
bool flag[1100];

void mul(int x[210][210],int y[210][210],int t )
{
	 int i,j,k;
	 for(k=1;k<=tot;++k)
       for(i=1;i<=tot;++i)
		 for(j=1;j<=tot;++j)
		 {
			 d1[i][j]=INF;
			 if(x[i][k]+y[k][j]<d1[i][j])
				 d1[i][j]=x[i][k]+y[k][j];
		 }
	if(t==1)
	{
	  for(i=1;i<=tot;++i)
		 for(j=1;j<=tot;++j)
			 d[i][j]=d1[i][j];
	}
	else
    {
	    for(i=1;i<=tot;++i)
			for(j=1;j<=tot;++j)
				map[i][j]=d1[i][j];
	}
}

void solve()
{
    while(N)
	{
		if(N&1)
			mul(d,map,1);
        mul(map,map,2);
		N>>=1;
	}
	printf("%d\n",d[S][E]);
}

void read_data()
{
	int i,j,v;
	tot=0;
	memset(flag,false,sizeof(flag));
	for(i=1;i<=200;++i)
	{
		for(j=1;j<=200;++j)
				map[i][j]=INF,d[i][j]=INF;
		d[i][i]=0;
	}
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
		if(v<map[test[i]][test[j]])
		{
		    map[test[i]][test[j]]=v;
		    map[test[j]][test[i]]=v;
		}
	}
	S=test[S];E=test[E];
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

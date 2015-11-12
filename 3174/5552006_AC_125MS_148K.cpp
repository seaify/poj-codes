#include<cstdio>
int N,sum,cnt,i,j,k;
int x[1000],y[1000];
struct node 
{
	int x,y,z;
};
node a[9000000];

/*int cmp(int a,int k)   ////根据极角判断....
{
     return (x[a]-x[i])*(y[k]-y[i])-(x[k]-x[i])*(y[a]-y[i]);
}*/
int cmp()
{
	 int v;
	 v=(x[j]-x[i])*(y[k]-y[i])-(x[k]-x[i])*(y[j]-y[i]);
	 if(v==0)
		 return 1;
	 return 0;
}

int main()
{
	while(EOF!=scanf("%d",&N))
	{
		for(i=1;i<=N;++i)
			scanf("%d %d",&x[i],&y[i]);
		cnt=0;
		for(i=1;i<=N;++i)
		  for(j=i+1;j<=N;++j)
			for(k=j+1;k<=N;++k)
		   	   if(cmp())
				{
			 	    cnt++;
					a[cnt].x=i;
					a[cnt].y=j;
					a[cnt].z=k;
				}
	    printf("%d\n",cnt);
		for(i=1;i<=cnt;++i)
			printf("%d %d %d\n",a[i].x,a[i].y,a[i].z);
		
	}
	return 0;
}
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-6;
double pos[2000][4],x[2000],y[2000];
int N,x1,x2,x3,x4;
bool map[1000][1000];

int main()
{
	int i,j,k,T=0;
	double ans;
	while(EOF!=scanf("%d",&N))
	{
		if(N==0)
			break;
		for(i=0,j=0;i<N;++i,j+=2)
		{
		    scanf("%lf %lf %lf %lf",&pos[i][0],&pos[i][1],&pos[i][2],&pos[i][3]);
			x[j]=pos[i][0];
			x[j+1]=pos[i][2];
			y[j]=pos[i][1];
			y[j+1]=pos[i][3];
		}
		sort(x,x+2*N);
		sort(y,y+2*N);
		memset(map,false,sizeof(map));
		for(i=0;i<N;++i)
		{
            for(j=0;fabs(x[j]-pos[i][0])>eps;++j);x1=j;
			for(j=0;fabs(y[j]-pos[i][1])>eps;++j);x2=j;
			for(j=0;fabs(x[j]-pos[i][2])>eps;++j);x3=j;
			for(j=0;fabs(y[j]-pos[i][3])>eps;++j);x4=j;
			for(j=x1;j<x3;++j)
				for(k=x2;k<x4;++k)
					map[j][k]=true;
		}
		ans=0.0;
		for(i=0;i<2*N-1;++i)
			for(j=0;j<2*N-1;++j)
				if(map[i][j])
				    ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
		printf("Test case #%d\n",++T);
		printf("Total explored area: %.2lf\n\n",ans);
	}
	return 0;
}
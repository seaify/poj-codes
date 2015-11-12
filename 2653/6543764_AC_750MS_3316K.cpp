#include<stdio.h>
#include<math.h>

const double eps=1e-6;
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

struct node
{
	double x,y;
};
node a,b,c,d,p,e[110000][2];

int cmp(double d)
{
	if(fabs(d)<eps)
		return 0;
	return (d>0)?1:-1;
}


double det(double x1,double y1,double x2,double y2)
{
	return x1*y2-x2*y1;
}

double cross(node a,node b,node c)
{
	return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}

int xycmp(double p,double mini,double maxi)
{
	return cmp(p-mini)*cmp(p-maxi);
}

int between(node a,node b,node c)
{
	if(fabs(b.x-c.x)>fabs(b.y-c.y))
		return xycmp(a.x,min(b.x,c.x),max(b.x,c.x));
	else
		return xycmp(a.y,min(b.y,c.y),max(b.y,c.y));
}

int out(int d,node c,node a,node b)
{
	 if(d!=0)
		 return 0;
     if(between(c,a,b)<=0)
	 {
		 p=c;
		 return 1;
	 }
     return 0;
}

int solve(node a,node b,node c,node d)
{
     double s1,s2,s3,s4;
	 int d1,d2,d3,d4;

	 d1=cmp(s1=cross(a,b,c));
	 d2=cmp(s2=cross(a,b,d));
	 d3=cmp(s3=cross(c,d,a));
	 d4=cmp(s4=cross(c,d,b));

	 if((d1^d2)==-2&&(d3^d4)==-2)
	 {
		 p.x=(c.x*s2-d.x*s1)/(s2-s1);
		 p.y=(c.y*s2-d.y*s1)/(s2-s1);
		 return 1;     /////////规范相交.....
	 }

	 if(out(d1,c,a,b)||out(d2,d,a,b)||out(d3,a,c,d)||out(d4,b,c,d))
		  return 2;    ////非规范相交...

	 return 0;  ///相离..

}

int main()
{
	int i,j,n,num;
	while(EOF!=scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
			scanf("%lf %lf %lf %lf",&e[i][0].x,&e[i][0].y,&e[i][1].x,&e[i][1].y);
        num=0;
		printf("Top sticks: ");

		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
				if(solve(e[i][0],e[i][1],e[j][0],e[j][1]))
					break;

			if(j==n+1)
				printf("%d, ",i);
			
		}
		printf("%d.\n",n);
	}
	return 0;
}
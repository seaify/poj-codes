#include<stdio.h>
#include<math.h>

const double eps=1e-6;

int n;
double x[10],y[10];
double a,b,c,d,e,f,xx,yy;

double det(double x1,double y1,double x2,double y2)
{
	return x1*y2-x2*y1;
}

int main()
{
	int i;
	double k;
	scanf("%d",&n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--)
	{
        for(i=1;i<=4;i++)
			scanf("%lf %lf",&x[i],&y[i]);
        k=det(x[2]-x[1],y[2]-y[1],x[4]-x[3],y[4]-y[3]);
		if(fabs(k)<eps)
		{
             k=det(x[2]-x[1],y[2]-y[1],x[3]-x[1],y[3]-y[1]);
			 if(fabs(k)<eps)
				 printf("LINE\n");
			 else
				 printf("NONE\n");
			 continue;
		}

		a=y[2]-y[1];
		b=x[2]-x[1];
		c=y[4]-y[3];
		d=x[4]-x[3];
		e=x[1]*y[2]-y[1]*x[2];
		f=x[3]*y[4]-y[3]*x[4];

		yy=(e*c-a*f)/(a*d-b*c);
		xx=(e*d-b*f)/(a*d-b*c);

		printf("POINT %.2lf %.2lf\n",xx,yy);

	}
	printf("END OF OUTPUT\n");

}
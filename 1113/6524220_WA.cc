#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const double eps=1e-8;

int n,L;

struct node
{
	int x,y;
};
node p[1100],q[1100],tmp;


double dis(node a,node b)
{
	return sqrt(0.0+(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


int cmp(node a,node b)
{
     int tmp=(a.x-p[0].x)*(b.y-p[0].y)-(b.x-p[0].x)*(a.y-p[0].y);
	 if(tmp<0)
		 return 0;
	 if(tmp>0)
		 return 1;
	 if(dis(a,p[0])+eps<=dis(b,p[0]))
		 return 1;
	 return 0;
}

int cross(node a,node b,node c)   ///// c在ab连线下方返回1
{
	 return (c.x-a.x)*(b.y-a.y)<(b.x-a.x)*(c.y-a.y);
}


int  main()
{
	int i,c,top,ans;
	double result,pi=acos(-1.0);
	while(EOF!=scanf("%d %d",&n,&L))
	{
		  scanf("%d %d",&p[0].x,&p[0].y);
		  c=0;
          for(i=1;i<n;i++)
		  {
			  scanf("%d %d",&p[i].x,&p[i].y);
			  if(p[i].y<p[c].y||(p[i].y==p[c].y&&p[i].x<p[c].x))
				  c=i;
		  }
		  tmp=p[0];
		  p[0]=p[c];
		  p[c]=tmp;
		  
		  sort(p+1,p+n,cmp);
          
		  q[0]=p[0];
		  q[1]=p[1];
		  q[2]=p[2];
		  top=2;

		  for(i=3;i<n;i++)
		  {
			  while(cross(q[top-1],q[top],p[i]))
				  top--;
			  q[++top]=p[i];
		  }


          
		  result=2.0*pi*L;
		  
		 // printf("%lf %lf\n",pi,result);

		  for(i=0;i<=top;i++)
			  result+=dis(q[i],q[(i+1)%(top+1)]);

	//	  ans=(int)(result+0.5);

		  printf("%.0f\n",result);

	}
}
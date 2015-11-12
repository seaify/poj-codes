#include<stdio.h>
#include<math.h>
#define eps 1e-9
typedef struct point 
{ 
  int x,y; 
}point;
point p[5]; 
typedef struct TLINE
{
   double a,b,c,y;
}TLINE;
TLINE k(point p1, point p2) 
{ 
    TLINE tmp; 
    tmp.a = p2.y - p1.y; 
    tmp.b = p1.x - p2.x; 
    tmp.c = p2.x * p1.y - p1.x * p2.y; 
	tmp.y=p1.y;
    return tmp;    
} 
void  swap(int i,int j)
{
	point c;
	c=p[i];
	p[i]=p[j];
	p[j]=c;
}
double dis(TLINE tmp,int x)
{
	double y;
	if(fabs(tmp.b)<eps)
          return tmp.y;
	else
	{
		y=(-tmp.c-tmp.a*x)/tmp.b;
	    return y;
	}
}
int ISint(double x)
{
	int k;
     k=int(x);
	if(fabs(x-k)<eps)
		return 1;
	if(fabs(x-k-1)<eps)
		return 1;
	return 0;
}
int main()
{
	TLINE tmp1,tmp2,tmp3;int s,i,h;double m,n;
	while(EOF!=scanf("%d%d%d%d%d%d",&p[1].x,&p[1].y,&p[2].x,&p[2].y,&p[3].x,&p[3].y)&&(p[1].x||p[1].y||p[2].x||p[2].y||p[3].x||p[3].y))
	{
		s=0;
		if(p[2].x<p[1].x)
			swap(1,2);
		if(p[3].x<p[1].x)
			swap(1,3);
		if(p[3].x<p[2].x)
			swap(2,3);	
		tmp1=k(p[1],p[2]);
		tmp2=k(p[2],p[3]);
		tmp3=k(p[1],p[3]);
		for(i=p[1].x+1;i<=p[2].x;i++)
		{
			m=dis(tmp1,i);	//可能有精度问题
            n=dis(tmp3,i);		
			s+=int(fabs(m-n));
			h=int(fabs(m-n));
			if(h&&ISint(m)&&ISint(n))
				s--;
		}
		for(i=p[2].x+1;i<p[3].x;i++)
		{
			m=dis(tmp2,i);
			n=dis(tmp3,i);
			s+=int(fabs(m-n));
			h=int(fabs(m-n));		
			if(h&&ISint(m)&&ISint(n))
				s--;
		}
		printf("%d\n",s);
	}
	return 0;
}

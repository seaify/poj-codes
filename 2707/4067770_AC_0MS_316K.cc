#include<stdio.h>
int main()
{
	double a,b,x,y,s;int c=37;
	while(EOF!=scanf("%lf%lf%lf%lf",&a,&b,&x,&y)&&(a||b||x||y))
	{
		s=a+b;
		a=(a<b)?a:b;
		b=s-a;
		s=x+y;
		x=(x<y)?x:y;
		y=s-x;
		if(x>=a&&y>=b)
			printf("100%c\n",c);
		else 
			if(x/a<=y/b)
			     printf("%d%c\n",int((x*100)/a),c);
			else
				 printf("%d%c\n",int((y*100)/b),c);
	}
	return 0;
}
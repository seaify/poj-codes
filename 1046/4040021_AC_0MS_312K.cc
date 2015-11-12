#include<stdio.h>
#include<string.h>
int main()
{
   int i,a,b,c,x[18],y[18],z[18],min,minx,miny,minz,s;
   for(i=1;i<=16;i++)
	   scanf("%d%d%d",&x[i],&y[i],&z[i]);
   while(EOF!=scanf("%d%d%d",&a,&b,&c))
   {
	   if(a==-1&&b==-1&&c==-1)
		   break;min=1000000;
	   for(i=1;i<=16;i++)
	   {
		   s=(a-x[i])*(a-x[i])+(b-y[i])*(b-y[i])+(c-z[i])*(c-z[i]);
		   if(s<min)
		   {   
			   min=s;
			   minx=x[i];
			   miny=y[i];
			   minz=z[i];
		   }
	   }
	   printf("(%d,%d,%d) maps to (%d,%d,%d)\n",a,b,c,minx,miny,minz);
   }
	return 0;
}



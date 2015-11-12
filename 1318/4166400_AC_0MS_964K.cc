#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[102][8],c[8],b[102][8];

int cmp1(const void *a,const void *b)
{
     return(*(char *)a-*(char *)b);
}

int cmp2(const void *a,const void *b)
{
     return(strcmp((char*)a,(char*)b));
}
void Printf(int n)
{
	int i,y,k;char x[102][8];
	y=0;k=1;
	for(i=1;i<=n;i++)
		if(strcmp(b[i],c)==0)
		{y=1;strcpy(x[k++],a[i]);}
	if(y)
	{
		qsort(x+1,k-1,sizeof(x[1]),cmp2);
	    for(i=1;i<=k-1;i++)
			printf("%s\n",x[i]);
	}
	else 
		printf("NOT A VALID WORD\n");
}

int main()
{
	int i,n,len;
   for(i=1; ;i++)
   {
	   scanf("%s",a[i]);
	if(strcmp(a[i],"XXXXXX")==0)
           break;

	   strcpy(b[i],a[i]);
	   len=strlen(b[i]);
	   qsort(b[i],len,sizeof(b[i][0]),cmp1);	   
   }
   n=i-1;
   while(EOF!=scanf("%s",c))
   {
	   if(strcmp(c,"XXXXXX")==0)
		   break;
	   len=strlen(c);
       qsort(c,len,sizeof(c[0]),cmp1);
	   Printf(n);
	   printf("******\n");
   }
   return 0;
}

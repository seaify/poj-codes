#include<stdio.h>
int main()
{
	int i,j,s,c;
	char a[10];
    gets(a);j=0;s=0;
	for(i=0,c=10;i<=8;i++,c--)
		if(a[i]=='?')
		{
			j=i;continue;
		}
		else 	
			s+=c*(a[i]-'0');
		s=s%11;
		if(j)
		{
			s=11-s;j=10-j;
	        for(i=0;i<=9;i++)
              if((j*i)%11==s)
			  {printf("%d\n",i);break;}
			  if(i==10)
				  printf("-1\n");
		}
		else
			if(s==0)
				printf("X\n");
			else 
				printf("-1\n");
			return 0;
}


		 


				
	
		
		

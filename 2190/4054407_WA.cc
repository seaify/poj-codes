#include<stdio.h>
int main()
{
	int i,j,s,c;
	char a[10];
    gets(a);j=0;s=0;
	for(i=0,c=10;i<=9;i++,c--)
		if(a[i]=='?')
		{
			j=i;continue;
		}
		else if(a[i]=='X')	
		      	s+=10;
		else
			s+=c*(a[i]-'0');
		s=s%11;
		s=11-s;j=10-j;  c=0;
	        for(i=0;i<=9;i++)
              if((j*i)%11==s)
			  {printf("%d\n",i);c=1;break;}
			  if(c!=1)
			  {  if(j==1&&s==10)
				 
					printf("X\n");
				else
					printf("-1\n");
			  }
	
			return 0;
}


		 


				
	
		

	  
		
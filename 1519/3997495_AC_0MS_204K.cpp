#include<stdio.h>
#include<string.h>
int main()
{
	long n,i,sum;char a[2000];int s[20];memset(a,0,sizeof(a));
	while(EOF!=scanf("%s",a))
	{   
	    if(strcmp(a,"0")==0)
			  break;
		  sum=0;
		  for(i=0;a[i]!='\0';i++)
			  sum+=a[i]-'0';n=sum;
		  while(1)
		  {  
			  sum=0;
		      for(i=0;n!=0;i++)
			  {
				  s[i]=n%10;
				  sum+=s[i];
				  n/=10;
			  }
			  if(sum>=10)
				  n=sum;
			  else
			  { printf("%ld\n",sum);break;}
		  }	
		  memset(a,0,sizeof(a));
	}
	return 0;
}



		  

	
			
		
		


		 
	     
			  

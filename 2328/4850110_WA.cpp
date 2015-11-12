#include<stdio.h>
#include<string.h>
char ans[20];
int value;
int main()
{
  int min,max,sum;
  bool last,first;
  min=20;max=-1;
  first=true;last=true;
  while(1)//不断更新min,max
  {
	scanf("%d",&value);
	gets(ans);
	if(value==0)
		break;
	if(strcmp(ans,"too high")==0)//注意初始化sum
	{
       if(!first&&value<=sum)
		    last=false;
	   sum=value-1;
	   first=false;
	}
	if(strcmp(ans,"too low")==0)
	{
	   if(!first&&value>=sum)
		   last=false;
	   sum=value+1;
	   first=false;
	}
	if(strcmp(ans,"right on")==0)
	{
      if(last&&sum==value)
		  printf("Stan may be honest\n");
	  else
		  printf("Stan is dishonest\n");
	  first=true;
	  last=true;
	  min=20;
	  max=-1;
	}
  }
  return 0;
}

				  
			  
		 
		
		
	
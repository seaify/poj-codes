#include<stdio.h>
#include<string.h>
char ans[10],temp[10];
int value;
int main()
{
  int min,max;
  bool minx,maxx,last;
  min=-1;max=20;
  minx=false;maxx=false;
  last=true;
  while(1)//不断更新min,max
  {
	scanf("%d",&value);
	if(value==0)
		break;
	scanf("%s%s",ans,temp);
	strcat(ans,temp);
	if(strcmp(ans,"toohigh")==0)//注意初始化sum
	{
	   if(last)
	   {
        if(minx&&maxx)
		  if(min>max)
			  last=false;
	    if(minx)
		  if(value<=min)
			  last=false;
	    max=(value-1)<max?value-1:max;  
	    maxx=true;
	   }
	}
	if(strcmp(ans,"toolow")==0)
	{
	   if(last)
	   {
	    if(minx&&maxx)
		  if(min>max)
			  last=false;
	    if(maxx)
		  if(value>=max)
			  last=false;
	    min=min>(value+1)?min:value+1;
	    minx=true;
	   }
	}
	if(strcmp(ans,"righton")==0)
	{
	  if(last)
	  {
	   if(minx&&maxx)
		  if(min>max)
			  last=false;
	   if(minx)
		  if(value<min)
			  last=false;
	   if(maxx)
		  if(value>max)
			  last=false;
	  }
	  if(last)
		  printf("Stan may be honest\n");
	  else
		  printf("Stan is dishonest\n");
	  minx=false;
	  maxx=false;
	  last=true;
	  min=-1;
	  max=20;
	}
  }
  return 0;
}

				  
			  
		 
		
		
	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int s[10000],n,i;

int cmp(const void *a, const void *b)
{
     return(*(int *)a-*(int *)b);
}

int main()
{
	char str[1005];int s[1005],i,len,flag[15],c,k,sum;
	while(EOF!=	scanf("%s",str))
	
	{	
	len=strlen(str);memset(flag,0,sizeof(flag));sum=0;
	for(i=0;i<len;i++)
	{
		s[i]=str[i]-48;
		flag[s[i]]++;
		sum+=s[i];
	} 
	qsort(s,len,sizeof(s[0]),cmp);k=sum%3;
     if(flag[0]==0&&flag[5]==0)
		printf("impossible\n");
	else if(flag[0]!=0)
	{		
		if(k==0)
		{   c=0;
			for(i=1;i<=9;i++)
				if(flag[i]!=0)
				    c=1;							
			if(!c)
				printf("0\n");
			else
			{
				for(i=len-1;i>=0;i--)
					printf("%d",s[i]);	
				printf("\n");   
			}
		}
		if(k==1)
		{
			if(flag[1]||flag[4]||flag[7])
			{
				for(i=0,c=1;i<len&&c>0;i++)
					if(s[i]%3==1)
					{s[i]=-1;c--;}
					c=0;
					for(i=len-1;i>=0;i--)
						if(s[i]>0)
						{c=1;break;}
					if(c==0)
						printf("0\n");
					else
					{ 
						for(i=len-1;i>=0;i--)
				        if(s[i]>=0)
						printf("%d",s[i]);	
						printf("\n");
					}        
			}  
			else
			{    
			
				for(i=1,c=2;i<=len-1&&c>=1;i++)
					if(s[i]%3==2)
					{c--;s[i]=-1;}c=0;
					for(i=len-1;i>=0;i--)
						if(s[i]>0)
						{c=1;break;}
					if(c==0)printf("0\n");
					else
					{for(i=len-1;i>=0;i--)
				        if(s[i]>=0)
						printf("%d",s[i]);
						printf("\n");
					}
			
			}
					
		}
		if(k==2)
		{
			if(flag[2]||flag[5]||flag[8])
			{
				for(i=1,c=1;i<=len-1&&c>0;i++)
					if(s[i]%3==2)
					{c--;s[i]=-1;}
					c=0;
					for(i=len-1;i>=0;i--)
						if(s[i]>0)
						{c=1;break;}
					if(c==0)
						printf("0\n");
					else
					{
						for(i=len-1;i>=0;i--)
				        if(s[i]>=0)
						printf("%d",s[i]);
						printf("\n");
					}
			}
			else
			{for(i=1,c=2;i<len-1&&c>0;i++)
		
					if(s[i]%3==1)
					{c--;s[i]=-1;}
					c=0;
					for(i=len-1;i>=0;i--)
						if(s[i]>0)
						{c=1;break;}
					if(c==0)
						printf("0\n");
					else
					{
						for(i=len-1;i>=0;i--)
				        if(s[i]>=0)
						printf("%d",s[i]);
						printf("\n");
					}
			}
		}
	}
	else
	{
		for(i=0,c=1;i<=len-1&&c>0;i++)
			if(s[i]==5)
			{s[i]=-1;c=0;}
		if(k==0)
		{
			for(i=len-1;i>=0;i--)
			    if(s[i]>=0)
					printf("%d",s[i]);
				printf("5\n");
		}
		if(k==1)
		{
           	if(flag[1]||flag[4]||flag[7])
			{
				for(i=0,c=1;i<len&&c>0;i++)
					if(s[i]>=0&&s[i]%3==1)
					{s[i]=-1;c--;}
					for(i=len-1;i>=0;i--)
				        if(s[i]>=0)
						printf("%d",s[i]);
						printf("5\n");
				
						
			}
			else
			{   if(flag[2]+flag[5]+flag[8]>=3)
			{for(i=0,c=2;i<=len-1&&c>0;i++)
					if(s[i]>=0&&s[i]%3==2)
					{c--;s[i]=-1;}
					for(i=len-1;i>=0;i--)
				        if(s[i]>=0)
						printf("%d",s[i]);
						printf("5\n");
			}
			else
				printf("impossible\n");
			}
		}

    if(k==2)
	{      if(flag[2]+flag[5]+flag[8]>=2)
	{
		
				for(i=1,c=1;i<len&&c>0;i++)
					if(s[i]>0&&s[i]%3==2)
					{c--;s[i]=-1;}
					for(i=len-1;i>=0;i--)
				        if(s[i]>=0)
						printf("%d",s[i]);
						printf("5\n");
		
	}
			else if(flag[1]+flag[4]+flag[7]>=2)
			{
				for(i=len-1,c=2;i>=0&&c>0;i--)
					if(s[i]%3==1)
					{c--;s[i]=-1;}
					for(i=len-1;i>=0;i--)
				        if(s[i]>=0)
						printf("%d",s[i]);
						printf("5\n");
			}
			else
				printf("impossible\n");
	}	
	}
	}    
     return 0;
}


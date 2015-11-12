#include<stdio.h>   
 #include<string.h>   
 int main()   
 {   
     int i,j,n,k,t1,t2,h,m,c;   
     char a[100],b[100];   
    scanf("%d",&n);
    
         m=n;   
     while(n--)   
     {   memset(a,0,sizeof(a));   
         memset(a,0,sizeof(b));   
         scanf("%s%s",a,b);   
         t1=strlen(a)-1;   
         t2=strlen(b)-1;   
         k=(t1>=t2)?t1:t2;   
         for(i=t1,j=t2;i>=0&&j>=0;i--,j--)   
         {   
             a[k]=a[i]+b[j]-48;   
             k--;   
         }   
         if(t1<t2)   
             for(i=0;i<t2-t1;i++)   
                 a[i]=b[i];   
             k=(t1>=t2)?t1:t2;   
             h=0;   
             for(i=k;i>=0;i--)   
             {      
                 a[i]=a[i]+h;   
                 if(a[i]>=50)   
                 {   
                     h=1;   
                     a[i]=a[i]-2;   
                 }   
                 else    
                     h=0;   
             }   
             printf("%d ",m-n);   
             if(h==1)   
                 printf("1%s\n",a);   
             if(h==0)   
			 {    c=0;
				 for(i=0;i<k;i++)
				  {
					  if(a[i]!=48)
						  c=1;
					  if(c)
						  printf("%c",a[i]);
				 }
				 printf("%c\n",a[k]);
			 }

					  
     }   
    
     return 0;   
 }   


     

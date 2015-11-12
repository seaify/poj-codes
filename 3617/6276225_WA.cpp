#include<iostream>

char a[2100],b[2100],ch[2];
int n,tot;

void dp(int x,int y)
{
     int i,j;
     if(x>y)
        return ;
	 if(x==y)
	 {
		 a[tot++]=b[x];
		 return ;
	 }
     for(i=x,j=y;i<=y&&j>=x;i++,j--)
          if(b[i]==b[j])
              continue;
          else if(b[i]<b[j])
          {
               a[tot++]=b[x];
               dp(x+1,y);
               return ;
          }
          else
          {
               a[tot++]=b[y];
               dp(x,y-1);
               return ;
          }
                       
}

int main()
{
    int i;
    while(EOF!=scanf("%d",&n))
    {
          for(i=0;i<n;i++)
          {
             scanf("%s",ch);
             b[i]=ch[0];
          }
          tot=0;
          dp(0,n-1);
          a[tot]='\0';
          for(i=0;i<tot;)
		  { 		
			  printf("%c",a[i++]);
			  if(i%80==0)
				   printf("\n");		 
		  }
    } 
	return 0;
}

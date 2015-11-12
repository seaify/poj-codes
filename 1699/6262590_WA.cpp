#include<iostream>
#include<string.h>

int T,n,result;
int map[20][20],len[20],p[20],a[1400];
char ch[20][40];

void init()
{
    int i,j,c,k,x,y,ans;
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
          if(j==i)
             continue;

		  ans=0;
         
		  for(k=1;k<=len[i]&&k<=len[j];k++)
		  {
			  x=len[i]-k;
			  y=0;
			  for(c=0;c<k;c++)
				  if(ch[i][x+c]!=ch[j][y+c])
					  break;
			  if(c==k)
				  ans=k;
		  }

          map[i][j]=ans;   
      }  
    }
}

void solve()
{
     int i,j,c,k,top=(1<<n);
     
     for(i=1;i<top;i++)
     {
         a[i]=0;
         for(j=0;j<n;j++)
             if(i&p[j])
             {
                k=i-p[j];
                if(k==0)    
                   continue;
                for(c=0;c<n;c++)
                   if(k&p[c])
                   {
                      if(a[k]+map[c][j]>a[i])
                         a[i]=a[k]+map[c][j];
                   }
             }              
     }
     printf("%d\n",result-a[top-1]); 
}

int main()
{
    int i;
    for(i=0;i<=20;i++)
        p[i]=(1<<i);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        result=0;
        for(i=0;i<n;i++)
        {
           scanf("%s",ch+i);
           len[i]=strlen(ch[i]);
           result+=len[i];
        }       
        init();
        solve();
    }
    return 0;
}

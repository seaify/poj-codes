#include<iostream>
#include<string.h>

int T,n,result;
int map[20][20],len[20],p[200],a[1400][20];
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

          map[i][j]=len[j]-ans;   
      }  
    }
}

void solve()
{
     int i,j,c,k,ans,top=(1<<n);
     
     for(i=1;i<top;i++)
     {
         for(j=0;j<n;j++)
             if(i&p[j])
             {
                k=i-p[j]; 
                if(k==0)   
				{
				   a[i][j]=len[j];
                   continue;
				}
				a[i][j]=2000;
                for(c=0;c<n;c++)
                   if(k&p[c])
                   {
                      if(a[k][c]+map[c][j]<a[i][j])
                         a[i][j]=a[k][c]+map[c][j];
                   }
             }              
     }
	 ans=2000;
     for(i=0;i<n;i++)
		 if(a[top-1][i]<ans)
			 ans=a[top-1][i];
	 printf("%d\n",ans);
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
        for(i=0;i<n;i++)
        {
           scanf("%s",ch[i]);
           len[i]=strlen(ch[i]);
        }       
        init();
        solve();
    }
    return 0;
}

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int m,n,result,N;
int a[200],p[20];
int f[70000],g[70000];
char ch[20];

struct node
{
    int x,y;
    char ch[20];
};
node e[70000];

int cmp(node a,node b)
{
    if(a.x!=b.x)
         return a.x<b.x;
    if(a.y!=b.y)
         return a.y<b.y;
    return strcmp(a.ch,b.ch)<0;
}

int main()
{
    int i,j,k,flag,tag;
    
    for(i=0;i<=18;i++)
          p[i]=(1<<i);
          
    while(EOF!=scanf("%d %d",&m,&n))
    {
		 flag=0;
		 tag=0;
         for(i=0;i<=n;i++)
         {
             scanf("%s",ch);
             a[i]=0;
             for(j=0;j<m;j++)
                 a[i]+=(ch[j]-'0')*p[m-j-1];
			 if(a[i]==a[0])
				 flag=1;
			 if(a[i]==0)
				 tag=1;

         }

		 if(flag)
		 {
			 if(tag)
				 printf("1\n");
			 else
				 printf("2\n");
			 for(j=0;j<m;j++)
                 if(a[0]&p[m-1-j])
                   printf("1");
                  else
                  printf("0"); 
             printf("\n"); 
			 continue;
		 }
         
         for(i=0;i<p[m];i++)
              f[i]=g[i]=1000;

              
         for(i=1;i<=n;i++)
         {
             g[a[i]]=0;
             for(j=0;j<p[m];j++)
                   if(f[j]+1<g[j^a[i]])
                        g[j^a[i]]=f[j]+1;
                
             for(j=0;j<p[m];j++)
                 f[j]=g[j];               
         }

	/*	 for(j=0;j<p[m];j++)
			 printf("%d ",f[j]);
		 printf("\n");*/
         
         N=0;
         
         for(j=0;j<p[m];j++)
           if(f[j]!=1000)
           {
               e[N].y=f[j]; 
               
               e[N].x=0;
             
               k=j^a[0];
               for(i=m-1;i>=0;i--)
               {
                  if(k&p[i])
                     e[N].x++;   

                  e[N].ch[m-1-i]='0';  

				  if(j&p[i])
					  e[N].ch[m-1-i]++;
               }
               e[N].ch[m]='\0';
               N++;
           }
         
         sort(e,e+N,cmp);
         
         printf("%d\n",e[0].y);

         printf("%s\n",e[0].ch);
                  
          
    }
    return 0;
} 

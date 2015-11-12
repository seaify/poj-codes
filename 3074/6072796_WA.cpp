#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn=700000;
const int INF=2000;
const int n=729;
const int m=324;

int tot;
int x[maxn],y[maxn],num[maxn];
int U[maxn],D[maxn],L[maxn],R[maxn];
int ok[1100],tail[1100];
int map[750][10],ans[200];
char s[200];

void debug()
{

	int i;

	for(i=1;i<=81;i++)
		printf("%d %d %d %d\n",map[i][1],map[i][2],map[i][3],map[i][4]);

}

void remove(int c)
{
     
     int i,j;
     
     R[L[c]]=R[c];
     L[R[c]]=L[c];
     
     for(i=D[c];i!=c;i=D[i])
         for(j=R[i];j!=i;j=R[j])
         {
              U[D[j]]=U[j];
              D[U[j]]=D[j]; 
              num[y[j]]--;
         }
                                     
}

void resume(int c)
{
     int i,j;
     
     for(i=U[c];i!=c;i=U[i])
        for(j=L[i];j!=i;j=L[j])
        {
             U[D[j]]=j;
             D[U[j]]=j;
             num[y[j]]++;
        } 
     
     R[L[c]]=c;
     L[R[c]]=c;   
     
}

int dfs(int k)
{
     int count,i,j,c;
     
     if(R[0]==0)      
     {
          
		 sort(ok,ok+k);

		 for(i=0;i<k;i++)
		 {
	
              c=ok[i]%9+1;

			  printf("%d",c);
	
		 }

		 printf("\n");
	
                  
         return 1;
     }
     
     count=INF;
     
     for(i=R[0];i!=0;i=R[i])
         if(num[i]<count)
         {
              count=num[i];
              c=i;       ////对于入口 
         }
         
     remove(c);
     
     for(i=D[c];i!=c;i=D[i])
     {
        ok[k]=x[i];
        for(j=R[i];j!=i;j=R[j])
                remove(y[j]);
                
        if(dfs(k+1))
              return 1;
        
        for(j=L[i];j!=i;j=L[j])
              resume(y[j]);
     }
     
     resume(c);
     
     return 0;
         
} 

void init()
{
     
   int i,j,row,col,c,box,value;
   
   
   for(i=1;i<=n;i++)
   {

	   map[i][0]=0;

	   row=i/81+1;
	   col=(i/9)%9+1;        ////row,col比实际少1
	   value=i%9+1;

	   c=(row-1)*9+col;

	   if(s[c]=='.'||s[c]=='0'+value)
	   {
		   map[i][0]=4;
		   map[i][1]=c;
		   map[i][2]=81+(row-1)*9+value;
		   map[i][3]=162+(col-1)*9+value;
		   box=((row+2)/3-1)*3+(col+2)/3;
		   map[i][4]=243+(box-1)*9+value;
	   }

   }
   
   for(i=0;i<=m;i++)  /////不需要初始化x,y,根本不会用上.... 
   {
       L[i]=i-1;
       R[i]=i+1;
       U[i]=i;
       D[i]=i;
       num[i]=0;
       tail[i]=i;    ////尾部指针.... 
	   y[i]=i;
   }
   
   L[0]=m;
   R[m]=0;
   
   tot=m;
   
   for(i=1;i<=n;i++)    /////只适合解静态条件的....,有些是题目给出,但也可以事先自己算出来即可..
   {         
       
	   c=map[i][0];

       for(j=1;j<=c;j++)
       {
                        
           col=map[i][j];
           
           
           x[tot+j]=i;
           y[tot+j]=col;
           
           
           R[tot+j]=tot+j+1;
           L[tot+j]=tot+j-1;
           
           U[col]=tot+j;
           D[tail[col]]=tot+j;
           U[tot+j]=tail[col];
           D[tot+j]=col;
           tail[col]=tot+j;
           num[col]++;
           
       }
       
    
      if(c)
	  {
          L[tot+1]=tot+c;
          R[tot+c]=tot+1;
	  }
      
       
      tot+=c;
       
   }

   dfs(0);
	               
}

int main()
{
    while(EOF!=scanf("%s",s+1))
    {
          if(s[1]=='e')
             break;
          init();
    }
    return 0;
} 

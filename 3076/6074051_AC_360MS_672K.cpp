#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn=40000;
const int INF=20000;
const int n=4096;
const int m=1024;

int tot;
int x[maxn],y[maxn],num[maxn],q[maxn];
int U[maxn],D[maxn],L[maxn],R[maxn];
int ok[maxn],tail[maxn];
int map[maxn][10];
char tmp[20][20];


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
          
		 sort(ok+1,ok+k); 
         
         

		 for(i=1;i<k;i++)	
		 {
             putchar(q[ok[i]]+'A'-1);
             if(i%16==0)
                printf("\n");
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
   
   
    for(row=1;row<=16;row++)
      for(col=1;col<=16;col++)
        for(value=1;value<=16;value++)
        { 
	        
	        i=(row-1)*256+(col-1)*16+value;
	        
	        map[i][0]=0;
	        
	        q[i]=value;

	        if(tmp[row][col]=='-'||tmp[row][col]=='A'-1+value)
	        {
		        map[i][0]=4;
		        map[i][1]=(row-1)*16+col;;
		        map[i][2]=256+(row-1)*16+value;
		        map[i][3]=512+(col-1)*16+value;
		        box=((row+3)/4-1)*4+(col+3)/4;
		        map[i][4]=768+(box-1)*16+value;
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
   
   dfs(1);
	               
}

int main()
{
    
    int i,T;

    while(EOF!=scanf("%s",&tmp[1][1]))
    {
        for(i=2;i<=16;i++)         
             scanf("%s",&tmp[i][1]);  
	
        init();

    }

    return 0;

} 


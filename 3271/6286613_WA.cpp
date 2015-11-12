#include<stdio.h>

const int INF=10000;

int n,m,S,T;
int a[40][40],map[1000][1000],d[1000],flag[1000],num[1000];
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

void Dijkstra()
{
   int i,j,x,min;
 
   n*=m;
   
   for(i=0;i<n;i++)
         d[i]=INF,flag[i]=1,num[i]=0;
   d[S]=0;
   num[S]=1;
   for(i=0;i<n;i++)
   {
       x=-1;
       min=INF;
       for(j=0;j<n;j++)
           if(flag[j]&&d[j]<min)
	   {
		min=d[j];
		x=j;
	   }
       if(x==-1)
       {
           printf("-1\n");
	   return ;
       }
       if(x==T)
           break;
       flag[x]=0;
       for(j=0;j<n;j++)
          if(flag[j]&&map[x][j]!=INF)
	  {
	      if(d[x]+map[x][j]<d[j])
                   d[j]=d[x]+map[x][j],num[j]=num[x];
	      else if(d[x]+map[x][j]==d[j])
                   num[j]+=num[x];
	  }
   }
   //for(i=0;i<n;i++)
   //printf("%d %d\n",d[i],num[i]);
   if(d[T]==0)
       num[T]=1;
   printf("%d\n%d\n",d[T],num[T]);
}

int main()
{
   int i,j,k,x1,y1;
   while(EOF!=scanf("%d %d",&m,&n))
   {
        for(i=0;i<m;i++)
	   for(j=0;j<n;j++)
           {
              scanf("%d",&a[i][j]);
              if(a[i][j]==3)
                  S=i*n+j;
              if(a[i][j]==4)
                  T=i*n+j;
                  
           }
       
        for(i=0;i<m*n;i++)
	{
      	  for(j=0;j<m*n;j++)
               map[i][j]=INF;
	   map[i][i]=0;
	}

	for(i=0;i<m;i++)
	 for(j=0;j<n;j++)
         {
	    for(k=0;k<8;k++)
            {
		x1=i+dir[k][0];
		y1=j+dir[k][1];
		if(x1<0||x1>=m||y1<0||y1>=n)
		     continue;
                if(a[x1][y1]==0)
                     map[i*n+j][x1*n+y1]=1;
   		else if(a[x1][y1]!=2)
		     map[i*n+j][x1*n+y1]=0;                 
	    }
	 }	
         
         Dijkstra();
        
   }
    return 0;
}    
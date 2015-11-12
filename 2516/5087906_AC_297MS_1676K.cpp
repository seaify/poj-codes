#include<stdio.h>
#include<string.h>
#include<math.h>
const int INF=100000000;
int m,n,x[400],y[400],lx[400],ly[400],link[400];
int minx,v[60][60][60],value[400][400],a[400][400],b[400][400],cnt[400];
struct node
{
   int beg,end;
};
node first[400],last[400];
int find(int cur)
{
 int i;
 x[cur]=true;
 for(i=1;i<=n;i++)
 {
   if(!y[i]&&lx[cur]+ly[i]==value[cur][i])
   {
	 y[i]=true;
	 if(link[i]==-1||find(link[i]))
	 {
		link[i]=cur;
		return 1;
	 }
   }
 }
 return 0;
}
int KM()
{
  int i;
  memset(link,-1,sizeof(link));
  for (i=1; i <=n; i++) 
    { 
        while (1) 
        { 
            memset(x, 0, sizeof(x)); 
            memset(y, 0, sizeof(y)); 
            if (find(i)) break; 
            int j, k, min = INF; 
            for (j = 1; j <= n; j++) 
                if (x[j]) 
                    for (k = 1; k <= n; k++) 
                        if (!y[k]) 
                            min= min< lx[j] + ly[k] -value[j][k]?min:lx[j] + ly[k] - value[j][k]; 
            if (!min) break; 
            for (j = 1; j<=n; j++) 
            { 
                if (x[j]) lx[j] -= min; 
                if (y[j]) ly[j] += min; 
            } 
        } 
    } 
  int res = 0; 
    for (i = 1; i <= n; i++) 
            res += value[link[i]][i]; 
    return res; 
}
int main()
{
  int i,j,k,n1,sum,c,w,d,time,flag;
  while(EOF!=scanf("%d%d%d",&n1,&m,&time))
  {
   if(n1==0&&m==0&&time==0)
      break;
   memset(cnt,0,sizeof(cnt));
   for(i=1;i<=n1;++i)//n1为所要的货物。。。 
   {
     for(j=1;j<=time;++j)
     {
        scanf("%d",&a[i][j]);
     //   printf("%d ",a[i][j]);
        cnt[j]-=a[i][j];
     }
  //   printf("\n");
   }
   for(i=1;i<=m;++i)//m为所能提供的货物。。。 
   {
     for(j=1;j<=time;++j)
     {
        scanf("%d",&b[i][j]);
    //    printf("%d ",b[i][j]);
        cnt[j]+=b[i][j];
     }
   //  printf("\n");
   }
   for(k=1;k<=time;++k)
     for(i=1;i<=n1;++i)//
       for(j=1;j<=m;++j)
          scanf("%d",&v[k][i][j]);
   flag=1;
   for(j=1;j<=time;++j)
      if(cnt[j]<0)
      {
          flag=0;
          break;
      }
   if(flag==0)
   {
      printf("-1\n");
      continue;
   }
   sum=0;
   for(c=1;c<=time;++c)
   {
      memset(value,0,sizeof(value));
	  memset(first,0,sizeof(first));
	  memset(last,0,sizeof(last));
	  k=0;n=0;
      for(i=1;i<=n1;++i)
		  if(a[i][c]>0)
		  {
			  first[i].beg=k+1;
			  first[i].end=first[i].beg+a[i][c]-1;
			  k=first[i].end;
			  n=n>first[i].end?n:first[i].end;
			  
		  }
	 // printf("%d\n",k);
	  k=0;
	  for(i=1;i<=m;++i)
		  if(b[i][c]>0)
		  {
			  last[i].beg=k+1;
			  last[i].end=last[i].beg+b[i][c]-1;
			  k=last[i].end;
			  n=n>last[i].end?n:last[i].end;
		  }
//	  printf("%d\n",k);
	  for(i=1;i<=n1;++i)
		  for(j=1;j<=m;++j)
		  {
			  w=v[c][i][j];
			  if(a[i][c]>0)
			  for(k=first[i].beg;k<=first[i].end;++k)
			      if(b[j][c]>0)
				  for(d=last[j].beg;d<=last[j].end;++d)
					  value[k][d]=-w;
		  }
	//	for(i=1;i<=n;++i)
	//	{
	//	   for(j=1;j<=n;++j)
	//		   printf("%d ",value[i][j]);
//		   printf("\n");
//		}
        for (i = 1; i<=n; i++) 
        { 
            lx[i] = -INF, ly[i] = 0; 
            for (j = 1; j <= n; j++) 
            { 
                lx[i] = lx[i]>value[i][j]?lx[i]:value[i][j]; 
            } 
        } 
    //  printf("%d\n",-KM());
        sum+=-KM();
   }
   printf("%d\n",sum);
  }
  return 0;
}

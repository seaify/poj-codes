#include<stdio.h>
#include<string.h>
#include<math.h>
const int INF=10000000;
int m,n,l[101],r[101],lx[101],ly[101],link[101];
int minx,hN,mN,value[110][110];
char map[101][101];
struct Node
{
  int x,y;
};
Node home[110],man[110];
int find(int cur)
{
 int i;
 l[cur]=true;
 for(i=1;i<=n;i++)
 {
   if(!r[i]&&lx[cur]+ly[i]==value[cur][i])
   {
	 r[i]=true;
	 if(link[i]==-1||find(link[i]))
	 {
		link[i]=cur;
		return 1;
	 }
   }
 }
 return 0;
}
void adjust()
{
  int i,j;
  minx=INF;
  for(i=1;i<=n;i++)
	  if(l[i])
	  {
		 for(j=1;j<=n;j++)
		   if(!r[j])
			   minx=minx<lx[i]+ly[j]-value[i][j]?minx:lx[i]+ly[j]-value[i][j];
	  }
  for(i=1;i<=n;i++)
	  if(l[i])
		  lx[i]-=minx;
	  else if(r[i])
		  ly[i]+=minx;
}
int KM()
{
  int i;
  memset(link,-1,sizeof(link));
  for(i=1;i<=n;i++)
   {
	memset(l,false,sizeof(l));
	memset(r,false,sizeof(r));
	while(!find(i))
	{
	  adjust();
	  memset(l,false,sizeof(l));
  	  memset(r,false,sizeof(r));
	}
   }
  int res = 0; 
    for (i = 1; i <= n; i++) 
            res += value[link[i]][i]; 
    return res; 
}
int main()
{
  int i,j;
  while(EOF!=scanf("%d%d",&n,&m))
  {
	if(n==0&&m==0)
		break;
    hN=0;mN=0;
    for (i = 1; i <= n; i++) 
        { 
            scanf("%s", &map[i][1]); 
            for (j = 1; j <= m; j++) 
                if (map[i][j] == 'H') 
                { 
                    home[++hN].x = i; 
                    home[hN].y = j; 
                } 
                else if (map[i][j] == 'm') 
                    { 
                        man[++mN].x = i; 
                        man[mN].y = j; 
                    }        
        } 
   n=hN;
   for (i = 1; i<=n; i++) 
        { 
            lx[i] = -INF, ly[i] = 0; 
            for (j = 1; j <= n; j++) 
            { 
                value[i][j] = -(abs(home[i].x - man[j].x) 
                            + abs(home[i].y - man[j].y)); 
                lx[i] = lx[i]>value[i][j]?lx[i]:value[i][j]; 
            } 
        } 
   printf("%d\n",-KM());
  }
  return 0;
}
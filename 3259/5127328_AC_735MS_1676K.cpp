#include<stdio.h>
#include<string.h>
const int INF=100000000;
int T,N,M,W,top,map[600][600],d[600];
struct node
{
   int x,y,v;
};
node e[10000];
void add(int i,int j,int value)
{
   	map[i][j]=++top;
	e[top].x=i;
	e[top].y=j;
	e[top].v=value;
}
int bellman(int s)
{
    int i,j,flag;
    for(i=1;i<=N;++i)
       d[i]=INF;
    d[s]=0;
    flag=1;
    for(i=1;i<N&&flag;++i)
    {
       flag=0;
       for(j=1;j<=top;++j)
         if(d[e[j].y]>d[e[j].x]+e[j].v)
             d[e[j].y]=d[e[j].x]+e[j].v,flag=1;
    }
    for(j=1;j<=top;++j)
      if(d[e[j].y]>d[e[j].x]+e[j].v)
          return 1;
    return 0;
}
int main()
{
   int i,j,value,t,cnt;
   scanf("%d",&T);
   while(T--)
   {
	 scanf("%d %d %d",&N,&M,&W);
	 memset(map,0,sizeof(map));
	 top=0;
	 while(M--)
	 {
	    scanf("%d %d %d",&i,&j,&value);
		if(map[i][j]==0)
		{
		    add(i,j,value);
	        add(j,i,value);
		}
		else if(e[map[i][j]].v>value)
		{
		    t=map[i][j];
			e[t].v=value;
			t=map[j][i];
			e[t].v=value;
		}
	 }
	 while(W--)
	 {
		scanf("%d %d %d",&i,&j,&value);
		value=-value;
		if(map[i][j]==0)
           add(i,j,value);
		else if(e[map[i][j]].v>value)
			e[map[i][j]].v=value;
	 }
	 cnt=0;
	 for(i=1;i<=N&&!cnt;++i)
	 {
         cnt=bellman(i);
     }
     if(cnt)
        printf("YES\n");
     else
        printf("NO\n");
   }
   return 0;
}

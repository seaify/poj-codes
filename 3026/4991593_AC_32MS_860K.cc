#include<stdio.h>
#include<string.h>
const int INF=1000000000;
int i,j,M,N,T,last,top,tag[100][100],v[2000][2000],min[2000];
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}}; 
char map[100][100];
bool flag[100][100],visit[2000];
struct node
{
  int x,y;
};
node edge[10000],queue[10000];
void BFS(int cur)
{
   int x,y,p,q,left,right,step,tot,cnt,temp,i,j;
   memset(flag,false,sizeof(flag));
   queue[0].x=edge[cur].x;queue[0].y=edge[cur].y;
   flag[queue[0].x][queue[0].y]=true;left=0;right=1;
   step=0;
   while(left<right)
   {
     ++step;cnt=right;
     for(j=left;j<right;++j)
      for(i=0;i<4;i++) //判断当前结点是否还可以扩展
      {
       p=queue[j].x+dir[i][0];
       q=queue[j].y+dir[i][1];   
       if(map[p][q]=='#'||p<1||p>M||q<1||q>N||flag[p][q])
               continue;
       queue[cnt].x=p;
       queue[cnt++].y=q;
       if(tag[p][q]>0)
          v[cur][tag[p][q]]=step;
       flag[p][q]=true;
      }
     left=right;
     right=cnt;
   }
}
void Prim(int last)
{
    int sum,c,k;
    memset(visit,false,sizeof(visit));
    for(i=1;i<=top;i++)
		min[i]=v[last][i];
    min[last]=0;visit[last]=true;
	sum=0;
	for(i=1;i<top;i++)
	{
		c=INF;
		for(j=1;j<=top;j++)
			if(!visit[j]&&min[j]<c)
			{
				c=min[j];
				k=j;
			}
	    sum=sum+c;
		visit[k]=true;
		for(j=1;j<=top;j++)
           if(!visit[j]&&v[k][j]<min[j])
			   min[j]=v[k][j];
	}
	printf("%d\n",sum);
}
int main()
{
  int i;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&N,&M);
    memset(tag,0,sizeof(tag));
    while(getchar() != '\n'){}//强悍。。。 
    top=0;
    for(i=1;i<=M;++i)
    {
      for(j=1;j<=N;++j)
      {
        scanf("%c",&map[i][j]);
        if(map[i][j]=='A'||map[i][j]=='S')
        {
           edge[++top].x=i;
           edge[top].y=j;
           tag[i][j]=top;
           if(map[i][j]=='S')
                last=top;
        }
      }
      getchar();
    }
    for(i=1;i<=top;++i)
    {
      for(j=1;j<=top;++j)
          v[i][j]=INF;
      v[i][i]=0;
    }
    for(i=1;i<=top;++i)
        BFS(i); 
   /* for(i=1;i<=top;++i)
    {
      for(j=1;j<=top;++j)
         printf("%d ",v[i][j]);
      printf("\n");
    }*/ 
    Prim(last);
  }
  return 0;
}


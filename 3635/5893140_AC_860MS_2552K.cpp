#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int p[1100];
int m,n,tot,P;
int C,S,T;
__int64 h[1100][110];

struct node
{
	int x;
	int y;
	node(int a=0,int b=0):x(a),y(b){};
};

vector < node > e[1100];

class heap
{
  private:
       node  array[110000];
       int pos[1100][110];
       int size;
  public:
       heap()
       {
           memset(pos,0,sizeof(pos));
           size=0;  
       }
       void Reset(int n,int C)
       {
            int i,j;
            for(i=0;i<n;i++)
               for(j=0;j<=C;j++)
                   pos[i][j]=0;
            size=0;
       }
       void push(const node &r)
       {
            int i;
			i=pos[r.x][r.y];
            if(pos[r.x][r.y]==0)
                 i=++size;
            while(i>1&&h[array[i/2].x][array[i/2].y]>h[r.x][r.y])
            {
                  array[i]=array[i/2];
                  pos[array[i].x][array[i].y]=i;
                  i=i/2;
            }
            pos[r.x][r.y]=i;
            array[i]=r;
       }
       const node &top()
       {
             return array[1];
       }
       void pop()
       {
            int i,ls;
            node r;
            r=array[size--];
			if(size==0)
				return;
            i=1;
            while(2*i<=size)
            {
               ls=2*i;
               if(ls+1<=size&&h[array[ls+1].x][array[ls+1].y]<h[array[ls].x][array[ls].y])
                    ls++;
               if(h[r.x][r.y]<h[array[ls].x][array[ls].y])
                     break;
               array[i]=array[ls];
               pos[array[i].x][array[i].y]=i;
               i=ls;       
            }
            array[i]=r;
            pos[r.x][r.y]=i;
       }
       bool empty()
       {
            return size==0;
       }
}Heap;


void bfs()
{
	 
	 int i,j,x,y,len,adj;
	 node tmp,vx;
	 if(S==T)
	 {
		 printf("0\n");
		 return ;
	 }
     Heap.Reset(n,C);
	 for(i=0;i<n;i++)
		 for(j=0;j<=C;j++)
			 h[i][j]=1000000000;
	 h[S][0]=0;
	 Heap.push(node(S,0));
	 while(!Heap.empty())
	 {
         
         x=Heap.top().x;
		 y=Heap.top().y;
		 Heap.pop();
		 if(x==T)
		 {
			 printf("%I64d\n",h[x][y]);
			 return ;
		 }
		 for(i=1;i+y<=C;i++)
		 {
			 if(h[x][y]+i*p[x]<h[x][y+i])
			 {
				 h[x][y+i]=h[x][y]+i*p[x];
				 Heap.push(node(x,y+i));
			 }
		 }
		 for(i=0;i<e[x].size();i++)
		 {
			 adj=e[x][i].x;
			 len=e[x][i].y;
			 if(y>=len&&h[x][y]<h[adj][y-len])
			 {
                 h[adj][y-len]=h[x][y];
				 Heap.push(node(adj,y-len));
			 }
		 }
	 }	
	 printf("impossible\n");
}

int main()
{
	int i,x,y,c;
    while(EOF!=scanf("%d %d",&n,&m))
	{
         for(i=0;i<n;i++)
		 {
			 scanf("%d",&p[i]);
			 e[i].clear();
		 }
		 while(m--)
		 {
			 scanf("%d %d %d",&x,&y,&c);  ////重边 
			 e[x].push_back(node(y,c));
			 e[y].push_back(node(x,c));
		 }
		 scanf("%d",&P);
		 while(P--)
		 {
             scanf("%d %d %d",&C,&S,&T);
  		     bfs();
		 }
	}
	return 0;
}



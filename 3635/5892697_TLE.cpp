
#include<stdio.h>
#include<string.h>
int p[110],first[1100];
int m,n,size,tot,P;
int C,S,T;
__int64 h[1100][110];

struct Q
{
	int x,y,c,next;
};

Q e[90000];

struct node
{
	int x;
	int y;
};

class heap
{
private:
    node arr[110000];
    int pos[1100][110];
    int size;
public:
    heap()
    {
        memset(pos,0,sizeof(pos));
        size = 0;
    }
    void Reset()
    {
        memset(pos,0,sizeof(pos));
        size = 0;
    }
    void push(const node &r)
    {
        int p = pos[r.x][r.y];
        if(pos[r.x][r.y] == 0) p = ++size;
        while(p/2>0 && h[arr[p/2].x][arr[p/2].y] > h[r.x][r.y])
        {
            arr[p] = arr[p/2];
            pos[arr[p].x][arr[p].y] = p;
            p = p/2;
        }
        arr[p] = r;
        pos[arr[p].x][arr[p].y] = p;
    }
    const node &top()
    {
        return arr[1];
    }
    void pop()
    {
        node t = arr[size--];
        int p = 1;
        for(int i=2*p;i<=size;i=2*p)
        {
            if(i+1<=size && h[arr[i].x][arr[i].y]>h[arr[i+1].x][arr[i+1].y]) ++i;
            if(h[t.x][t.y] < h[arr[i].x][arr[i].y]) break;
            arr[p] = arr[i];
            pos[arr[p].x][arr[p].y] = p;
            p = i;
        }
        arr[p] = t;
        pos[arr[p].x][arr[p].y] = p;
    }
    bool empty()
    {
        return size == 0;
    }
}Heap;


void add(int x,int y,int c)
{
	e[++tot].x=x;
	e[tot].y=y;
	e[tot].c=c;
	e[tot].next=first[x];
	first[x]=tot;
}

void bfs()
{
	 
	 int i,j,x,y,nb,len,adj;
	 node tmp,vx;
	 if(S==T)
	 {
		 printf("0\n");
		 return ;
	 }
     Heap.Reset();
	 for(i=1;i<=n;i++)
		 for(j=0;j<=C;j++)
			 h[i][j]=1000000000;
	 h[S][0]=0;
	 tmp.x=S;
	 tmp.y=0;
	 Heap.push(tmp);
	 while(!Heap.empty())
	 {
         tmp=Heap.top(); 
         x=tmp.x;
		 y=tmp.y;
		 Heap.pop();
		 if(x==T)
		 {
			 printf("%I64d\n",h[x][y]);
			 return ;
		 }
		 for(i=1;i+y<=C;i++)
		 {
             vx.x=x;
			 vx.y=y+i;
			 if(h[x][y]+i*p[x]<h[vx.x][vx.y])
			 {
				 h[vx.x][vx.y]=h[x][y]+i*p[x];
				 Heap.push(vx);
			 }
		 }
		 nb=first[x];
		 while(nb!=-1)
		 {
			 adj=e[nb].y;
			 len=e[nb].c;
			 if(y>=len)
			 {
				 vx.x=adj;
				 vx.y=y-len;
				 if(h[x][y]<h[vx.x][vx.y])
				 {
					 h[vx.x][vx.y]=h[x][y];
					 Heap.push(vx);
				 }
			 }
			 nb=e[nb].next;
		 }
	 }	
	 printf("impossible\n");
}

int main()
{
	int i,x,y,c;
    while(EOF!=scanf("%d %d",&n,&m))
	{
         for(i=1;i<=n;i++)
		 {
			 scanf("%d",&p[i]);
			 first[i]=-1;
		 }
		 tot=0;
		 while(m--)
		 {
			 scanf("%d %d %d",&x,&y,&c);  ////重边 
			 add(x+1,y+1,c);
			 add(y+1,x+1,c);
		 }
		 scanf("%d",&P);
		 while(P--)
		 {
             scanf("%d %d %d",&C,&S,&T);
			 S++;
			 T++;
  		     bfs();
		 }
	}
	return 0;
}


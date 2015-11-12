#include<stdio.h>
#include<string.h>
int p[110],first[1100];
int m,n,tot,P;
int C,S,T;
__int64 h[1100][110];

struct Q
{
	int x,y,len,next;
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


void add(int x,int y,int c)
{
	e[++tot].x=x;
	e[tot].y=y;
	e[tot].len=c;
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
     Heap.Reset(n,C);
	 for(i=0;i<n;i++)
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
			 len=e[nb].len;
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
         for(i=0;i<n;i++)
		 {
			 scanf("%d",&p[i]);
			 first[i]=-1;
		 }
		 tot=0;
		 while(m--)
		 {
			 scanf("%d %d %d",&x,&y,&c);  ////重边 
			 add(x,y,c);
			 add(y,x,c);
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



#include<stdio.h> 
const int INF=1000000000; 
const int maxn=30005; 
int m,n,top,len,pos[maxn],dis[maxn],tot; 
int first[maxn],last;
bool flag;
struct node 
{ 
  int value,index; 
};
struct edge
{
  int x,y,next,value;
};
node queue[maxn],res; 
edge g[150002];
void add(int x,int y,int value)//加入边
{
	++tot;
	g[tot].x=x;
	g[tot].y=y;
	g[tot].value=value;
	g[tot].next=first[x];
	first[x]=tot;
}
void update(int i,int min)//交换queue[i]和queue[min],并修改pos,
{ 
   node temp; 
   pos[queue[i].index]=min;pos[queue[min].index]=i; 
   temp=queue[i];queue[i]=queue[min];queue[min]=temp; 
} 
void down(int i) 
{ 
  int l,r,min; 
  while(1) 
  { 
    l=2*i; 
    r=2*i+1; 
    if(l<=len&&queue[l].value<queue[i].value) 
        min=l; 
    else 
        min=i; 
    if(r<=len&&queue[r].value<queue[min].value) 
        min=r; 
    if(min!=i) 
    { 
       update(i,min); 
       i=min;//更新当前结点
    } 
    else 
       break; 
} 
} 
void Extract_min() 
{ 
   res=queue[1];//
   pos[queue[len].index]=1; 
   pos[res.index]=len; 
   queue[1]=queue[len]; 
   --len; 
   down(1); 
} 
void change(int i) 
{ 
   while(i>1&&queue[i/2].value>queue[i].value) 
   { 
      update(i,i/2); 
      i=i/2; 
   } 
} 
void Try(int beg,int end)
{ 
   int i,c,cnt,x,y;
   for(i=1;i<=n;i++)//初始化
   { 
        queue[i].index=i;//queue[i].index表示堆中的第i个位置在数组的位置
        queue[i].value=INF; 
        dis[i]=INF; 
        pos[i]=i; //pos[i]表示数组中的第i个元素在堆中的位置
   } 
   queue[beg].value=0; 
   dis[beg]=0;len=n; 
   if(flag)
	   update(1,n);
   flag=true;
   for(i=1;i<=n;i++)
    { 
        Extract_min(); 
        c=res.index; 
        cnt=first[c];
		while(cnt!=-1)
		{
		  x=g[cnt].x;y=g[cnt].y;
          if(res.value+g[cnt].value<dis[y]) 
           { 
             dis[y]=queue[pos[y]].value=res.value+g[cnt].value; 
             change(pos[y]);//调整堆
           } 
		 cnt=g[cnt].next;
     } 
   }
   if(dis[end]!=INF&&last<dis[end])
	     last=dis[end];
}

int main() 
{ 
   int i,j,value; 
   scanf("%d%d",&n,&m);
   tot=0;
   for(i=1;i<=n;i++)
	   first[i]=-1;
   while(m--)
   {
	 scanf("%d%d%d",&i,&j,&value);
     add(i,j,value);
   }
   last=-1;
   flag=false;
   Try(1,n);
   Try(n,1);
   printf("%d\n",last);
   return 0; 
}


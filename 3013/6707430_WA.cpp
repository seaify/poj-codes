#include<stdio.h> 
const long long INF=100000000000LL; 
const long long maxn=200005; 
long long m,n,top,len,pos[maxn],dis[maxn],tot,v[maxn]; 
long long first[maxn];
struct node 
{ 
  long long value,index; 
};
struct edge
{
  long long x,y,next,value;
};
node queue[maxn],res; 
edge g[150002];
void add(long long x,long long y,long long value)//加入边
{
	++tot;
	g[tot].x=x;
	g[tot].y=y;
	g[tot].value=value;
	g[tot].next=first[x];
	first[x]=tot;
}
void update(long long i,long long min)//交换queue[i]和queue[min],并修改pos,
{ 
   node temp; 
   pos[queue[i].index]=min;pos[queue[min].index]=i; 
   temp=queue[i];queue[i]=queue[min];queue[min]=temp; 
} 
void down(long long i) 
{ 
  long long l,r,min; 
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
void change(long long i) 
{ 
   while(i>1&&queue[i/2].value>queue[i].value) 
   { 
      update(i,i/2); 
      i=i/2; 
   } 
} 
int main() 
{ 
   long long i,j,value,c,cnt,x,y,T,sum; 
   scanf("%lld",&T);
   while(T--)
   {
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;++i)
       scanf("%d",&v[i]);
    tot=0;
    for(i=1;i<=n;i++)
	   first[i]=-1;
    while(m--)
    {
	 scanf("%lld %lld %lld",&i,&j,&value);
     add(i,j,value);
    }
    for(i=1;i<=n;i++)//初始化
    { 
        queue[i].index=i;//queue[i].index表示堆中的第i个位置在数组的位置
        queue[i].value=INF; 
        dis[i]=INF; 
        pos[i]=i; //pos[i]表示数组中的第i个元素在堆中的位置
    } 
    queue[1].value=0; 
    dis[1]=0;
    len=n; sum=0;
    for(i=1;i<=n;i++)
     { 
        Extract_min(); 
        c=res.index; 
        if(res.value==INF)
              break;
        cnt=first[c];
        sum+=v[c]*res.value;
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
     if(i==n+1)
       printf("%lld\n",sum);
     else
       printf("No Answer\n");
   }
   return 0; 
}


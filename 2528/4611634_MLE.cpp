#include<stdio.h>
const int maxn=10000000;
int i;bool flag;
struct node
{
int low,high,left,right,count;
bool mark;
}a[4*maxn];
void init(int low,int high,int i)//初始化
{
int mid;
a[i].left=2*i;
a[i].right=2*i+1;
a[i].low=low;
a[i].high=high;
a[i].count=0;
a[i].mark=true;
if(low==high)
   return ;
mid=(low+high)/2;
init(low,mid,2*i);
init(mid+1,high,2*i+1);
}
int insert(int l,int r,int x,int y,int k)//更新一个区间
{
if(x<=r&&l<=y)
{
if(a[k].mark&&x<=l&&r<=y)//必需保证该区间内的值相同，即a[k].mark为true,如果为false时，其许多子区间未更新
{
   a[k].count=i;
   a[k].mark=true;
   return 0;
}
if(a[k].mark)//因为需要修改，故值向下传
{
    a[k].mark=false;
    a[2*k].count=a[2*k+1].count=a[k].count;
    a[2*k].mark=a[2*k+1].mark=true;
}
insert(a[a[k].left].low,a[a[k].left].high,x,y,2*k);
insert(a[a[k].right].low,a[a[k].right].high,x,y,2*k+1);
if(a[2*k].mark&&a[2*k+1].mark&&a[2*k].count==a[2*k+1].count)//合并两段区间
{
   a[k].count=a[2*k].count;
   a[k].mark=true;
}
}
return 0;
}
int search(int l,int r,int x,int y,int k)//觉得应该可以将所求区间和树一起分解加速运行，
{
if(x<=r&&l<=y)
{
if(a[k].mark)//a[i].mark==true 表示其区间内颜色相同
{
   if(x<=l&&r<=y)
   {
   if(a[k].count<=i)
    flag=false;
    return 0;
   }
     if(l<=x&&y<=r)//应该可以加速些，当所求区间被该结点覆盖，直接判断
   {
    if(a[k].count<=i)
     flag=false;
    return 0;
   }
}
if(flag==false)
   return 0;
search(a[a[k].left].low,a[a[k].left].high,x,y,2*k);
if(flag==false)
   return 0;
search(a[a[k].right].low,a[a[k].right].high,x,y,2*k+1);
}
return 0;
}
int main()
{
int t,b[10010],c[10010],n,sum,max;
scanf("%d",&t);
while(t--)
{
   scanf("%d",&n);
   max=0;
   for(i=1;i<=n;i++)
   {
    scanf("%d%d",&b[i],&c[i]);
    if(c[i]>max)
     max=c[i];
   }
   init(1,max,1);
   for(i=1;i<=n;i++)
   {
    insert(1,max,b[i],c[i],1);
   }
   sum=0;
   for(i=1;i<=n;i++)
   {
    flag=true;
    search(1,max,b[i],c[i],1);
          if(flag)
    sum++;
   }
   printf("%d\n",n-sum);
}
return 0;
} 

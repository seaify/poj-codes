#include<stdio.h>
#include<string.h>
#include<math.h>
const int max=100000;
int T,a,b;
bool flag[max],tag[110000];
int prime[11000],j,top,queue[510000];
void init()
{
 int i,k;
 memset(flag,true,sizeof(flag));//生成素数,共9592 个 
 flag[1]=false;
 k=int(sqrt(max));
 for(i=2;i<=k;i++)
 {
   if(flag[i])
   {
    j=i*i;
    while(j<=max)
    {
     flag[j]=false;
     j=j+2*i;
    }
   }
 }
 k=1;
 prime[1]=2;
  for(i=3;i<=max;i=i+2)
    if(flag[i])//为true表示是素数。。。 
        prime[++k]=i;
 top=k;
}
int bfs()
{
   int i,k,beg,end,x,temp,step,last,ia,ib,ic,id;
   if(a==b) 
     return 0;
   memset(tag,false,sizeof(tag));
   queue[0]=a;tag[a]=true;
   beg=0;end=1;step=0;
   while(beg<end)
   {
      ++step;
      if(tag[b])
          return step;
      last=end;
      for(i=beg;i<end;++i)//可能产生的结果小于大于K 
      {
         ia=queue[i]/1000;id=queue[i]%10;
         ic=((queue[i]-id)%100)/10;ib=(queue[i]-id-ia*1000-ic*10)/100;
         for(j=1000;j>0;j/=10)
           for(k=0;k<=9;++k)
           {
              if((j==1000&&k==0)||(j==1&&k%2==0))
                  continue;
              if(j==1000)
                  x=queue[i]+(k-ia)*1000;
              else if(j==100)
                  x=queue[i]+(k-ib)*100;
              else if(j==10)
                  x=queue[i]+(k-ic)*10;
              else 
                  x=queue[i]+k-id;
              if(!flag[x])
                  continue;
              if(!tag[x])
                {
                  tag[x]=true;
                  queue[last]=x;
                  ++last;
                }
              if(tag[b])
                  return step;     
           }
      }
      beg=end;
      end=last;
   }  
}
int main()
{
    init();
    scanf("%d",&T);
    while(T--)
    {
      scanf("%d%d",&a,&b);
      printf("%d\n",bfs());
    }
    return 0;
}

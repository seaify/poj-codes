#include<set>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1000010;

int L[maxn],R[maxn],head[maxn],tail[maxn];
int pos[maxn],num[maxn],self[maxn];
char cc[maxn],color[maxn];
int n;

struct node
{
    int no,pos,num;
    char color;
    
    friend bool operator < (const node &a,const node &b)
    {
         if(a.num!=b.num)
              return a.num<b.num;
         else
              return a.pos>b.pos;
    }
};

node a[maxn],b,c;
set < node > H;
set < node > :: const_iterator it;


void del(node b)
{
     int i,l,r,tmp;
     printf("%c",b.color);
     tmp=b.no;
     while(1)
     {
         b.num-=self[tmp];
         for(i=0;i<self[tmp];i++)
             printf(" %d",pos[tmp]+i);
         if(b.num==0)
             break;
         tmp=R[tmp];
     }
     
     l=L[b.no];
     r=R[tmp];
     
     R[l]=r;
     L[r]=l;
     
     if(color[r]==color[l])
     {
        c.c
     }
     
     printf("\n");
}

int main()
{
    int n,i,hh,len;
    
    while(EOF!=scanf("%s",cc))
    {
        n=0;
        hh=1;
        len=strlen(cc);
        cc[len++]='W';
    
        for(i=0;i<=len;i++)
            L[i]=i-1,R[i]=i+1,head[i]=tail[i]=i;
        
        for(i=1;i<len;i++)
        {
            if(cc[i]==cc[i-1])
                 hh++;
            else
            {
                 ++n;
                 self[n]=num[n]=hh;
                 color[n]=cc[i-1];
                 pos[n]=i-hh+1;///偏离量为1 
                 hh=1; 
            }
        }
        
        for(i=1;i<=n;i++)
            printf("%d %d %c\n",self[i],pos[i],color[i]);
        
        H.clear();
        
        for(i=1;i<=n;i++)
        {
            b.color=color[i];
            b.num=num[i];
            b.pos=pos[i];
            b.no=i;
            H.insert(b);
        }
        
     /*   for(it=H.begin();it!=H.end();it++)
        {
            b=*it;  
            printf("%d %d %c\n",b.num,b.pos,b.color);
        }*/
        printf("\n");
        
        while(!H.empty())
        {
            it=--H.end();
            b=*it;
            if(b.num==1)
               break;
               
            del(b);
            
            H.erase(it);
        }
       
        
        
    }
    return 0;
}

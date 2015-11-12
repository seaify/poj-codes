#include<stdio.h>
#include<string.h>
#include<set>
#include<algorithm>
using namespace std;

const int maxn=1000010;

int L[maxn],R[maxn],head[maxn],tail[maxn];
int pos[maxn],num[maxn],self[maxn];
char cc[maxn],color[maxn];
int n;

struct cmp
{
    
     bool operator() (const int &x,const int &y)
    {
         if(num[x]!=num[y])
              return num[x]<num[y];
         else
              return pos[x]>pos[y];
    }
};

set < int ,cmp > H;
set < int ,cmp > :: const_iterator it;


void del(int no)
{
     int i,l,r,tmp,sum;
	 //printf("no :%d\n",no);
     printf("%c",color[no]);
     tmp=no;
     while(1)
     {
         num[no]-=self[tmp];
         for(i=0;i<self[tmp];i++)
             printf(" %d",pos[tmp]+i);
         if(num[no]==0)
             break;
         tmp=R[tmp];
     }
     
     l=L[no];
     r=R[tmp];
     
     R[l]=r;
     L[r]=l;
	
	 
     if(l!=0&&r!=n+1&&color[r]==color[l])
     {
		 H.erase(head[l]);
		 H.erase(r);
		 sum=num[l]+num[r];
         head[tail[r]]=head[l];
		 num[tail[r]]=sum;
		 tail[head[l]]=tail[r];
		 num[head[l]]=sum;
		 H.insert(head[l]);
     }
     
     printf("\n");
}

int main()
{
    int i,b,hh,len;

    
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
        
        
        H.clear();
        
        for(i=1;i<=n;i++)
            H.insert(i);
        
        while(!H.empty())
        {
            it=--H.end();
            b=*it;
            if(num[b]==1)
               break;
               
            H.erase(it);
			del(b);
        }
       
        
    }
    return 0;
}

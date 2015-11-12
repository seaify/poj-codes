#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
int n,tot,p[1100000];
map < int,int > q;

class heap
{
  public:
       int array[1100000];
       int pos[1100000];
       int size;
       void Reset(int n)
       {
            int i;
            for(i=0;i<n;i++)
                pos[i]=0;
            size=0;
       }
       void push(const int &r)  ////插入r 
       {
            int i,ls;
			i=pos[p[r]];
            if(pos[p[r]]==0)
                 i=++size;
            while(2*i<=size)
            {
               ls=2*i;
               if(ls+1<=size&&array[ls+1]<array[ls])
                    ls++;
               if(r<=array[ls])
                     break;
               array[i]=array[ls];
               pos[array[i]]=i;
               i=ls;       
            }
            array[i]=r;
            pos[p[r]]=i;
       }
       const int &top()
       {
             return array[1];
       }
       bool empty()
       {
            return size==0;
       }
}Heap;


int main()
{
    int i,x,ans;
    while(EOF!=scanf("%d",&n))
    {
          q.clear();
          tot=-1;
          for(i=0;i<n;i++)
          {
              scanf("%d",&x);
              if(q.count(x))
                  p[i]=q[x];
              else
              {
                  q[x]=++tot;
                  p[i]=tot;
              }
          }
          ++tot;   ///共tot个... 
          ans=n;
          Heap.Reset(tot);
          for(i=0;i<n;i++)
          {
              Heap.push(i);
              if(Heap.size==tot&&i-Heap.top()+1<ans)
                    ans=i-Heap.top()+1;
          }
          printf("%d\n",ans);                                                                  
    }
    return 0;
}

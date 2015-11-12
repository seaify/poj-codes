#include<iostream>
using namespace std;

template <class TYPE>
class DHeap
{
  private:
    TYPE *heap;
    unsigned int max;
    unsigned int cur;
    void insL(const TYPE& e,unsigned int i)
    {
      unsigned int j=i>>1;
      while(j>1&&heap[j]>e)
      {
        heap[i]=heap[j];
        i=j;
        j>>=1;
      }
      heap[i]=e;
    }
    void insR(const TYPE& e,unsigned int i)
    {
      unsigned int j=i>>1;
      while(j>1&&e>heap[j])
      {
        heap[i]=heap[j];
        i=j;
        j>>=1;
      }
      heap[i]=e;
    }
    unsigned int bits(unsigned int i)
    {
      __asm("bsrl %1, %0"
           :"=r"(i)
           :"r"(i)
           );
      return i;
    }
    unsigned int partner(unsigned int i)
    {
      return i^(1<<(bits(i)-1));
    }
    unsigned int inR(unsigned int i)
    {
      return i&(1<<(bits(i)-1));
    }
  public:
    DHeap(unsigned int num)
    {
      max=num;
      heap=new TYPE[max+2];
      cur=1;
    }
    DHeap(){DHeap(128);}
    ~DHeap(){delete [] heap;}
    const TYPE& operator[] (unsigned int i)
    {return i>cur?heap[0]:heap[i];}
    void Clear(){cur=1;}
    void SetZero(const TYPE& e){heap[0]=e;}
    void SetInf(const TYPE& e){heap[1]=e;}
    unsigned int Len(){return cur;}
    void Double()
    {
      unsigned int i;
      TYPE *temp;
      max<<=1;
      temp=new TYPE[max+2];
      for(i=0;i<=cur;++i)
        temp[i]=heap[i];
      delete [] heap;
      heap=temp;
    }
    void Push(const TYPE& e)
    {
      unsigned int i,j;
      if(cur+1>max) Double();
      ++cur;
      if(cur==2)
        heap[2]=e;
      else
      {
        if(inR(cur))
        {
          i=partner(cur);
          if(e>heap[i])
            insR(e,cur);
          else
          {
            heap[cur]=heap[i];
            insL(e,i);
          }
        }
        else
        {
          i=partner(cur)>>1;
          if(heap[i]>e)
            insL(e,cur);
          else
          {
            heap[cur]=heap[i];
            insR(e,i);
          }
        }
      }
    }
    TYPE Pop_min()
    {
      if(cur<2) return heap[0];
      TYPE a=heap[2];
      TYPE& b=heap[cur--];
      unsigned int i=2,j=4;
      while(j<=cur)
      {
        if(j<cur&&heap[j]>heap[j+1])
          ++j;
        heap[i]=heap[j];
        i=j;
        j<<=1;
      }
      j=partner(i);
      if(j>cur&&cur>2)j>>=1;
      if(b>heap[j])
      {
        heap[i]=heap[j];
        insR(b,j);
      }
      else
        insL(b,i);
      return a;
    }
    TYPE Pop_max()
    {
      if(cur<2) return heap[1];
      if(cur<4) return heap[cur--];
      TYPE a=heap[3];
      TYPE& b=heap[cur--];
      unsigned int i=3,j=6;
      while(j<=cur)
      {
        if(j<cur&&heap[j+1]>heap[j])
          ++j;
        heap[i]=heap[j];
        i=j;
        j<<=1;
      }
      j=partner(i);
      if((j<<1)<=cur)
      {
        j<<=1;
        if(j<cur&&heap[j+1]>heap[j])
          ++j; 
      }
      if(b>heap[j])
        insR(b,i);
      else
      {
        heap[i]=heap[j];
        insL(b,j);
      }
      return a;
    }
    void ShowTree()
    {
      for(unsigned int i=1;i<=cur;i++)
      {
        if(!(i&(i+1))) cout<<heap[i]<<endl;
        else cout<<heap[i]<<",";
      }
      if(cur&(cur+1))cout<<endl;
    }
};

struct PPP
{
  int k,p;
  bool operator> (const PPP& x) const
  {return p>x.p;}
  friend ostream& operator<< (ostream& o,PPP& x)
  {
    o<<"["<<x.k<<","<<x.p<<"]";
    return o;
  }
}X;


main()
{
  int i,j,k,p,n;
  DHeap<PPP> h(8192);
  X.k=X.p=0;
  h.SetZero(X);
  h.SetInf(X);
  while(scanf("%d",&n)&&n)
  {
    if(n==1)
    {
      scanf("%d%d",&k,&p);
      X.k=k;X.p=p;
      h.Push(X);
    }
    else if(n==2)
      printf("%d\n",h.Pop_max().k);
    else if(n==3)
      printf("%d\n",h.Pop_min().k);
  }
}

#include<iostream>
#include<math.h>

const int MOD=99991;

int P,B,N,m,tot;
int hash[120000],first[120000],next[120000],key[120000];

void insert(int tmp,int j)
{
    int x;
    x=tmp%MOD;
    if(hash[x]==0)
    {
       hash[x]=tmp;
       key[x]=j;
	   next[x]=-1;
	   first[x]=x;
    }
    else
    {
       hash[++tot]=tmp;
       key[tot]=j;
       next[tot]=first[x];
       first[x]=tot;
    }
}

int find(int tmp)
{  
    int x,ans;
    
    x=tmp%MOD;
    ans=first[x];
    
    while(ans!=-1)
    {
          if(hash[ans]==tmp)
             return key[ans];
          ans=next[ans];
    }
    
    return -1;
         
}

int solve(int a,int n)
{
    int result=1;
    while(n)
    {
         if(n&1)
            result=(__int64)result*a%P;
         a=(__int64)a*a%P;
         n>>=1; 
    }
    return result;
}

int main()
{
    int i,j,y,tmp,res;
    
    while(EOF!=scanf("%d %d %d",&P,&B,&N))
    {
          if(N==1)
          {
              printf("0\n");
              continue;
          }                 

		  if(P<=100000)
		  {
			  res=1;
			  for(i=1;i<P;i++)
			  {
				  res=(__int64)res*B%P;
				  if(res==N)
				  {
					  printf("%d\n",i);
					  break;
				  }
			  }
			  if(i>=P)
				    printf("no solution\n");
			  continue;

		  }
          m=int(ceil(sqrt(P*1.0)));
          
          for(i=0;i<MOD;i++)
              hash[i]=0,first[i]=-1;
          tot=MOD-1;
          
          hash[1]=1;
          key[1]=0;
          tmp=1;
          
          for(j=1;j<m;j++)
          {
             tmp=(__int64)tmp*B%P;
             insert(tmp,j);
          }
          
          y=N;
          res=solve(B,P-1-m);
          
          for(i=0;i<m;i++)
          {
              j=find(y);
              if(j>=0)
              {
                 printf("%d\n",(i*m+j)%(P-1));
                 break;
              }
              y=(__int64)y*res%P;
                         
          }
          
          if(i>=m)
              printf("no solution\n");
          
             
          
    }
    return 0;
}


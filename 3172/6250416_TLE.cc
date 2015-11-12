#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;

set < int > H,W;
set < int > ::iterator it;

int a[100];
int N,C,ans;


int main()
{
    int i,flag;
    
    while(EOF!=scanf("%d %d",&N,&C))
    {
          flag=0;
          for(i=1;i<=N;i++)
          {
              scanf("%d",&a[i]);
              if(a[i]==C)
                  flag=1;
          }
          if(flag)
          {
              printf("%d\n",C);
              continue;
          }
          
          for(i=1;i<=N;i++)
              if(a[i]>C)
                   break;
                   
          N=i-1;

		  H.clear();
		  H.insert(0);

		  for(i=1;i<=N;i++)
		  {
			  W=H;
			  for(it=H.begin();it!=H.end();it++)
			  {
				  if(*it+a[i]<=C)
					  W.insert(*it+a[i]);
				  else
					  break;
			  }
			  H=W;
		  }

		 // for(it=H.begin();it!=H.end();it++)
		//	  printf("%d ",*it);
		  //printf("\n");

		  it=H.end();
		  it--;
		  printf("%d\n",*it);
          
         
                     
    }

	return 0;
 
}

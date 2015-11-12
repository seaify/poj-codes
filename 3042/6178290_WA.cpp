#include<iostream>
#include<algorithm>
using namespace std;

__int64 N,L,ans,pos;
__int64 ls,rs; 
__int64 x[1100];
__int64 f[1100][1100][2];

__int64 min(__int64 a,__int64 b)
{
    if(a<b)
       return a;
    return b;
}

void debug()
{
    int i,j;
    for(i=1;i<=pos;i++)
      for(j=pos;j<=N;j++)
        printf("%d %d\n",f[i][j][0],f[i][j][1]);
}

int main()
{
    __int64 i,j,k,flag,t1,t2;

	freopen("ontherun.9.in","r",stdin);
	freopen("check.txt","w",stdout);

    while(EOF!=scanf("%I64d %I64d",&N,&L))
    {
        
        flag=1;
        
        for(i=1;i<=N;i++)
        {
            scanf("%I64d",&x[i]);
            if(x[i]==L)
              flag=0; 
        }
        
        if(flag)
            x[++N]=L;
            
        sort(x+1,x+N+1);
        
        for(i=2;i<=N;i++)
          if(x[i]==x[i-1])
          {
            //printf("YES\n");
            break;
          }
        
        for(i=1;i<=N;i++)
            if(x[i]==L)
            {
                pos=i;
              //  printf("%I64d\n",pos);
                break;
            }
            
        f[pos][pos][0]=0;
        f[pos][pos][1]=0;
        ls=pos-1;
        rs=pos+1;
        t1=0;
        t2=0;
        
        while(1)
        {
           if(rs>N)
           {
              t2=1; 
             
           }
           
           if(ls<1)
           {
              t1=1;
          
           }
           
           if(t1==1&&t2==1)
              break;
              
           if(t2==0)
           {
			 if(t1==1)
				 ls=0;
             for(i=ls+1;i>=1&&i<=pos;i++)
             {
               k=N-rs+i;
               f[i][rs][1]=min(f[i][rs-1][0]+k*(x[rs]-x[i]),f[i][rs-1][1]+k*(x[rs]-x[rs-1]));
             }
			 f[pos][rs][0]=(N-rs+pos-1)*(x[rs]-x[pos]);
			 for(j=pos+1;j<=rs;j++)
				 f[pos][rs][0]+=(x[j]-x[j-1])*(N-j+pos);
             //f[pos][rs][0]=f[pos][rs-1][0]+(N-rs+pos)*(x[rs]-x[]);
             for(i=pos-1;i>=ls+1;i--)
             {
               k=N-rs+i;
               f[i][rs][0]=min(f[i+1][rs][0]+k*(x[i+1]-x[i]),f[i+1][rs][1]+k*(x[rs]-x[i]));
             }
           }
           
           if(t1==0)
           {
			  if(t2==1)
				  rs=N;
              for(j=pos;j<=rs;j++)
              {
                  k=N-j+ls;
                  f[ls][j][0]=min(f[ls+1][j][0]+k*(x[ls+1]-x[ls]),f[ls+1][j][1]+k*(x[j]-x[ls]));
              }       
              f[ls][pos][1]=f[ls][pos][0]+(N-pos+ls-1)*(x[pos]-x[ls]); 
              for(j=pos+1;j<=rs;j++)
              {
                  k=N-j+ls;
                  f[ls][j][1]=min(f[ls][j-1][0]+k*(x[j]-x[i]),f[i][j-1][1]+k*(x[j]-x[j-1])); 
              } 
           }
           
           rs++;
           ls--;
           
        
           
        }

	//	debug();
        
        ans=min(f[1][N][1],f[1][N][0]);
        
        printf("%I64d\n",ans);
             
    }
    return 0;
}



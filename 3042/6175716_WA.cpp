#include<iostream>
#include<algorithm>
using namespace std;

const int INF=2000000000;

int N,L,ans,pos;
int x[1100];
int f[1100][1100][2];

void debug()
{
    int i,j;
    for(i=1;i<=pos;i++)
      for(j=pos;j<=N;j++)
        printf("%d %d\n",f[i][j][0],f[i][j][1]);
}

int main()
{
    int i,j,k,flag;
    while(EOF!=scanf("%d %d",&N,&L))
    {
        
        flag=1;
        
        for(i=1;i<=N;i++)
        {
            scanf("%d",&x[i]);
            if(x[i]==L)
              flag=0; 
        }
        
        if(flag)
            x[++N]=L;
            
        sort(x+1,x+N+1);
        
        for(i=1;i<=N;i++)
            if(x[i]==L)
            {
                pos=i;
                break;
            }
            
        f[pos][pos][0]=0;
        f[pos][pos][1]=0;

		for(i=pos-1;i>=1;i--)
		{
			f[i][pos][0]=f[i+1][pos][0]+(N-pos+i)*(x[i+1]-x[i]);
			f[i][pos][1]=f[i][pos][0]+(N-pos+i-1)*(x[pos]-x[i]);  ////
		//	printf("%d %d\n",f[i][pos][0],f[i][pos][1]);
		}

		printf("\n");

		for(j=pos+1;j<=N;j++)
		{
            for(i=1;i<=pos;i++)
			{
				k=j-i;
				f[i][j][1]=f[i][j-1][0]+(N-k)*(x[j]-x[i]);
				if(f[i][j-1][1]+(N-k)*(x[j]-x[j-1])<f[i][j][1])
					f[i][j][1]=f[i][j-1][1]+(N-k)*(x[j]-x[j-1]);
			}
			k=N-j+pos-1;
			f[pos][j][0]=f[pos][j][1]+k*(x[j]-x[pos]);
			for(i=1;i<pos;i++)
			{
				k=j-i;
				f[i][j][0]=f[i+1][j][0]+(N-k)*(x[i+1]-x[i]);
				if(f[i+1][j][1]+(N-k)*(x[j]-x[i])<f[i][j][0])
					f[i][j][0]=f[i+1][j][1]+(N-k)*(x[j]-x[i]);

			}

		/*	for(i=1;i<=pos;i++)
				printf("%d %d\n",f[i][j][0],f[i][j][1]);
			printf("\n");*/
		}
        
     //   debug();
        
        ans=f[1][N][0];
        
        if(ans>f[1][N][1])
           ans=f[1][N][1];
        
        printf("%d\n",ans);
             
    }
    return 0;
}


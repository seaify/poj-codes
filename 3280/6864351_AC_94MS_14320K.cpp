#include<stdio.h>

#define min(a,b) a<b?a:b;
const int INF=2000000000;

int N,M;
int del[300],add[300],f[2100][2100];
char ch[4000];

int main()
{
	int i,j,k,x,y;
	char s[10];

	while(EOF!=scanf("%d %d",&N,&M))
	{
		scanf("%s",ch);
		while(N--)
		{
			scanf("%s %d %d",s,&x,&y);
            add[s[0]]=x;
			del[s[0]]=y;
		}
		for(i=0;i<M;i++)
			f[i][i]=0;

		for(k=1;k<M;k++)
			for(i=0;i+k<M;i++)
			{
				j=i+k;
				f[i][j]=INF;
				if(ch[i]==ch[j])
				{
					if(k==1)
						 f[i][j]=0;
					else
                         f[i][j]=f[i+1][j-1];
				}
				x=min(f[i][j-1]+del[ch[j]],f[i][j-1]+add[ch[j]]);
				y=min(f[i+1][j]+del[ch[i]],f[i+1][j]+add[ch[i]]);
				x=min(x,y);
				f[i][j]=min(x,f[i][j]);
			}
		printf("%d\n",f[0][M-1]);
	}
	return 0;
}
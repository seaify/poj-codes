#include <stdio.h>
#include <string.h>
const int INF=100000000;

int N, augc, found, ans, h[2010], vh[2010]; 
int c[1100][1100];

void aug(int cur)
{
	int i, minh = N+1 , augco = augc; 
	if (cur == N) 
	{
		found = 1; 
		ans += augc; 
		return; 
	}
	for(i=1;i<=N;++i)
		if(c[cur][i]>0)
		{
			if (h[i] + 1 == h[cur])
			{
				if(c[cur][i]<augc)
				   augc = c[cur][i]; 
				aug(i); 
				if (h[1] >= N) 
					return; 
				if (found) 
					break; 
				augc = augco; 
			}
			if(h[i]<minh)
			   minh = h[i]; 
		}
	if (!found)
	{
		vh[h[cur]]--; 
		if (vh[h[cur]] == 0) 
			h[1] = N; 
		h[cur] = minh + 1; 
		vh[h[cur]]++; 
	}
	else
	{
		c[cur][i] -= augc; 
		c[i][cur] += augc; 
	}
}
int main()
{
	//freopen("test.in", "r", stdin); 
	//freopen("ans.txt", "w", stdout); 
	int  m,x,y,v; 
	while (scanf("%d %d", &m, &N))
	{
	    memset(c,0,sizeof(c)); ////容量c
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&v);
			c[x][y]+=v;   ///容量加
		}
		memset(h, 0, sizeof(int) * (N+1)); 
		memset(vh, 0, sizeof(int) * (N+1)); 
		vh[0] = N; 
		ans=0;
	    while (h[1] < N)
		{
				augc = INF;
				found = 0; 
				aug(1); 
		}
		printf("%d\n", ans); 
	}
	return 0;
}

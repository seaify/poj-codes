	#include <stdio.h>
	#include <string.h>
	#include <limits.h>
	#define INF INT_MAX
	struct adjLink
	{
	int c, v, nxt; 
	}adj[1000000]; 
	int ans, n, augc, found, adjN; 
	void add(int beg, int end, int c)
	{
	adj[adjN].v = end; 
	adj[adjN].c = c; 
	adj[adjN].nxt = adj[beg].nxt; 
	adj[beg].nxt = adjN++; 
	}
/*	void insert(int beg, int end, int c)
	{
	add(beg, end, c); 
	add(end, beg, 0); 
	}*/
	int h[20010], vh[20010]; 
	void aug(int cur)
	{
	int i, minh = n - 1, augco = augc; 
	if (cur == 1)
	{
	found = 1; 
	ans += augc; 
	return; 
	}
	for (i = adj[cur].nxt; i != -1; i = adj[i].nxt)
	if (adj[i].c > 0)
	{
	int v = adj[i].v; 
	if (h[v] + 1 == h[cur])
	{
		if(adj[i].c<augc)
	augc = adj[i].c; 
	aug(v); 
	if (h[0]>= n)
	    return; 
	if (found) 
	break; 
	augc = augco; 
	}
	if(minh<=h[v])
	   h[v]=minh;

	}
	if (!found)
	{
	vh[h[cur]]--; 
	if (vh[h[cur]] == 0)
	{
	h[0] = n; 
	return; 
	}
	h[cur] = minh + 1; 
	vh[h[cur]]++; 
	}
	else
	{
	adj[i].c -= augc; 
	}
	}
	int main()
	{ 
	int m, i; 
	scanf("%d%d", &n, &m); 
	for (i = 0; i < n + 2; i++) 
	adj[i].nxt = -1; 
	adjN = i + !((i & 1) ^ 1); 
	for (i = 0; i < n; i++) 
	{
	int a, b; 
	scanf("%d%d", &a, &b); 
	add(0, i + 2, a); 
	add(i + 2, 1, b); 
	}
	for (i = 0; i < m; i++) 
	{
	int beg, end, w; 
	scanf("%d%d%d", &beg, &end, &w); 
	add(beg + 1, end + 1, w); 
	add(end + 1, beg + 1, w); 
	}
	n += 2; 
	
	
	
	
	memset(vh, 0, sizeof(int) * n); 
	memset(h, 0, sizeof(int) * n); 
	vh[0] = n; 
	ans = 0; 
	while (h[0] < n)
	{
	found = 0; 
	augc = INF; 
	aug(0); 
	}
	printf("%d\n", ans); 
	scanf("%d", &n); 
	return 0; 
	}
	
	 
	

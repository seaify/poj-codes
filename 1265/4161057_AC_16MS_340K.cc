#include <stdio.h>
#include <stdlib.h>

typedef struct TPoint
{
	int x;
	int y;	
}TPoint;

typedef struct TPolygon
{
	TPoint p[1050];
	int n;
}TPolygon;

typedef struct TLine
{
	int a, b, c;
}TLine;

int polygonArea(TPolygon p)
{
    //已知多边形各顶点的坐标，求其面积
    int area, i, n;
    area = 0;
    n = p.n;
    for(i = 1;i <= n;i++){
        area += (p.p[i - 1].x * p.p[i % n].y - p.p[i % n].x * p.p[i - 1].y);
    }  
    return abs(area);   
}

TLine lineFromSegment(TPoint p1, TPoint p2)
{
    //线段所在直线,返回直线方程的三个系统 
    TLine tmp;
    tmp.a = p2.y - p1.y;
    tmp.b = p1.x - p2.x;
    tmp.c = p2.x * p1.y - p1.x * p2.y;
    return tmp;
}

void swap(TPoint &p1, TPoint &p2)
{
	TPoint p0;
	p0 = p1;
	p1 = p2;
	p2 = p0;
}

int Count(TPoint p1, TPoint p2)
{
	int i, num, y;
	TLine l1 = lineFromSegment(p1, p2);
	if(l1.b == 0) return abs(p1.y - p2.y) + 1;
	if(p1.x > p2.x) swap(p1, p2);
	num = 0;
	for(i = p1.x;i <= p2.x;i++){
		y = -l1.c - l1.a * i;
		if(y % l1.b == 0) num++;
	}
	return num;	
}

int main()
{
	int test, i, n, dx, dy, A2, d, sumc, t = 1;
	TPolygon p;
	scanf("%d", &test);
	while(test--){
		scanf("%d", &n);
		p.p[0].x = 0;
		p.p[0].y = 0;
		sumc = 0;
		for(i = 1;i <= n;i++){
			scanf("%d%d", &dx, &dy);
			p.p[i].x = p.p[i - 1].x + dx;
			p.p[i].y = p.p[i - 1].y + dy;
			sumc += Count(p.p[i - 1], p.p[i]);			
		}
		//p[n] = p[0]
		sumc = sumc - n;	
		p.n = n;
		A2 = polygonArea(p);
		printf("Scenario #%d:\n", t++);
		printf("%d %d %.1lf\n\n",(A2 - sumc) / 2 + 1, sumc, (double)A2 / 2);
	}
	return 0;
}

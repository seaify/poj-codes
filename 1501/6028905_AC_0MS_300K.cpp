#include<stdio.h>
#include<string.h>
const int kind=26;

int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
char map[1100][1100],str[1100];
int n,tot,flag,root;
int L,C,W,count,cx,cy,cz,total,ans[1100][5];

struct node
{
	int id;
	int next[kind];
};
node q[9000000];

void init()
{
	int i;
	++tot;
    for(i=0;i<kind;i++)
		q[tot].next[i]=0;
}

void insert()
{
	int i=0,index,p;
	p=1;
	while(str[i])
	{
		index=str[i]-'A';
		if(q[p].next[index])
			p=q[p].next[index];
		else
		{
			init();
			q[p].next[index]=tot;
			p=tot;

		}
		i++;
	}
	q[p].id=++count;
}

void find(int p,int x,int y)
{
	  int t;
      if(p==0)
		  return ;
	  if(q[p].id>0)
	  {
		  t=q[p].id;
		  ans[t][0]=cx;
		  ans[t][1]=cy;
		  ans[t][2]=x-dir[cz][0];
		  ans[t][3]=y-dir[cz][1];
		  q[p].id=0;
		  total++;
		 
	  }

	  if(x<0||x>=L||y<0||y>=C)         //important
		  return ;

	  find(q[p].next[map[x][y]-'A'],x+dir[cz][0],y+dir[cz][1]);

}

void solve()
{
    int i,j,k;   

	total=0;
	for(i=0;i<L;i++)
		for(j=0;j<C;j++)
			for(k=0;k<8;k++)
			{
					cx=i;
					cy=j;
					cz=k;
					find(1,cx,cy);
					if(total==W)
						return ;
				}
}

int main()
{

    int i;

	while(EOF!=scanf("%d",&L))
	{

		for(i=0;i<L;i++)
			scanf("%s",map+i);

		C=L;

		tot=0;
		count=0;
		W=0;
		
		init();

	    while(EOF!=scanf("%s",str))
		{
			if(str[0]=='0')
				break;
		    W++;
			insert();
			ans[W][0]=-1;
		}

        solve();

		for(i=1;i<=W;i++)
			if(ans[i][0]!=-1)
		    	printf("%d,%d %d,%d\n",ans[i][0]+1,ans[i][1]+1,ans[i][2]+1,ans[i][3]+1);
			else
				printf("Not found\n");


	}

	return 0;
}
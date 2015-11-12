#include<stdio.h>     
#include<string.h> 
#include<time.h>   
char a[362882][15],y[40],c[40];
int tag[362882],s[10],ans; 
char x[12]; 
int pre[362882],op[362882];


int LRotate(int op)
{
	int i,pos,tmp;
	char ch;

	for(i=1;i<=9;i++)
		if(x[i]=='0')
		{
			pos=i;
			break;
		}

	if(op==1)
	{		
		if(pos<4)
			return 1;
		tmp=pos-3;
	}
	else if(op==2)
	{		
		if(pos%3==0)
			return 1;
		tmp=pos+1;	
	}
	else if(op==3)
	{
		if(pos>=7)
			return 1;
		tmp=pos+3;
	}
	else 
	{
		if(pos%3==1)
			return 1;
		tmp=pos-1;		
	}

	ch=x[pos];
	x[pos]=x[tmp];
	x[tmp]=ch;

    return 0;
}

int find(char *z)//?????????????????? 
{ 
	int i,j,c,m;
	int b[12]; 
	memset(b,0,sizeof(b)); 
    for(i=1;i<9;i++) 
		for(j=i+1;j<=9;j++) 
			if(z[j-1]< z[i-1]) 
				b[i]++;    
			m=8;c=0; 
			for(i=1;i<=9;i++) 
				c+=b[i]*s[m--];        
			return c; 
} 

void dfs(int x)
{
     if(pre[x]==0)
		 return ;
	
	 if(op[x]==1)
		 printf("d");
	 else if(op[x]==2)
		 printf("l");
	 else if(op[x]==3)
		 printf("u");
	 else 
		 printf("r"); 
	 dfs(pre[x]);
}

void bfs()     
{     
	int i,head,tail,ttail,k,c,value; 

	head=0;
	tail=1;
	strcpy(a[0],"123456780"); 

	pre[find(a[0])]=0;
	
	while(head<tail)     
	{     
		
		ttail=tail;     
		for(k=head;k<tail;k++)        
		{ 
			value=find(a[k]);
			for(i=1;i<=4;i++)     
			{    
				strcpy(x+1,a[k]);     
				if(LRotate(i))
					continue;
				c=find(x+1); 

				if(pre[c]!=-1)
					continue;

				op[c]=i;
				pre[c]=value;   
			
				strcpy(a[ttail++],x+1);   

			}     
		} 
		head=tail;     
		tail=ttail;     
	}        
}     

int main()     
{ 
	int i,j,x; 

	for(i=2,s[1]=1;i<=9;i++)   
		s[i]=s[i-1]*i; 

	memset(pre,-1,sizeof(pre));
	bfs();

	while(gets(c+1))     
	{     
	    j=0;
	    for(i=1;c[i]&&j<=9;i++)
			if(c[i]!=' ')
			{
			  if(c[i]=='x')
				  c[i]='0';
			  y[++j]=c[i];
			}
		y[j+1]='\0';

		x=find(y+1);

		if(pre[x]!=-1)
			dfs(x);
		else
			printf("unsolvable");

		printf("\n");


	}     
	
	return 0;     
}     


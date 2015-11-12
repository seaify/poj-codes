#include<stdio.h>
#include<stack>
using namespace std;
int n;
int q[1100];
stack < int > p;

int main()
{
    int i,top,flag;
    while(EOF!=scanf("%d",&n)&&n)
    {
        while(1)
		{
			scanf("%d",&q[1]);
			
			if(q[1]==0)
				break;
			
			for(i=2;i<=n;i++)
				scanf("%d",&q[i]);
			
			while(!p.empty())
				p.pop();
			
			top=1;
		
			i=1;
			while(i<=n||!p.empty())
			{
				flag=0;
				if(i==q[top])
				{
					top++;
					i++;
					flag=1;
				}
				else if(!p.empty()&&p.top()==q[top])
				{
					top++;
					p.pop();
					flag=1;
					
				}
				else if(i<=n)
				{
					p.push(i);   
					i++;
				}

				if(i>n&&!flag)
					break;
				
			}

		
			if(top==n+1)
				printf("Yes\n");
			else
				printf("No\n\n");
		}
		
    }
    return 0;
}

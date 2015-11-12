#include<stdio.h>
#include<string.h>

int n;
char a[1000],b[1000];

int main()
{
    int i;
    while(1)
    {
        scanf("%s",a);
        if(a[0]=='E')
            break;
        getchar();
        gets(b);
        scanf("%s",a);
        n=strlen(b);
        for(i=0;i<n;i++)
            if(b[i]>='A'&&b[i]<='Z')
                 printf("%c",((b[i]-'A'-5+26)%26)+'A');
            else
                 printf("%c",b[i]);
        printf("\n");       
    }
    return 0;
}


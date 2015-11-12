#include<stdio.h>
#include<string.h>
int main()
{
	char a[27],s[100];
	int i;
	gets(a);
    gets(s);
	for(i=0;s[i]!='\0';i++)
		if(s[i]>='a'&&s[i]<='z')
			printf("%c",a[s[i]-'a']);
		else if(s[i]>='A'&&s[i]<='z')
			printf("%c",a[s[i]+32-'a']-32);
        else 
			printf("%c",s[i]);
		printf("\n");
		return 0;
}
		


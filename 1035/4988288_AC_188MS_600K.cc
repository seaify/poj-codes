#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char temp[20],last[20],ch;
bool tag[11000];
struct node
{
   char a[20];
   int index;
};
node edge[11000],ans[11000];
int cmp1(const void *a,const void *b)
{
     struct node *aa=(node *)a;
     struct node *bb=(node *)b;
     return strcmp(aa->a,bb->a);
}
int cmp2(const void *a,const void *b)
{
     struct node *aa=(node *)a;
     struct node *bb=(node *)b;
     return aa->index-bb->index;
}
int i,j,t,n,flag,len,top;//top为最终结果。。。 
int Bsearch(char temp[])
{
    int left=1,right=n,mid,q;
    while(left<=right)
    {
       mid=(left+right)/2;
       q=strcmp(temp,edge[mid].a);
       if(q==0)
       {
            if(tag[mid]==false)//判重。。。。 
            {
               tag[mid]=true;
               strcpy(ans[++top].a,temp);
               ans[top].index=edge[mid].index;
               return 1;
            }
            return 0;
       }
       else if(q<0)
            right=mid-1;
       else
            left=mid+1;          
    }
    return 0;
}
int main()
{
   memset(edge,0,sizeof(edge));
   for(i=1;;++i)
   {
     scanf("%s",temp);
     if(temp[0]=='#')
        break;
     strcpy(edge[i].a,temp);
     edge[i].index=i;
   }
   n=i-1;
   qsort(edge+1,n,sizeof(edge[1]),cmp1);
  // for(i=1;i<=n;++i)
   //  printf("%d ",edge[i].index);printf("\n");  
   while(EOF!=scanf("%s",temp))
   {
     if(temp[0]=='#')
         break; 
     memset(tag,false,sizeof(tag));
     flag=Bsearch(temp);
     if(flag)
     {
        printf("%s is correct\n",temp);
        continue;
     }  
     len=strlen(temp);top=0;strcpy(last,temp);
     for(i=0;i<=25;++i)//置换，top为最终结果的个数 
        for(j=0;j<len;++j)
        {
           ch=last[j];
           last[j]=i+'a';
           Bsearch(last);       
           last[j]=ch;
        }
     for(i=0;i<len;++i)//删除 
     {
         ch=temp[i];temp[i]='#';t=-1;
         memset(last,0,sizeof(last));
         for(j=0;j<len;++j)
            if(temp[j]!='#')
               last[++t]=temp[j];
         temp[i]=ch;
         Bsearch(last);
         temp[i]=ch;              
     } 
     for(i=0;i<=25;++i)
     {
         for(j=0;j<=len;++j)
         { 
              memset(last,0,sizeof(last));
              if(j>0) 
                 strncat(last,temp,j);
              last[j]=i+'a';
              if(j<len)
                 strncat(last,temp+j,len-j);
              Bsearch(last);
         }
     }
     printf("%s:",temp);
     if(top>0)
     {
       qsort(ans+1,top,sizeof(ans[1]),cmp2); 
       printf(" ");
       for(i=1;i<top;++i)
          printf("%s ",ans[i].a);
       printf("%s\n",ans[top].a);  
     }   
     else
       printf("\n");       
   }
   return 0;
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

bool isStan;
void print()
{
    if (isStan) printf("Stan wins\n");
    else printf("Ollie wins\n");
}

int main()
{
    int a,b,t;
    while (scanf("%d%d",&a,&b),a!=0 || b!=0)
    {
        if (a<b)
        { t=b; b=a; a=t;}
        isStan=1;
        while (1)
        {
            if (a/b>=2)
            {
                print();
                break;
            }
            t=a%b;
            a=b;
            b=t;
            if (b==0)
            {
                print();
                break;
            }
            isStan=1-isStan;
        }
    }
    return 0;
}

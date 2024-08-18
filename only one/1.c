#include<stdio.h>

extern int abc;
int main()
{
    int *a;
    int b=1;
    int c=2;
    a=&b;
    printf("我爱你 %d",abc);
    getchar();
}


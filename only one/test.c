#include<stdio.h>
int main()
{
    int z[100];
    scanf("%[0-9]",&z);
    printf("%zu\n",sizeof(z));

    printf("%d,%d,%d",z[0],z[1],z[2]);
}
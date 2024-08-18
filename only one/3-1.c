#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *arr;
    int capacity=5;
    arr=malloc(capacity* sizeof(char));
    int size=0;
    char ch;
    while((ch=getchar())!='\n')
    {
        if(size==capacity-1)
        {
            capacity=capacity *2;
            arr=realloc(arr,capacity * sizeof(char));
        }
        arr[size]=ch;
        size++;

    }
    arr[size]='\0';
    printf("%s",arr);
    int a[size-1];
    int sum=0;
    int flag=0;
    for(int i=0;i<size;i++)
    {
        if (arr[i]=='(')
        {
            a[i]=-1;
            sum=sum-1;
        }
        else{
            a[i]=1;
            sum=sum+1;
        }
        if(sum>0&&flag==0)
        {
            flag=i;
        }

    }
    if(sum!=0)
    {
        printf("\nfalse\n");
    }
    if(sum==0)
    {
        printf("\nTrue\n");
    }
    if(sum>0)
    {
        printf("failed point: %d",flag);
    }
    if(sum<0)
    {
        printf("failed ponit: %d",size-1);
    }
}
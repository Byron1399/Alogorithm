#include <stdio.h>
#include <stdlib.h>

void insert(int **arr,int p,int k,int * size)
{
    int temp;
    while((*size)<p)
    {   temp=*size;
        *size=(*size) * 2;
        arr=realloc(arr,(*size) * sizeof(int *));
        for(int i=temp;i<*size;i++)
        {
            arr[i]=NULL;
        }
    }
    arr[p]=malloc(sizeof(int));
    *(arr[p])=k;
}

int ** delete (int **arr,int p,int *size)
{   int temp=0;
    arr[p]=NULL;
    for(int i=0;i<*size;i++)
    {
        if(arr[i]!=NULL)
        {
            temp++;
        }
    }
    int **newarr;
    newarr=malloc(temp *sizeof(int*));
    int j=0;
    for(int i=0;i<*size;i++)
    {
        if(arr[i]!=NULL)
        {
            newarr[j]=arr[i];
            j++;
        }
    }
    *size=temp;
    return newarr;
    
}

int main()
{
    int **arr;
    int capacity=5;
    arr=malloc(capacity * sizeof(int *));
    for(int i=0;i<capacity;i++)
    {
        arr[i]=NULL;
    }
    int * size;
    size=&capacity;
    insert(arr,7,7,size);
    printf("插入完成\n");
    printf("%d\n",*(arr[7]));
    printf("%d\n",*size);
    arr=delete(arr,7,size);
    printf("%d\n",*size);
}
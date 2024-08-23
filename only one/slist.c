#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int duru(char * arr ,int sum,int size)
{
    char ch;
    while((ch=getchar())!='\n')
    {   
        if(size==sum-1)
        {
            sum=sum *2;
          char * newarr=realloc(arr,sum*sizeof(char));
          if(!newarr)
          {
            printf("扩展失败\n");
            return -1;
          }
          arr=newarr;
        }
        arr[size]=ch;
        size++;
    }
    arr[size]='\0';
    return size;
}
int main()
{
    char * arr0;
    arr0=malloc(5*sizeof(char));
    int sum=5;
    int size=0;
    int size0=duru(arr0,sum,size);
    char * arr1;
    arr1=malloc(5*sizeof(char));
    int size1=duru(arr1,sum,size);
    if(size1>size0)
    {
        printf("不存在");
    }
    for(int i=0;i<size0;i++)
    {
        printf("%c",arr0[i]);
    }
    printf("\n");
    for(int i=0;i<size1;i++)
    {
        printf("%c",arr1[i]);
    }
    printf("\n");
    int n=size0-size1+1;
    long int n_sum=0;

    typedef struct list 
       {
         int data;
         struct list * next;
       }list;
    list * arr2;
    arr2=malloc(n*sizeof(list));
    for(int i=0;i<n;i++)
    {
        arr2[i].data=-1;
        arr2[i].next=NULL;
    }
    for(int i=0;i<n;i++)
    {
       if(i==0)
       {
        for(int j=0;j<size1;j++)
        {
            n_sum+=pow(3,size1-1-j) * (char)arr0[i+j];
        }
       }
       else
       {
            n_sum=3*(n_sum-pow(3,size1-1)*(char)arr0[i-1])+(char)arr0[i+size1-1];
       }
       int x=n_sum%n;
       list * p=&arr2[x];
        while(p->data!=-1)
        {
            if(p->next==NULL)
            {
                list * p1=malloc(sizeof(list));
                p1->data=i;
                p1->next=NULL;
                p->next=p1;
                break;
            }
            else
            {
                p=p->next;
            }
        }
        if(p->data==-1)
        {
            p->data=i;
        }

    }
    long int size1_sum=0;
   
    for(int i=0;i<size1;i++)
    {  
        size1_sum+=pow(3,size1-1-i) * (char)arr1[i];
    }
      list * x1p=&arr2[size1_sum%n];
      int x1=arr2[size1_sum%n].data;
        int findsize=0;
        while(x1!=-1)
        {   int flag=1;
            int j=0;
            for(int i=x1;j<(size1-1);i++)
            {
                if(arr0[i]!=arr1[j])
                {
                    flag=-1;
                    break;
                }
                else
                {
                    j++;
                }
            }
            if(flag==1)
            {
                printf("找到了,%d\n",x1);
                findsize++;
            }
            if(x1p->next!=NULL)
            {
                x1p=x1p->next;
                x1=x1p->data;
            }
            else
            {
                break;
            }
        }
        printf("共找到%d个",findsize);
    
}
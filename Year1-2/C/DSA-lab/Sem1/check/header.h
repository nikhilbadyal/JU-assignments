#include<stdio.h>
#include<math.h>
int arr[20];
int get_size()
{
    int n;
    printf("How many members do you have,\n");
    scanf("%d",&n);
    return n;
}
int* create_set(int n)
{
    int *p;
    int countt=0;
    int ret_arr(int i ) {return arr[i];}
    int temp,j,i;
    printf("Enter elements one by one.\n");
    for(int i=0;i<n;i++)
    {
        returned:
        scanf("%d",&temp);
        for(j=0;j<n;j++)
        {
            if((ret_arr(j)) == temp){
                    printf("Element already exist.Enter again.\n");
                    goto returned;
            }
            else{
            countt =1;
            }
        }
        if(countt==1)
        {
           arr[i]=temp;
        }
    }
    return arr;
}

void show_data(int *arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d",*(arr+i));
    }
}

int* create_union()
{
    int i,k;
    static int arr[40];
    int *p;
    int n = get_size();
    p= create_set(n);
    int *q;
    int m = get_size();
    q= create_set(m);
    for(i=0;i<n;i++)
    {
        arr[i] = *(p+i);
    }
    k=i;
    for(i=0;i<m;i++)
    {
        arr[k] = *(q+i);
    }
    return arr;

}


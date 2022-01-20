#include<stdio.h>
struct array
{
    int arr[100],size;
};
void create_set(struct array *x)
{
    printf("How many members do you have,\n");
    scanf("%d",&x->size);
    int countt=0;
    int ret_arr(int i ) {return x->arr[i];}
    int temp,j,i;
    printf("Enter elements one by one.\n");
    for(int i=0;i<(x->size);i++)
    {
        returned:
     //   scanf("%d",&temp);
        for(j=0;j<(x->size);j++)
        {
            printf("%d\n",ret_arr(j));
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
           x->arr[i]=temp;
        }
    }
}

void show_data(struct array x)
{
    int i;
    for(i=0;i<(x.size);i++)
    {

        printf("%d",x.arr[i]);
        printf("\n");
    }
}

void create_union(struct array *u)
{
    int i,k;
    struct array x,y;
    create_set(&x);
    create_set(&y);
    for(i=0;i<(x.size);i++)
    {
        u->arr[i] = x.arr[i];
    }
    k=i;
    for(i=0;i<(y.size);i++)
    {
        u->arr[k+1] = y.arr[i];
    }
}


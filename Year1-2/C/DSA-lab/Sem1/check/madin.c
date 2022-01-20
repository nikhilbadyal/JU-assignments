#include<stdio.h>
#include"try.c"

int main()
{
 /*   struct array x ;
    create_set(&x);
    show_data(x);
    struct array y ;
    create_set(&y);
    show_data(y);*/
    struct array u;
    create_union(&u);
    show_data(u);

    return 0;
}

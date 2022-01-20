#include <stdio.h>
#include <math.h>
#include <stdlib.h>


static int rand_int(int n) {
    int limit = RAND_MAX - RAND_MAX % n;
    int rnd;

    do {
        rnd = rand();
    }
    while (rnd >= limit);
    return rnd % n;
}

void shuffle(int *array, int n) {
    int i, j, tmp;

    for (i = n - 1; i > 0; i--) {
        j = rand_int(i + 1);
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
   }
}
int main(void)
{

    int i,n;
    FILE *fp;
    fp=fopen("random_numbers.txt","w");
    printf("Enter how many numbers do you want : \n");
    int numbers[1000000];
    printf("Enter how many numbers do you want : \n");
    scanf("%d",&n);
    for (i = 0; i <n; i++)
        numbers[i]= i;
    shuffle(numbers,n);
    printf("\nArray after shuffling is: \n");
    for ( i = 0; i <n; i++)
    {
        printf("%d  %d\n",i+1,numbers[i]);
        fprintf(fp,"%d - %d\n",i+1,numbers[i]);
    }
    fclose(fp);
    return 0;

}

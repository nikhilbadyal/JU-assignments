#include <stdio.h>
#include "sparse.h"

int main(){
	int i,n;sparse p,s,m;
	while(1){
        printf("\n1.Initialisation\t2.Insert Elements\t3.DIsplay Elements\t4.Count non-zero elements\t5.Display Sparse Matrix\t6.Display transpose matrix\t7.Exit");
        printf("\nEnter your choice: \n");
        scanf("%d",&n);
		switch(n){
			case 1:
				init(&p);break;
			case 2:
				creat_array(&p);break;
			case 3:
				display(p);break;
			case 4:
				i = count(p);
				printf("Number of non-zero elements = %d\n",i);break;
			case 5:
				init(&s);
				creat_tuple(&s,p);
				display_tuple(s);break;
			case 6:
				init(&m);
				transpose(&m,s);
				display_tuple(m);break;
			case 7:
				exit(0);

		}
	}

return 0;

}

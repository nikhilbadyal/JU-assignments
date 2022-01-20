#include <stdio.h>
#include "poly.h"

int main(){
	struct poly p1,p2,p3,p4,p5;	
	init(&p1);
	init(&p2);
	init(&p3);
	init(&p4);
	init(&p5);
	append(&p1,1,4);
	append(&p1,2,3);
	append(&p1,2,2);
	append(&p1,2,1);

	display(p1);

	append(&p2,2,3);
	append(&p2,3,2);
	append(&p2,4,1);

	display(p2);

	p3 = add(p1,p2);
	display(p3);

	p4 = add(p1,p2);
	display(p4);

	p5 = mul(p1,p2);
	display(p5);

return 0;
}

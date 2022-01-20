#define MAX 30
struct term{
	int coeff;
	int exp;
};
struct poly{
	struct term t[30];
	int not;
};
void init(struct poly* p){
	int i;
	p->not = 0;
	for(i=0; i<MAX; i++){
		p->t[i].coeff = 0;
		p->t[i].exp = 0;
	}
}
void append(struct poly *p,int c,int e){
	p->t[p->not].coeff = c;
	p->t[p->not].exp = e;
	(p->not)++;
}
void display(struct poly p){
	int i,flag=0;
	for(i=0; i<p.not; i++){
		if(p.t[i].exp!=0){
			printf("%dx^%d ",p.t[i].coeff,p.t[i].exp);
			if(i!=p.not-1) printf("+");
		else 
			{
				printf("+ %d",p.t[i].coeff);
				flag = 1;
			}
	}
	if(!flag)
		printf("\b\b\b");
	printf("\n\n");
}
struct poly add(POLY p1,POLY p2,int m,int n)
{
	
	POLY sum;
	int i=0,j=0,x=0;
	while(i<p1.no_t && j<p2.no_t)
	{
		if(p1.term[i].exp == p2.term[j].exp)
		{
			sum.term[x].exp=p1.term[i].exp;
			sum.term[x].coef=p1.term[i].coef+p2.term[j].coef;
			i++;
			j++;
			x++;
		}
		else if(p1[i].exp > p2.term[j].exp)
		{
			sum.term[x].exp=p1.term[i].exp;
			sum.term[x].coef=p1.term[i].coef;
			i++;
			x++;
		}
		else
		{
			sum.term[x].exp=p2.term[j].exp;
			sum.term[x].coef=p2.term[j].coef;
			j++;
			x++;
		}
	}
	while(i<m)
	{
		sum.term[x].exp=p1.term[i].exp;
		sum.term[x].coef=p1.term[i].coef;
		i++;
		x++;
	}
	while(j<n)
	{
		sum.term[x].exp=p2.term[j].exp;
		sum.term[x].coef=p1.term[j].coef;
		j++;
		x++;
	}

	
	return sum;

}struct poly sub(struct poly p1,struct poly p2){
	struct poly p3;
	init(&p3);
	int i,j,n;
	if(p1.not>p2.not)
		n = p1.not;
	else
		n = p2.not;
	for(i=0,j=0; i<n; p3.not++){
		if(p1.t[i].coeff == 0 && p2.t[j].coeff == 0)
			break;
		if(p1.t[i].exp >= p2.t[j].exp){
			if(p1.t[i].exp == p2.t[j].exp){
				p3.t[p3.not].coeff = p1.t[i].coeff - p2.t[j].coeff;
				p3.t[p3.not].exp = p1.t[i].exp;
				i++;j++;
			}
			else{
				p3.t[p3.not].coeff = p1.t[i].coeff;
				p3.t[p3.not].exp = p1.t[i].exp;
				i++;
			}	
		}
		else{
			p3.t[p3.not].coeff = p2.t[j].coeff;
			p3.t[p3.not].exp = p2.t[j].exp;
			j++;
		}
	}

return p3;
}
struct poly mul(struct poly p1, struct poly p2){
	int coeff,exp;
	struct poly temp,p4;
	init(&p4);init(&temp);
	if(p1.not !=0 && p2.not !=0){
		int i,j;
		for(i=0 ;i<p1.not; i++){
			struct poly p; init(&p);
			for(j=0; j<p2.not; j++){
				coeff = p1.t[i].coeff*p2.t[j].coeff;
				exp = p1.t[i].exp+p2.t[j].exp; 
				append(&p,coeff,exp);
			}
			if(i!=0) {p4 = add(p,temp); temp = p4;}
			else temp = p;
		}
	}
return p4;
}

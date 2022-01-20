%{
/* Definition section */
#include<stdio.h>
%}

%token AFTR MORN

/* Rule Section */
%%
stm1: MORN {
	char name[10]; 
	printf("Enter your name");
	scanf("%s",name);}
	printf("Good morning %s",name);
	};
stm2: AFTER {
	char name[10]; 
	printf("Enter your name");
	scanf("%s",name);}
	printf("Good Afternoon %s",name);
	};

%%

void main()
{
	yyin = fopen("input.txt", "r");
	yyparse();
}
void yyerror()
{
printf("Invalid data");
}

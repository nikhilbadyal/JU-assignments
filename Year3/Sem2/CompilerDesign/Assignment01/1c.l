%{
        	int count=0;
%}
start     	^[aeiouAEIOU]
space 		[ ]
vowel 		[aeiouAEIOU]
%%
{start} 	{count++;}
{space}{vowel}+ {count++;}
\n 			;
. 			;
%%
int yywrap(){ return 1; }
int main() {
	yyin = fopen("input3.txt", "r");
	yylex();
	printf("Number of words starting with a vowel are: %d\n",count);
}
